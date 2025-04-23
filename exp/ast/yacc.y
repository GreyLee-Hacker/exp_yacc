%{
#define YYDEBUG 1

#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include "ast.h"

// 声明全局根变量
std::unique_ptr<BaseAST> root;

int yylex();
void yyerror(const char *s);
extern char* yytext;

%}

// 定义语义值的可能类型
%union {
    BaseAST* ast_ptr;  // 用于AST节点指针
    int int_val;       // 用于整数值
    char* str_val;     // 用于字符串和标识符名称
}

// 定义token
%token MAIN CONST INT BREAK CONTINUE IF ELSE VOID
%token WHILE GETINT PRINTF RETURN
%token PLUS MINUS TIMES DIVIDE
%token LSS LEQ GRE GEQ EQL NEQ AND OR
%token <str_val> IDENT STR_CONST
%token <int_val> INT_CONST

// 定义非终结符的类型
%type <ast_ptr> CompUnit
%type <ast_ptr> Decl ConstDecl VarDecl
%type <ast_ptr> BType
%type <ast_ptr> FuncDef
%type <ast_ptr> MainFuncDef
%type <ast_ptr> Block BlockItems BlockItem
%type <ast_ptr> Stmt Assignment Number
%type <ast_ptr> ConstDefList ConstDef ArrayDims ConstInitVal ConstInitValList ConstExp
%type <ast_ptr> VarDefList VarDef InitVal InitValList
%type <ast_ptr> FuncFParams FuncFParam
%type <ast_ptr> PrintfItems
%type <ast_ptr> Exp Cond
%type <ast_ptr> LVal LValArrayIndices
%type <ast_ptr> PrimaryExp
%type <ast_ptr> UnaryExp UnaryOp FuncRParams
%type <ast_ptr> MulExp AddExp RelExp EqExp LAndExp LOrExp

%left OR
%left AND
%left LSS LEQ GRE GEQ EQL NEQ
%left PLUS MINUS
%left TIMES DIVIDE '%'
%right '!'
%left '(' ')' '[' ']'

%start CompUnit

%%

// 语法开始符号
CompUnit
    : Decl CompUnit {
        auto ast = dynamic_cast<CompUnitAST*>($2);
        if (!ast) {
            ast = new CompUnitAST(); // Should not happen if root is handled correctly
            root.reset(ast);
        }
        if ($1) {
            // Prepend declaration to maintain order similar to original linked list approach
            ast->declarations.insert(ast->declarations.begin(), std::unique_ptr<BaseAST>(static_cast<BaseAST*>($1)));
        }
        $$ = ast;
    }
    | FuncDef CompUnit {
        auto ast = dynamic_cast<CompUnitAST*>($2);
        if (!ast) {
            ast = new CompUnitAST(); // Should not happen if root is handled correctly
            root.reset(ast);
        }
        if ($1) {
            // Prepend function definition
            ast->function_definitions.insert(ast->function_definitions.begin(), std::unique_ptr<BaseAST>(static_cast<BaseAST*>($1)));
        }
        $$ = ast;
    }
    | MainFuncDef {
        auto ast = std::make_unique<CompUnitAST>();
        ast->main_func_def.reset(static_cast<BaseAST*>($1));
        root = std::move(ast); // Set global root
        $$ = root.get(); // Return raw pointer for bison stack
    }
    | Decl {
        auto ast = std::make_unique<CompUnitAST>();
        if ($1) {
            ast->declarations.emplace_back(static_cast<BaseAST*>($1));
        }
        root = std::move(ast);
        $$ = root.get();
    }
    | FuncDef {
        auto ast = std::make_unique<CompUnitAST>();
        if ($1) {
            ast->function_definitions.emplace_back(static_cast<BaseAST*>($1));
        }
        root = std::move(ast);
        $$ = root.get();
    }
    ;

// ... rest of the file ...

Decl : 
    ConstDecl ';' {
        auto ast = std::make_unique<DeclAST>();
        ast->decl.reset(static_cast<BaseAST*>($1));
        ast->kind = DeclAST::DeclKind::CONST_DECL;
        $$ = ast.release();
    } | VarDecl ';' {
        auto ast = std::make_unique<DeclAST>();
        ast->decl.reset(static_cast<BaseAST*>($1));
        ast->kind = DeclAST::DeclKind::VAR_DECL;
        $$ = ast.release();
    }
    ;

