%{
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);

%}

%token MAIN CONST INT BREAK CONTINUE IF ELSE VOID
%token WHILE GETINT PRINTF RETURN 
%token IDENT INT_CONST STR_CONST
%token PLUS MINUS TIMES DIVIDE
%token LSS LEQ GRE GEQ EQL NEQ AND OR

%left OR
%left AND
%left LSS LEQ GRE GEQ EQL NEQ
%left PLUS MINUS
%left TIMES DIVIDE '%'
%right '!'
%left '(' ')' '[' ']'

%start CompUnit
%%

// CompUnit -> {Decl} {FuncDef} MainFuncDef
CompUnit
    : Decl MainFuncDef {
        printf("<CompUnit>\n");
    } | FuncDef MainFuncDef {
        printf("<CompUnit>\n");
    } | MainFuncDef {
        printf("<CompUnit>\n");
    } | Decl CompUnit {

    } | FuncDef CompUnit {

    }
    ;

Decl : 
    ConstDecl ';' {
        
    } | VarDecl ';' {
        
    }
    ;

// ConstDecl -> 'const' BType ConstDef {',' ConstDef} ';'
ConstDecl :
    CONST BType ConstDef {
        printf("<ConstDecl>\n");
    } | CONST BType ConstDef ',' ConstDefList {
        printf("<ConstDecl>\n");
    }
    ;

ConstDefList :
    ConstDef {
        
    } | ConstDef ',' ConstDefList {
        
    }
    ;

// ConstDef -> Ident {'[' ConstExp ']'} '=' ConstInitVal
ConstDef :
    IDENT '=' ConstInitVal {
        
    } | IDENT ArrayDims '=' ConstInitVal {
        
    }
    ;

ArrayDims :
    '[' ConstExp ']' {
        
    } | '[' ConstExp ']' ArrayDims {
        
    }
    ;

// ConstInitVal -> ConstExp | '{' [ConstInitVal {',' ConstInitVal}] '}'
ConstInitVal :
    ConstExp {
        
    } | '{' '}' {
        
    } | '{' ConstInitValList '}' {
        
    }
    ;

ConstInitValList :
    ConstInitVal {
        
    } | ConstInitVal ',' ConstInitValList {
        
    }
    ;

// ConstExp -> AddExp
ConstExp :
    AddExp {
        
    }
    ;

// BType -> 'int' | 'void'
BType : 
    INT { }
  | VOID { }
  ;

// VarDecl -> BType VarDef {',' VarDef} ';'
VarDecl :
    BType VarDef {
        printf("<VarDecl>\n");
    } | BType VarDef ',' VarDefList {
        printf("<VarDecl>\n");
    }
    ;

VarDefList :
    VarDef {
        
    } | VarDef ',' VarDefList {
        
    }
    ;

// VarDef -> Ident {'[' ConstExp ']'} | Ident {'[' ConstExp ']'} '=' InitVal
VarDef :
    IDENT {
        
    } | IDENT ArrayDims {
        
    } | IDENT '=' InitVal {
        
    } | IDENT ArrayDims '=' InitVal {
        
    }
    ;

// InitVal -> Exp | '{' [InitVal {',' InitVal}] '}'
InitVal :
    Exp {
        
    } | '{' '}' {
        
    } | '{' InitValList '}' {
        
    }
    ;

InitValList :
    InitVal {
        
    } | InitVal ',' InitValList {
        
    }
    ;

// FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
FuncDef :
    BType IDENT '(' ')' Block {
        printf("<FuncDef>\n");
    } | BType IDENT '(' FuncFParams ')' Block {
        printf("<FuncDef>\n");
    }
    ;

// FuncFParams -> FuncFParam {',' FuncFParam}
FuncFParams :
    FuncFParam {
        
    } | FuncFParam ',' FuncFParams {
        
    }
    ;

// FuncFParam -> BType Ident ['[' ']' {'[' ConstExp ']'}]
FuncFParam :
    BType IDENT {
        
    } | BType IDENT '[' ']' {
        
    } | BType IDENT '[' ']' ArrayDims {
        
    }
    ;

// MainFuncDef -> 'int' 'main' '(' ')' Block
MainFuncDef :
    INT MAIN '(' ')' Block {
        printf("<MainFuncDef>\n");
    }
    ;

// Block -> '{' {BlockItem} '}'
Block :
    '{' '}' {
        printf("<Block>\n");
    } | '{' BlockItems '}' {
        printf("<Block>\n");
    }
    ;

BlockItems :
    BlockItem {
        
    } | BlockItem BlockItems {
        
    }
    ;

// BlockItem -> Decl | Stmt
BlockItem :
    Decl {
        
    } | Stmt {
        
    }
    ;