// ConstDecl -> 'const' BType ConstDef {',' ConstDef} ';'
ConstDecl :
    CONST BType IDENT '=' Number {
        auto ast = std::make_unique<ConstDeclAST>();
        ast->type = TYPE_INT;  // 假设默认为INT类型
        
        // 使用$3而不是yytext
        ast->ident = std::string($3);  
        
        // 获取Number节点的值
        auto number = dynamic_cast<NumberAST*>($5);
        if (number) {
            ast->value = number->value;
        }
        
        // 释放字符串
        free($3);
        
        $$ = ast.release();
    } | CONST BType ConstDef {
        auto ast = std::make_unique<ConstDeclAST>();
        if ($2) {
            ast->type = TYPE_INT; // 假设默认为INT类型
        }
        ast->const_def.reset(static_cast<BaseAST*>($3));
        $$ = ast.release();
    } | CONST BType ConstDef ',' ConstDefList {
        auto ast = std::make_unique<ConstDeclAST>();
        if ($2) {
            ast->type = TYPE_INT; // 假设默认为INT类型
        }
        
        auto const_def_list = std::make_unique<ConstDefListAST>();
        const_def_list->const_defs.emplace_back(static_cast<BaseAST*>($3));
        
        auto def_list = dynamic_cast<ConstDefListAST*>($5);
        if (def_list) {
            for (auto& def : def_list->const_defs) {
                const_def_list->const_defs.emplace_back(std::move(def));
            }
        }
        
        ast->const_def_list.reset(const_def_list.release());
        $$ = ast.release();
    }
    ;