// Stmt -> LVal '=' Exp ';' | [Exp] ';' | Block
//      | 'if' '(' Cond ')' Stmt ['else' Stmt]
//      | 'while' '(' Cond ')' Stmt
//      | 'break' ';' | 'continue' ';'
//      | 'return' [Exp] ';' | LVal '=' 'getint' '(' ')' ';'
//      | 'printf' '(' FormatString {',' Exp} ')' ';'
Stmt :
    LVal '=' Exp ';' {
        printf("<Stmt>\n");
    } | ';' {
        printf("<Stmt>\n");
    } | Exp ';' {
        printf("<Stmt>\n");
    } | Block {
        printf("<Stmt>\n");
    } | IF '(' Cond ')' Stmt {
        printf("<Stmt>\n");
    } | IF '(' Cond ')' Stmt ELSE Stmt {
        printf("<Stmt>\n");
    } | WHILE '(' Cond ')' Stmt {
        printf("<Stmt>\n");
    } | BREAK ';' {
        printf("<Stmt>\n");
    } | CONTINUE ';' {
        printf("<Stmt>\n");
    } | RETURN ';' {
        printf("<Stmt>\n");
    } | RETURN Exp ';' {
        printf("<Stmt>\n");
    } | LVal '=' GETINT '(' ')' ';' {
        printf("<Stmt>\n");
    } | PRINTF '(' STR_CONST PrintfItems ')' ';' {
        printf("<Stmt>\n");
    }
    ;

PrintfItems :
    /* empty */ {
        
    } | ',' Exp PrintfItems {
        
    }
    ;

// Exp -> AddExp
Exp :
    AddExp {
        
    }
    ;

// Cond -> LOrExp
Cond :
    LOrExp {
        
    }
    ;

// LVal -> Ident {'[' Exp ']'}
LVal :
    IDENT {
        
    } | IDENT LValArrayIndices {
        
    }
    ;

LValArrayIndices :
    '[' Exp ']' {
        
    } | '[' Exp ']' LValArrayIndices {
        
    }
    ;

// PrimaryExp -> '(' Exp ')' | LVal | Number
PrimaryExp :
    '(' Exp ')' {
        
    } | LVal {
        
    } | Number {
        
    }
    ;

// Number -> IntConst
Number :
    INT_CONST {
        
    }
    ;

// UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
UnaryExp :
    PrimaryExp {
        
    } | IDENT '(' ')' {
        
    } | IDENT '(' FuncRParams ')' {
        
    } | UnaryOp UnaryExp {
        
    }
    ;

// UnaryOp -> '+' | '-' | '!'
UnaryOp :
    PLUS {
        
    } | MINUS {
        
    } | '!' {
        
    }
    ;

// FuncRParams -> Exp {',' Exp}
FuncRParams :
    Exp {
        
    } | Exp ',' FuncRParams {
        
    }
    ;

// MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
MulExp :
    UnaryExp {
        
    } | MulExp TIMES UnaryExp {
        
    } | MulExp DIVIDE UnaryExp {
        
    } | MulExp '%' UnaryExp {
        
    }
    ;

// AddExp -> MulExp | AddExp ('+' | '-') MulExp
AddExp :
    MulExp {
        
    } | AddExp PLUS MulExp {
        
    } | AddExp MINUS MulExp {
        
    }
    ;

// RelExp -> AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
RelExp :
    AddExp {
        
    } | RelExp LSS AddExp {
        
    } | RelExp GRE AddExp {
        
    } | RelExp LEQ AddExp {
        
    } | RelExp GEQ AddExp {
        
    }
    ;

// EqExp -> RelExp | EqExp ('==' | '!=') RelExp
EqExp :
    RelExp {
        
    } | EqExp EQL RelExp {
        
    } | EqExp NEQ RelExp {
        
    }
    ;

// LAndExp -> EqExp | LAndExp '&&' EqExp
LAndExp :
    EqExp {
        
    } | LAndExp AND EqExp {
        
    }
    ;

// LOrExp -> LAndExp | LOrExp '||' LAndExp
LOrExp :
    LAndExp {
        
    } | LOrExp OR LAndExp {
        
    }
    ;

%% 

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

extern FILE *yyin;

int main(int argc, char *argv[]) {
    // 如果没有提供命令行参数，使用标准输入
    if (argc <= 1) {
        yyin = stdin;
    } else {
        // 如果提供了文件名，尝试打开该文件
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "无法打开文件 '%s'\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    yydebug = 0;  // 调试模式：1为启用，0为关闭
    int result = yyparse();
    
    // 如果打开了文件，记得关闭
    if (argc > 1 && yyin != stdin) {
        fclose(yyin);
    }
    
    return result;
}