ConstDefList :
    ConstDef {
        auto ast = std::make_unique<ConstDefListAST>();
        ast->const_defs.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | ConstDef ',' ConstDefList {
        auto ast = dynamic_cast<ConstDefListAST*>($3);
        if (!ast) {
            ast = new ConstDefListAST();
        }
        ast->const_defs.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    ;

// ConstDef -> Ident {'[' ConstExp ']'} '=' ConstInitVal
ConstDef :
    IDENT '=' ConstInitVal {
        auto ast = std::make_unique<ConstDefAST>();
        ast->ident = std::string($1);
        ast->const_init_val.reset(static_cast<BaseAST*>($3));
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    } | IDENT ArrayDims '=' ConstInitVal {
        auto ast = std::make_unique<ConstDefAST>();
        ast->ident = std::string($1);
        ast->array_dims.reset(static_cast<BaseAST*>($2));
        ast->const_init_val.reset(static_cast<BaseAST*>($4));
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    }
    ;

// BType -> 'int'
BType : 
    INT {
        $$ = nullptr;  // BType不需要生成AST节点
    } |
    VOID {
        $$ = nullptr;  // BType不需要生成AST节点
    }
    ;

// VarDecl -> BType VarDef {',' VarDef} ';'
VarDecl :
    BType IDENT {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT;
        ast->ident = std::string($2);
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    } | BType IDENT '=' InitVal {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT;
        ast->ident = std::string($2);
        
        // 创建一个VarDefAST并设置初始化值
        auto var_def = std::make_unique<VarDefAST>();
        var_def->ident = std::string($2);
        var_def->init_val.reset(static_cast<BaseAST*>($4));
        var_def->has_init = true;
        
        ast->var_def.reset(var_def.release());
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    } | BType VarDef {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT; // 假设类型为INT
        ast->var_def.reset(static_cast<BaseAST*>($2));
        $$ = ast.release();
    } | BType VarDef ',' VarDefList {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT; // 假设类型为INT
        
        auto var_def_list = std::make_unique<VarDefListAST>();
        var_def_list->var_defs.emplace_back(static_cast<BaseAST*>($2));
        
        auto def_list = dynamic_cast<VarDefListAST*>($4);
        if (def_list) {
            for (auto& def : def_list->var_defs) {
                var_def_list->var_defs.emplace_back(std::move(def));
            }
        }
        
        ast->var_def_list.reset(var_def_list.release());
        $$ = ast.release();
    }
    ;

VarDefList :
    VarDef {
        auto ast = std::make_unique<VarDefListAST>();
        ast->var_defs.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | VarDef ',' VarDefList {
        auto ast = dynamic_cast<VarDefListAST*>($3);
        if (!ast) {
            ast = new VarDefListAST();
        }
        ast->var_defs.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    ;

// VarDef -> Ident {'[' ConstExp ']'} | Ident {'[' ConstExp ']'} '=' InitVal
VarDef :
    IDENT {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string($1);
        ast->has_init = false;
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    } | IDENT ArrayDims {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string($1);
        ast->array_dims.reset(static_cast<BaseAST*>($2));
        ast->has_init = false;
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    } | IDENT '=' InitVal {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string($1);
        ast->init_val.reset(static_cast<BaseAST*>($3));
        ast->has_init = true;
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    } | IDENT ArrayDims '=' InitVal {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string($1);
        ast->array_dims.reset(static_cast<BaseAST*>($2));
        ast->init_val.reset(static_cast<BaseAST*>($4));
        ast->has_init = true;
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    }
    ;

// InitVal -> Exp | '{' [InitVal {',' InitVal}] '}'
InitVal :
    Exp {
        auto ast = std::make_unique<InitValAST>();
        ast->init_type = InitValAST::InitType::EXPR;
        ast->expr.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | '{' '}' {
        auto ast = std::make_unique<InitValAST>();
        ast->init_type = InitValAST::InitType::LIST;
        ast->list.reset(new InitValListAST()); // 空列表
        $$ = ast.release();
    } | '{' InitValList '}' {
        auto ast = std::make_unique<InitValAST>();
        ast->init_type = InitValAST::InitType::LIST;
        ast->list.reset(static_cast<BaseAST*>($2));
        $$ = ast.release();
    }
    ;

InitValList :
    InitVal {
        auto ast = std::make_unique<InitValListAST>();
        ast->init_vals.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | InitVal ',' InitValList {
        auto ast = dynamic_cast<InitValListAST*>($3);
        if (!ast) {
            ast = new InitValListAST();
        }
        ast->init_vals.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    ;

MainFuncDef :
    INT MAIN '(' ')' Block {
        auto ast = std::make_unique<MainFuncDefAST>();
        ast->block.reset(static_cast<BaseAST*>($5));
        $$ = ast.release();
    }
    ;

Block :
    '{' BlockItems '}' {
        $$ = $2;  // 直接使用BlockItems生成的BlockAST
    } | '{' '}' {
        auto ast = std::make_unique<BlockAST>();  // 创建空块
        $$ = ast.release();
    }
    ;

BlockItems :
    BlockItems BlockItem {
        auto block = dynamic_cast<BlockAST*>($1);
        if (block && $2) {
            block->items.emplace_back(static_cast<BaseAST*>($2));
        }
        $$ = block;
    } | BlockItem {
        auto ast = std::make_unique<BlockAST>();
        if ($1) {
            ast->items.emplace_back(static_cast<BaseAST*>($1));
        }
        $$ = ast.release();
    }
    ;

BlockItem :
    Decl {
        $$ = $1;
    } | Stmt {
        $$ = $1;
    }
    ;

Stmt :
    Assignment ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::ASSIGNMENT;
        ast->content.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    | IDENT '=' Exp ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::ASSIGN;
        
        auto assign = std::make_unique<AssignmentAST>();
        auto lval = std::make_unique<LValAST>();
        lval->ident = std::string($1);
        assign->lval.reset(lval.release());
        assign->exp.reset(static_cast<BaseAST*>($3));
        ast->content = std::move(assign);
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    }
    | Block {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::BLOCK;
        ast->content.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    | RETURN IDENT ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::RETURN;
        ast->return_ident = std::string($2);
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    }
    | LVal '=' Exp ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::ASSIGN;
        
        auto assign = std::make_unique<AssignmentAST>();
        assign->lval.reset(static_cast<BaseAST*>($1));
        assign->exp.reset(static_cast<BaseAST*>($3));
        ast->content = std::move(assign);
        
        $$ = ast.release();
    }
    | ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::EMPTY;
        $$ = ast.release();
    }
    | Exp ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::EXPRESSION;
        ast->content.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    | IF '(' Cond ')' Stmt {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::IF;
        ast->cond.reset(static_cast<BaseAST*>($3));
        ast->if_stmt.reset(static_cast<BaseAST*>($5));
        $$ = ast.release();
    }
    | IF '(' Cond ')' Stmt ELSE Stmt {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::IF_ELSE;
        ast->cond.reset(static_cast<BaseAST*>($3));
        ast->if_stmt.reset(static_cast<BaseAST*>($5));
        ast->else_stmt.reset(static_cast<BaseAST*>($7));
        $$ = ast.release();
    }
    | WHILE '(' Cond ')' Stmt {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::WHILE;
        ast->cond.reset(static_cast<BaseAST*>($3));
        ast->while_stmt.reset(static_cast<BaseAST*>($5));
        $$ = ast.release();
    }
    | BREAK ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::BREAK;
        $$ = ast.release();
    }
    | CONTINUE ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::CONTINUE;
        $$ = ast.release();
    }
    | RETURN ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::RETURN_VOID;
        $$ = ast.release();
    }
    | RETURN Exp ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::RETURN_EXP;
        ast->content.reset(static_cast<BaseAST*>($2));
        $$ = ast.release();
    }
    | LVal '=' GETINT '(' ')' ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::GETINT;
        ast->content.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    | PRINTF '(' STR_CONST PrintfItems ')' ';' {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::PRINTF;
        
        auto printf_items = std::make_unique<PrintfItemsAST>();
        printf_items->format_string = std::string($3);
        
        // 如果有其他参数
        auto items = dynamic_cast<PrintfItemsAST*>($4);
        if (items) {
            printf_items->expressions = std::move(items->expressions);
        }
        
        // 释放字符串
        free($3);
        
        ast->content.reset(printf_items.release());
        $$ = ast.release();
    }
    ;

Assignment :
    IDENT '=' GETINT '(' ')' {
        auto ast = std::make_unique<AssignmentAST>();
        ast->ident = std::string($1);
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    }
    ;
    
Number :
    INT_CONST {
        auto ast = std::make_unique<NumberAST>();
        ast->value = $1;
        $$ = ast.release();
    }
    ;

ArrayDims :
    '[' ConstExp ']' {
        auto ast = std::make_unique<ArrayDimsAST>();
        ast->dims.emplace_back(static_cast<BaseAST*>($2));
        $$ = ast.release();
    } | '[' ConstExp ']' ArrayDims {
        auto ast = dynamic_cast<ArrayDimsAST*>($4);
        if (!ast) {
            ast = new ArrayDimsAST();
        }
        ast->dims.emplace_back(static_cast<BaseAST*>($2));
        $$ = ast;
    }
    ;

// ConstInitVal -> ConstExp | '{' [ConstInitVal {',' ConstInitVal}] '}'
ConstInitVal :
    ConstExp {
        auto ast = std::make_unique<ConstInitValAST>();
        ast->init_type = ConstInitValAST::InitType::EXPR;
        ast->expr.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | '{' '}' {
        auto ast = std::make_unique<ConstInitValAST>();
        ast->init_type = ConstInitValAST::InitType::LIST;
        ast->list.reset(new ConstInitValListAST()); // 空列表
        $$ = ast.release();
    } | '{' ConstInitValList '}' {
        auto ast = std::make_unique<ConstInitValAST>();
        ast->init_type = ConstInitValAST::InitType::LIST;
        ast->list.reset(static_cast<BaseAST*>($2));
        $$ = ast.release();
    }
    ;

ConstInitValList :
    ConstInitVal {
        auto ast = std::make_unique<ConstInitValListAST>();
        ast->init_vals.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | ConstInitVal ',' ConstInitValList {
        auto ast = dynamic_cast<ConstInitValListAST*>($3);
        if (!ast) {
            ast = new ConstInitValListAST();
        }
        ast->init_vals.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    ;

// ConstExp -> AddExp
ConstExp :
    AddExp {
        auto ast = std::make_unique<ConstExpAST>();
        ast->exp.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    ;

// FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
FuncDef :
    BType IDENT '(' ')' Block {
        auto ast = std::make_unique<FuncDefAST>();
        ast->return_type = TYPE_INT; // 假设返回类型为INT
        ast->ident = std::string($2);
        ast->block.reset(static_cast<BaseAST*>($5));
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    } | BType IDENT '(' FuncFParams ')' Block {
        auto ast = std::make_unique<FuncDefAST>();
        ast->return_type = TYPE_INT; // 假设返回类型为INT
        ast->ident = std::string($2);
        ast->func_f_params.reset(static_cast<BaseAST*>($4));
        ast->block.reset(static_cast<BaseAST*>($6));
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    }
    ;

// FuncFParams -> FuncFParam {',' FuncFParam}
FuncFParams :
    FuncFParam {
        auto ast = std::make_unique<FuncFParamsAST>();
        ast->params.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | FuncFParam ',' FuncFParams {
        auto ast = dynamic_cast<FuncFParamsAST*>($3);
        if (!ast) {
            ast = new FuncFParamsAST();
        }
        ast->params.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    ;

// FuncFParam -> BType Ident ['[' ']' {'[' ConstExp ']'}]
FuncFParam :
    BType IDENT {
        auto ast = std::make_unique<FuncFParamAST>();
        ast->param_type = TYPE_INT; // 假设类型为INT
        ast->ident = std::string($2);
        ast->is_array = false;
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    } | BType IDENT '[' ']' {
        auto ast = std::make_unique<FuncFParamAST>();
        ast->param_type = TYPE_INT; // 假设类型为INT
        ast->ident = std::string($2);
        ast->is_array = true;
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    } | BType IDENT '[' ']' ArrayDims {
        auto ast = std::make_unique<FuncFParamAST>();
        ast->param_type = TYPE_INT; // 假设类型为INT
        ast->ident = std::string($2);
        ast->is_array = true;
        ast->array_dims.reset(static_cast<BaseAST*>($5));
        
        // 释放字符串
        free($2);
        
        $$ = ast.release();
    }
    ;

PrintfItems :
    /* empty */ {
        auto ast = std::make_unique<PrintfItemsAST>();
        $$ = ast.release();
    } | ',' Exp PrintfItems {
        auto ast = dynamic_cast<PrintfItemsAST*>($3);
        if (!ast) {
            ast = new PrintfItemsAST();
        }
        
        // 使用emplace_back添加表达式
        ast->expressions.emplace_back(static_cast<BaseAST*>($2));
        $$ = ast;
    }
    ;

// Exp -> AddExp
Exp :
    AddExp {
        auto ast = std::make_unique<ExpAST>();
        ast->expr.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    ;

// Cond -> LOrExp
Cond :
    LOrExp {
        auto ast = std::make_unique<CondAST>();
        ast->expr.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    ;

// LVal -> Ident {'[' Exp ']'}
LVal :
    IDENT {
        auto ast = std::make_unique<LValAST>();
        ast->ident = std::string($1);
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    } | IDENT LValArrayIndices {
        auto ast = std::make_unique<LValAST>();
        ast->ident = std::string($1);
        ast->array_indices.reset(static_cast<BaseAST*>($2));
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    }
    ;

LValArrayIndices :
    '[' Exp ']' {
        auto ast = std::make_unique<LValArrayIndicesAST>();
        ast->indices.emplace_back(static_cast<BaseAST*>($2));
        $$ = ast.release();
    } | '[' Exp ']' LValArrayIndices {
        auto ast = dynamic_cast<LValArrayIndicesAST*>($4);
        if (!ast) {
            ast = new LValArrayIndicesAST();
        }
        ast->indices.emplace_back(static_cast<BaseAST*>($2));
        $$ = ast;
    }
    ;

// PrimaryExp -> '(' Exp ')' | LVal | Number
PrimaryExp :
    '(' Exp ')' {
        auto ast = std::make_unique<PrimaryExpAST>();
        ast->type = PrimaryExpAST::PrimaryType::EXP;
        ast->exp.reset(static_cast<BaseAST*>($2));
        $$ = ast.release();
    } | LVal {
        auto ast = std::make_unique<PrimaryExpAST>();
        ast->type = PrimaryExpAST::PrimaryType::LVAL;
        ast->lval.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | Number {
        auto ast = std::make_unique<PrimaryExpAST>();
        ast->type = PrimaryExpAST::PrimaryType::NUMBER;
        ast->number.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    }
    ;

// UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
UnaryExp :
    PrimaryExp {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::PRIMARY;
        ast->primary_exp.reset(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | IDENT '(' ')' {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::FUNC_CALL;
        ast->func_name = std::string($1);
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    } | IDENT '(' FuncRParams ')' {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::FUNC_CALL;
        ast->func_name = std::string($1);
        ast->func_r_params.reset(static_cast<BaseAST*>($3));
        
        // 释放字符串
        free($1);
        
        $$ = ast.release();
    } | UnaryOp UnaryExp {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::UNARY;
        ast->unary_op.reset(static_cast<BaseAST*>($1));
        ast->unary_exp.reset(static_cast<BaseAST*>($2));
        $$ = ast.release();
    }
    ;

// UnaryOp -> '+' | '-' | '!'
UnaryOp :
    PLUS {
        auto ast = std::make_unique<UnaryOpAST>();
        ast->op = UnaryOpAST::OpType::PLUS;
        $$ = ast.release();
    } | MINUS {
        auto ast = std::make_unique<UnaryOpAST>();
        ast->op = UnaryOpAST::OpType::MINUS;
        $$ = ast.release();
    } | '!' {
        auto ast = std::make_unique<UnaryOpAST>();
        ast->op = UnaryOpAST::OpType::NOT;
        $$ = ast.release();
    }
    ;

// FuncRParams -> Exp {',' Exp}
FuncRParams :
    Exp {
        auto ast = std::make_unique<FuncRParamsAST>();
        ast->params.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast.release();
    } | Exp ',' FuncRParams {
        auto ast = dynamic_cast<FuncRParamsAST*>($3);
        if (!ast) {
            ast = new FuncRParamsAST();
        }
        ast->params.emplace_back(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    ;

// MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
MulExp :
    UnaryExp {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->op = MulExpAST::OpType::NONE;
        $$ = ast.release();
    } | MulExp TIMES UnaryExp {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = MulExpAST::OpType::MUL;
        $$ = ast.release();
    } | MulExp DIVIDE UnaryExp {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = MulExpAST::OpType::DIV;
        $$ = ast.release();
    } | MulExp '%' UnaryExp {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = MulExpAST::OpType::MOD;
        $$ = ast.release();
    }
    ;

// AddExp -> MulExp | AddExp ('+' | '-') MulExp
AddExp :
    MulExp {
        auto ast = std::make_unique<AddExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->op = AddExpAST::OpType::NONE;
        $$ = ast.release();
    } | AddExp PLUS MulExp {
        auto ast = std::make_unique<AddExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = AddExpAST::OpType::ADD;
        $$ = ast.release();
    } | AddExp MINUS MulExp {
        auto ast = std::make_unique<AddExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = AddExpAST::OpType::SUB;
        $$ = ast.release();
    }
    ;

// RelExp -> AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
RelExp :
    AddExp {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->op = RelExpAST::OpType::NONE;
        $$ = ast.release();
    } | RelExp LSS AddExp {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = RelExpAST::OpType::LESS;
        $$ = ast.release();
    } | RelExp GRE AddExp {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = RelExpAST::OpType::GREATER;
        $$ = ast.release();
    } | RelExp LEQ AddExp {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = RelExpAST::OpType::LESS_EQ;
        $$ = ast.release();
    } | RelExp GEQ AddExp {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = RelExpAST::OpType::GREATER_EQ;
        $$ = ast.release();
    }
    ;

// EqExp -> RelExp | EqExp ('==' | '!=') RelExp
EqExp :
    RelExp {
        auto ast = std::make_unique<EqExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->op = EqExpAST::OpType::NONE;
        $$ = ast.release();
    } | EqExp EQL RelExp {
        auto ast = std::make_unique<EqExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = EqExpAST::OpType::EQ;
        $$ = ast.release();
    } | EqExp NEQ RelExp {
        auto ast = std::make_unique<EqExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = EqExpAST::OpType::NEQ;
        $$ = ast.release();
    }
    ;

// LAndExp -> EqExp | LAndExp '&&' EqExp
LAndExp :
    EqExp {
        auto ast = std::make_unique<LAndExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->op = LAndExpAST::OpType::NONE;
        $$ = ast.release();
    } | LAndExp AND EqExp {
        auto ast = std::make_unique<LAndExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = LAndExpAST::OpType::AND;
        $$ = ast.release();
    }
    ;

// LOrExp -> LAndExp | LOrExp '||' LAndExp
LOrExp :
    LAndExp {
        auto ast = std::make_unique<LOrExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->op = LOrExpAST::OpType::NONE;
        $$ = ast.release();
    } | LOrExp OR LAndExp {
        auto ast = std::make_unique<LOrExpAST>();
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        ast->op = LOrExpAST::OpType::OR;
        $$ = ast.release();
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}