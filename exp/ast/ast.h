#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <string>

// 全局节点ID计数器，用于生成唯一的节点标识
static int node_id_counter = 0;

// 辅助函数：转义DOT标签中的特殊字符
inline std::string EscapeStringForDOT(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        switch (c)
        {
        case '%':
            result += "\\%";
            break;
        case '"':
            result += "\\\"";
            break;
        case '\\':
            result += "\\\\";
            break;
        case '<':
            result += "\\<";
            break;
        case '>':
            result += "\\>";
            break;
        case '{':
            result += "\\{";
            break;
        case '}':
            result += "\\}";
            break;
        case '|':
            result += "\\|";
            break;
        default:
            result += c;
            break;
        }
    }
    return result;
}

// AST节点基类
class BaseAST
{
public:
    virtual ~BaseAST() = default;

    virtual std::string DumpDOT() const = 0;

    virtual int GetNodeID() const = 0;

    static int NewNodeID()
    {
        return node_id_counter++;
    }
};

// 类型枚举
enum Type
{
    TYPE_INT,
    TYPE_VOID
};

// 编译单元AST节点
class CompUnitAST : public BaseAST
{
private:
    int node_id;

public:
    // Use vectors instead of linked list and separate pointers
    std::vector<std::unique_ptr<BaseAST>> declarations;
    std::vector<std::unique_ptr<BaseAST>> function_definitions;
    std::unique_ptr<BaseAST> main_func_def;

    CompUnitAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        // 定义此节点
        ss << "  node" << node_id << " [label=\"CompUnit\", shape=box, style=filled, fillcolor=lightblue];\n";

        // 连接声明子节点
        for (size_t i = 0; i < declarations.size(); ++i)
        {
            if (declarations[i])
            {
                ss << "  node" << node_id << " -> node" << declarations[i]->GetNodeID()
                   << " [label=\"decl_" << i << "\"];\n";
                ss << declarations[i]->DumpDOT();
            }
        }

        // 连接函数定义子节点
        for (size_t i = 0; i < function_definitions.size(); ++i)
        {
            if (function_definitions[i])
            {
                ss << "  node" << node_id << " -> node" << function_definitions[i]->GetNodeID()
                   << " [label=\"func_def_" << i << "\"];\n";
                ss << function_definitions[i]->DumpDOT();
            }
        }

        // 连接主函数定义子节点
        if (main_func_def)
        {
            ss << "  node" << node_id << " -> node" << main_func_def->GetNodeID()
               << " [label=\"main_func_def\"];\n";
            ss << main_func_def->DumpDOT();
        }

        return ss.str();
    }
};

// 声明AST节点
class DeclAST : public BaseAST
{
private:
    int node_id;

public:
    enum DeclKind
    {
        CONST_DECL,
        VAR_DECL
    };

    DeclKind kind;
    std::unique_ptr<BaseAST> decl; // 可以是 ConstDecl 或 VarDecl

    DeclAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"Decl\", shape=box];\n";

        if (decl)
        {
            ss << "  node" << node_id << " -> node" << decl->GetNodeID()
               << " [label=\"decl\"];\n";
            ss << decl->DumpDOT();
        }

        return ss.str();
    }
};

// 常量声明AST节点
class ConstDeclAST : public BaseAST
{
private:
    int node_id;

public:
    Type type;
    std::string ident;
    int value;
    std::unique_ptr<BaseAST> const_def;
    std::unique_ptr<BaseAST> const_def_list;

    ConstDeclAST() : node_id(NewNodeID()) {}

    // 从C风格字符串构造
    ConstDeclAST(const char *id) : node_id(NewNodeID()), ident(id) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "ConstDecl\\nident: " + ident +
                            "\\ntype: " + (type == TYPE_INT ? "int" : "void");
        if (!ident.empty())
        {
            label += "\\nvalue: " + std::to_string(value);
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightyellow];\n";

        if (const_def)
        {
            ss << "  node" << node_id << " -> node" << const_def->GetNodeID()
               << " [label=\"const_def\"];\n";
            ss << const_def->DumpDOT();
        }

        if (const_def_list)
        {
            ss << "  node" << node_id << " -> node" << const_def_list->GetNodeID()
               << " [label=\"const_def_list\"];\n";
            ss << const_def_list->DumpDOT();
        }

        return ss.str();
    }
};

// 变量声明AST节点
class VarDeclAST : public BaseAST
{
private:
    int node_id;

public:
    Type type;
    std::string ident;
    std::unique_ptr<BaseAST> var_def;
    std::unique_ptr<BaseAST> var_def_list;

    VarDeclAST() : node_id(NewNodeID()) {}

    // 从C风格字符串构造
    VarDeclAST(const char *id) : node_id(NewNodeID()), ident(id) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "VarDecl\\nident: " + ident +
                            "\\ntype: " + (type == TYPE_INT ? "int" : "void");

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightgreen];\n";

        if (var_def)
        {
            ss << "  node" << node_id << " -> node" << var_def->GetNodeID()
               << " [label=\"var_def\"];\n";
            ss << var_def->DumpDOT();
        }

        if (var_def_list)
        {
            ss << "  node" << node_id << " -> node" << var_def_list->GetNodeID()
               << " [label=\"var_def_list\"];\n";
            ss << var_def_list->DumpDOT();
        }

        return ss.str();
    }
};

// 主函数定义AST节点
class MainFuncDefAST : public BaseAST
{
private:
    int node_id;

public:
    std::unique_ptr<BaseAST> block;

    MainFuncDefAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"MainFuncDef\\nint main()\", shape=box, style=filled, fillcolor=lightcoral];\n";

        if (block)
        {
            ss << "  node" << node_id << " -> node" << block->GetNodeID()
               << " [label=\"block\"];\n";
            ss << block->DumpDOT();
        }

        return ss.str();
    }
};

// 代码块AST节点
class BlockAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> items;

    BlockAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"Block\", shape=box, style=filled, fillcolor=lightgrey];\n";

        // 连接所有子项目
        for (size_t i = 0; i < items.size(); i++)
        {
            if (items[i])
            {
                ss << "  node" << node_id << " -> node" << items[i]->GetNodeID()
                   << " [label=\"item" << i << "\"];\n";
                ss << items[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 块项目AST节点
class BlockItemAST : public BaseAST
{
private:
    int node_id;

public:
    std::unique_ptr<BaseAST> item; // 可以是 Decl 或 Stmt

    BlockItemAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"BlockItem\", shape=box];\n";

        if (item)
        {
            ss << "  node" << node_id << " -> node" << item->GetNodeID()
               << " [label=\"item\"];\n";
            ss << item->DumpDOT();
        }

        return ss.str();
    }
};

// 语句AST节点
class StmtAST : public BaseAST
{
private:
    int node_id;

public:
    enum StmtKind
    {
        ASSIGNMENT,
        BLOCK,
        RETURN,
        ASSIGN,
        EMPTY,
        EXPRESSION,
        IF,
        IF_ELSE,
        WHILE,
        BREAK,
        CONTINUE,
        RETURN_VOID,
        RETURN_EXP,
        GETINT,
        PRINTF
    };

    StmtKind kind;
    std::unique_ptr<BaseAST> content;    // Assignment, Block 或 返回值标识符
    std::unique_ptr<BaseAST> cond;       // 条件表达式，用于if和while语句
    std::unique_ptr<BaseAST> if_stmt;    // if语句中的执行体
    std::unique_ptr<BaseAST> else_stmt;  // else语句中的执行体
    std::unique_ptr<BaseAST> while_stmt; // while语句中的执行体
    std::string return_ident;            // 如果是RETURN类型，存储返回的标识符

    StmtAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        std::string label;

        switch (kind)
        {
        case ASSIGNMENT:
            label = "Stmt\\nkind: ASSIGNMENT";
            break;
        case BLOCK:
            label = "Stmt\\nkind: BLOCK";
            break;
        case RETURN:
            label = "Stmt\\nkind: RETURN\\nident: " + return_ident;
            break;
        case ASSIGN:
            label = "Stmt\\nkind: ASSIGN";
            break;
        case EMPTY:
            label = "Stmt\\nkind: EMPTY";
            break;
        case EXPRESSION:
            label = "Stmt\\nkind: EXPRESSION";
            break;
        case IF:
            label = "Stmt\\nkind: IF";
            break;
        case IF_ELSE:
            label = "Stmt\\nkind: IF_ELSE";
            break;
        case WHILE:
            label = "Stmt\\nkind: WHILE";
            break;
        case BREAK:
            label = "Stmt\\nkind: BREAK";
            break;
        case CONTINUE:
            label = "Stmt\\nkind: CONTINUE";
            break;
        case RETURN_VOID:
            label = "Stmt\\nkind: RETURN_VOID";
            break;
        case RETURN_EXP:
            label = "Stmt\\nkind: RETURN_EXP";
            break;
        case GETINT:
            label = "Stmt\\nkind: GETINT";
            break;
        case PRINTF:
            label = "Stmt\\nkind: PRINTF";
            break;
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        if (content)
        {
            std::string edge_label;
            switch (kind)
            {
            case ASSIGNMENT:
                edge_label = "assignment";
                break;
            case BLOCK:
                edge_label = "block";
                break;
            case RETURN_EXP:
            case EXPRESSION:
            case GETINT:
            case PRINTF:
                edge_label = "content";
                break;
            default:
                edge_label = "content";
                break;
            }

            ss << "  node" << node_id << " -> node" << content->GetNodeID()
               << " [label=\"" << edge_label << "\"];\n";
            ss << content->DumpDOT();
        }

        if (cond)
        {
            ss << "  node" << node_id << " -> node" << cond->GetNodeID()
               << " [label=\"condition\"];\n";
            ss << cond->DumpDOT();
        }

        if (if_stmt)
        {
            ss << "  node" << node_id << " -> node" << if_stmt->GetNodeID()
               << " [label=\"if_stmt\"];\n";
            ss << if_stmt->DumpDOT();
        }

        if (else_stmt)
        {
            ss << "  node" << node_id << " -> node" << else_stmt->GetNodeID()
               << " [label=\"else_stmt\"];\n";
            ss << else_stmt->DumpDOT();
        }

        if (while_stmt)
        {
            ss << "  node" << node_id << " -> node" << while_stmt->GetNodeID()
               << " [label=\"while_stmt\"];\n";
            ss << while_stmt->DumpDOT();
        }

        return ss.str();
    }
};

// 赋值语句AST节点
class AssignmentAST : public BaseAST
{
private:
    int node_id;

public:
    std::string ident;
    std::unique_ptr<BaseAST> lval;
    std::unique_ptr<BaseAST> exp;

    AssignmentAST() : node_id(NewNodeID()) {}

    // 从C风格字符串构造
    AssignmentAST(const char *id) : node_id(NewNodeID()), ident(id) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "Assignment\\nident: " + ident;
        if (lval && exp)
        {
            label += "\\nassignment_type: regular";
        }
        else
        {
            label += "\\nis_getint: true";
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightsalmon];\n";

        if (lval)
        {
            ss << "  node" << node_id << " -> node" << lval->GetNodeID()
               << " [label=\"lval\"];\n";
            ss << lval->DumpDOT();
        }

        if (exp)
        {
            ss << "  node" << node_id << " -> node" << exp->GetNodeID()
               << " [label=\"exp\"];\n";
            ss << exp->DumpDOT();
        }

        return ss.str();
    }
};

// 数字AST节点
class NumberAST : public BaseAST
{
private:
    int node_id;

public:
    int value;

    NumberAST() : node_id(NewNodeID()) {}

    NumberAST(int val) : node_id(NewNodeID()), value(val) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "Number\\nvalue: " + std::to_string(value);

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse, style=filled, fillcolor=lightpink];\n";

        return ss.str();
    }
};

// 函数定义AST节点
class FuncDefAST : public BaseAST
{
private:
    int node_id;

public:
    Type return_type;
    std::string ident;
    std::unique_ptr<BaseAST> func_f_params;
    std::unique_ptr<BaseAST> block;

    FuncDefAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "FuncDef\\nident: " + ident +
                            "\\nreturn_type: " + (return_type == TYPE_INT ? "int" : "void");

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightcoral];\n";

        if (func_f_params)
        {
            ss << "  node" << node_id << " -> node" << func_f_params->GetNodeID()
               << " [label=\"params\"];\n";
            ss << func_f_params->DumpDOT();
        }

        if (block)
        {
            ss << "  node" << node_id << " -> node" << block->GetNodeID()
               << " [label=\"block\"];\n";
            ss << block->DumpDOT();
        }

        return ss.str();
    }
};

// BType AST节点
class BTypeAST : public BaseAST
{
private:
    int node_id;

public:
    Type type;

    BTypeAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = std::string("BType\\ntype: ") + (type == TYPE_INT ? "int" : "void");

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        return ss.str();
    }
};

// 常量定义列表AST节点
class ConstDefListAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> const_defs;

    ConstDefListAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"ConstDefList\", shape=box];\n";

        for (size_t i = 0; i < const_defs.size(); i++)
        {
            if (const_defs[i])
            {
                ss << "  node" << node_id << " -> node" << const_defs[i]->GetNodeID()
                   << " [label=\"const_def" << i << "\"];\n";
                ss << const_defs[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 常量定义AST节点
class ConstDefAST : public BaseAST
{
private:
    int node_id;

public:
    std::string ident;
    std::unique_ptr<BaseAST> array_dims;
    std::unique_ptr<BaseAST> const_init_val;

    ConstDefAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "ConstDef\\nident: " + ident;

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightyellow];\n";

        if (array_dims)
        {
            ss << "  node" << node_id << " -> node" << array_dims->GetNodeID()
               << " [label=\"array_dims\"];\n";
            ss << array_dims->DumpDOT();
        }

        if (const_init_val)
        {
            ss << "  node" << node_id << " -> node" << const_init_val->GetNodeID()
               << " [label=\"const_init_val\"];\n";
            ss << const_init_val->DumpDOT();
        }

        return ss.str();
    }
};

// 数组维度AST节点
class ArrayDimsAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> dims;

    ArrayDimsAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"ArrayDims\", shape=box];\n";

        for (size_t i = 0; i < dims.size(); i++)
        {
            if (dims[i])
            {
                ss << "  node" << node_id << " -> node" << dims[i]->GetNodeID()
                   << " [label=\"dim" << i << "\"];\n";
                ss << dims[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 常量初始值AST节点
class ConstInitValAST : public BaseAST
{
private:
    int node_id;

public:
    enum InitType
    {
        EXPR,
        LIST
    };

    InitType init_type;
    std::unique_ptr<BaseAST> expr;
    std::unique_ptr<BaseAST> list;

    ConstInitValAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = std::string("ConstInitVal\\ntype: ") +
                            (init_type == EXPR ? "expr" : "list");

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box];\n";

        if (init_type == InitType::EXPR && expr)
        {
            ss << "  node" << node_id << " -> node" << expr->GetNodeID()
               << " [label=\"expr\"];\n";
            ss << expr->DumpDOT();
        }
        else if (init_type == InitType::LIST && list)
        {
            ss << "  node" << node_id << " -> node" << list->GetNodeID()
               << " [label=\"list\"];\n";
            ss << list->DumpDOT();
        }

        return ss.str();
    }
};

// 常量初始值列表AST节点
class ConstInitValListAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> init_vals;

    ConstInitValListAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"ConstInitValList\", shape=box];\n";

        for (size_t i = 0; i < init_vals.size(); i++)
        {
            if (init_vals[i])
            {
                ss << "  node" << node_id << " -> node" << init_vals[i]->GetNodeID()
                   << " [label=\"init_val" << i << "\"];\n";
                ss << init_vals[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 常量表达式AST节点
class ConstExpAST : public BaseAST
{
private:
    int node_id;

public:
    std::unique_ptr<BaseAST> exp;

    ConstExpAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"ConstExp\", shape=box];\n";

        if (exp)
        {
            ss << "  node" << node_id << " -> node" << exp->GetNodeID()
               << " [label=\"exp\"];\n";
            ss << exp->DumpDOT();
        }

        return ss.str();
    }
};

// 变量定义列表AST节点
class VarDefListAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> var_defs;

    VarDefListAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"VarDefList\", shape=box];\n";

        for (size_t i = 0; i < var_defs.size(); i++)
        {
            if (var_defs[i])
            {
                ss << "  node" << node_id << " -> node" << var_defs[i]->GetNodeID()
                   << " [label=\"var_def" << i << "\"];\n";
                ss << var_defs[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 变量定义AST节点
class VarDefAST : public BaseAST
{
private:
    int node_id;

public:
    std::string ident;
    std::unique_ptr<BaseAST> array_dims;
    std::unique_ptr<BaseAST> init_val;
    bool has_init;

    VarDefAST() : node_id(NewNodeID()), has_init(false) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "VarDef\\nident: " + ident +
                            "\\nhas_init: " + (has_init ? "true" : "false");

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightgreen];\n";

        if (array_dims)
        {
            ss << "  node" << node_id << " -> node" << array_dims->GetNodeID()
               << " [label=\"array_dims\"];\n";
            ss << array_dims->DumpDOT();
        }

        if (has_init && init_val)
        {
            ss << "  node" << node_id << " -> node" << init_val->GetNodeID()
               << " [label=\"init_val\"];\n";
            ss << init_val->DumpDOT();
        }

        return ss.str();
    }
};

// 初始值AST节点
class InitValAST : public BaseAST
{
private:
    int node_id;

public:
    enum InitType
    {
        EXPR,
        LIST
    };

    InitType init_type;
    std::unique_ptr<BaseAST> expr;
    std::unique_ptr<BaseAST> list;

    InitValAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = std::string("InitVal\\ntype: ") +
                            (init_type == EXPR ? "expr" : "list");

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box];\n";

        if (init_type == InitType::EXPR && expr)
        {
            ss << "  node" << node_id << " -> node" << expr->GetNodeID()
               << " [label=\"expr\"];\n";
            ss << expr->DumpDOT();
        }
        else if (init_type == InitType::LIST && list)
        {
            ss << "  node" << node_id << " -> node" << list->GetNodeID()
               << " [label=\"list\"];\n";
            ss << list->DumpDOT();
        }

        return ss.str();
    }
};

// 初始值列表AST节点
class InitValListAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> init_vals;

    InitValListAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"InitValList\", shape=box];\n";

        for (size_t i = 0; i < init_vals.size(); i++)
        {
            if (init_vals[i])
            {
                ss << "  node" << node_id << " -> node" << init_vals[i]->GetNodeID()
                   << " [label=\"init_val" << i << "\"];\n";
                ss << init_vals[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 函数形参列表AST节点
class FuncFParamsAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> params;

    FuncFParamsAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"FuncFParams\", shape=box];\n";

        for (size_t i = 0; i < params.size(); i++)
        {
            if (params[i])
            {
                ss << "  node" << node_id << " -> node" << params[i]->GetNodeID()
                   << " [label=\"param" << i << "\"];\n";
                ss << params[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 函数形参AST节点
class FuncFParamAST : public BaseAST
{
private:
    int node_id;

public:
    Type param_type;
    std::string ident;
    bool is_array;
    std::unique_ptr<BaseAST> array_dims;

    FuncFParamAST() : node_id(NewNodeID()), is_array(false) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "FuncFParam\\nident: " + ident +
                            "\\ntype: " + (param_type == TYPE_INT ? "int" : "void") +
                            "\\nis_array: " + (is_array ? "true" : "false");

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box];\n";

        if (is_array && array_dims)
        {
            ss << "  node" << node_id << " -> node" << array_dims->GetNodeID()
               << " [label=\"array_dims\"];\n";
            ss << array_dims->DumpDOT();
        }

        return ss.str();
    }
};

// Printf项目列表AST节点
class PrintfItemsAST : public BaseAST
{
private:
    int node_id;

public:
    std::string format_string;
    std::vector<std::unique_ptr<BaseAST>> expressions;

    PrintfItemsAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "PrintfItems\\nformat: " + EscapeStringForDOT(format_string);

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box];\n";

        for (size_t i = 0; i < expressions.size(); i++)
        {
            if (expressions[i])
            {
                ss << "  node" << node_id << " -> node" << expressions[i]->GetNodeID()
                   << " [label=\"expr" << i << "\"];\n";
                ss << expressions[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 表达式AST节点
class ExpAST : public BaseAST
{
private:
    int node_id;

public:
    std::unique_ptr<BaseAST> expr;

    ExpAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"Exp\", shape=ellipse];\n";

        if (expr)
        {
            ss << "  node" << node_id << " -> node" << expr->GetNodeID()
               << " [label=\"expr\"];\n";
            ss << expr->DumpDOT();
        }

        return ss.str();
    }
};

// 条件表达式AST节点
class CondAST : public BaseAST
{
private:
    int node_id;

public:
    std::unique_ptr<BaseAST> expr;

    CondAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"Cond\", shape=ellipse];\n";

        if (expr)
        {
            ss << "  node" << node_id << " -> node" << expr->GetNodeID()
               << " [label=\"expr\"];\n";
            ss << expr->DumpDOT();
        }

        return ss.str();
    }
};

// 左值表达式AST节点
class LValAST : public BaseAST
{
private:
    int node_id;

public:
    std::string ident;
    std::unique_ptr<BaseAST> array_indices;

    LValAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "LVal\\nident: " + ident;

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (array_indices)
        {
            ss << "  node" << node_id << " -> node" << array_indices->GetNodeID()
               << " [label=\"indices\"];\n";
            ss << array_indices->DumpDOT();
        }

        return ss.str();
    }
};

// 左值数组索引AST节点
class LValArrayIndicesAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> indices;

    LValArrayIndicesAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"LValArrayIndices\", shape=box];\n";

        for (size_t i = 0; i < indices.size(); i++)
        {
            if (indices[i])
            {
                ss << "  node" << node_id << " -> node" << indices[i]->GetNodeID()
                   << " [label=\"index" << i << "\"];\n";
                ss << indices[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 基本表达式AST节点
class PrimaryExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum PrimaryType
    {
        EXP,
        LVAL,
        NUMBER
    };

    PrimaryType type;
    std::unique_ptr<BaseAST> exp;
    std::unique_ptr<BaseAST> lval;
    std::unique_ptr<BaseAST> number;

    PrimaryExpAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "PrimaryExp\\ntype: ";
        switch (type)
        {
        case PrimaryType::EXP:
            label += "exp";
            break;
        case PrimaryType::LVAL:
            label += "lval";
            break;
        case PrimaryType::NUMBER:
            label += "number";
            break;
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (type == PrimaryType::EXP && exp)
        {
            ss << "  node" << node_id << " -> node" << exp->GetNodeID()
               << " [label=\"exp\"];\n";
            ss << exp->DumpDOT();
        }
        else if (type == PrimaryType::LVAL && lval)
        {
            ss << "  node" << node_id << " -> node" << lval->GetNodeID()
               << " [label=\"lval\"];\n";
            ss << lval->DumpDOT();
        }
        else if (type == PrimaryType::NUMBER && number)
        {
            ss << "  node" << node_id << " -> node" << number->GetNodeID()
               << " [label=\"number\"];\n";
            ss << number->DumpDOT();
        }

        return ss.str();
    }
};

// 一元表达式AST节点
class UnaryExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum UnaryType
    {
        PRIMARY,
        UNARY,
        FUNC_CALL
    };

    UnaryType type;
    std::unique_ptr<BaseAST> primary_exp;
    std::unique_ptr<BaseAST> unary_op;
    std::unique_ptr<BaseAST> unary_exp;
    std::string func_name;
    std::unique_ptr<BaseAST> func_r_params;

    UnaryExpAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "UnaryExp\\ntype: ";
        switch (type)
        {
        case UnaryType::PRIMARY:
            label += "primary";
            break;
        case UnaryType::UNARY:
            label += "unary";
            break;
        case UnaryType::FUNC_CALL:
            label += "func_call\\nfunc: " + func_name;
            break;
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (type == UnaryType::PRIMARY && primary_exp)
        {
            ss << "  node" << node_id << " -> node" << primary_exp->GetNodeID()
               << " [label=\"primary_exp\"];\n";
            ss << primary_exp->DumpDOT();
        }
        else if (type == UnaryType::UNARY && unary_op && unary_exp)
        {
            ss << "  node" << node_id << " -> node" << unary_op->GetNodeID()
               << " [label=\"unary_op\"];\n";
            ss << unary_op->DumpDOT();

            ss << "  node" << node_id << " -> node" << unary_exp->GetNodeID()
               << " [label=\"unary_exp\"];\n";
            ss << unary_exp->DumpDOT();
        }
        else if (type == UnaryType::FUNC_CALL)
        {
            if (func_r_params)
            {
                ss << "  node" << node_id << " -> node" << func_r_params->GetNodeID()
                   << " [label=\"params\"];\n";
                ss << func_r_params->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 一元操作符AST节点
class UnaryOpAST : public BaseAST
{
private:
    int node_id;

public:
    enum OpType
    {
        PLUS,
        MINUS,
        NOT
    };

    OpType op;

    UnaryOpAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss; // Add stringstream declaration
        std::string label = "UnaryOp\\n";
        switch (op)
        {
        case OpType::PLUS:
            label += "+";
            break;
        case OpType::MINUS:
            label += "-";
            break;
        case OpType::NOT:
            label += "!";
            break;
        }

        // Remove duplicate line
        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        return ss.str();
    }
};

// 函数实参列表AST节点
class FuncRParamsAST : public BaseAST
{
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> params;

    FuncRParamsAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        ss << "  node" << node_id << " [label=\"FuncRParams\", shape=box];\n";

        for (size_t i = 0; i < params.size(); i++)
        {
            if (params[i])
            {
                ss << "  node" << node_id << " -> node" << params[i]->GetNodeID()
                   << " [label=\"param" << i << "\"];\n";
                ss << params[i]->DumpDOT();
            }
        }

        return ss.str();
    }
};

// 乘法表达式AST节点
class MulExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum OpType
    {
        NONE,
        MUL,
        DIV,
        MOD
    };

    OpType op;
    std::unique_ptr<BaseAST> left;
    std::unique_ptr<BaseAST> right;

    MulExpAST() : node_id(NewNodeID()), op(NONE) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "MulExp";
        if (op != OpType::NONE)
        {
            label += "\\nop: ";
            switch (op)
            {
            case OpType::MUL:
                label += "*";
                break;
            case OpType::DIV:
                label += "/";
                break;
            case OpType::MOD:
                label += "%";
                break;
            default:
                break; // Should not happen if op != NONE
            }
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (left)
        {
            ss << "  node" << node_id << " -> node" << left->GetNodeID()
               << " [label=\"left\"];\n";
            ss << left->DumpDOT();
        }

        if (op != OpType::NONE && right)
        {
            ss << "  node" << node_id << " -> node" << right->GetNodeID()
               << " [label=\"right\"];\n";
            ss << right->DumpDOT();
            // Remove duplicate lines
        }

        return ss.str();
    }
};

// 加法表达式AST节点
class AddExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum OpType
    {
        NONE,
        ADD,
        SUB
    };

    OpType op;
    std::unique_ptr<BaseAST> left;
    std::unique_ptr<BaseAST> right;

    AddExpAST() : node_id(NewNodeID()), op(NONE) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "AddExp";
        if (op != OpType::NONE)
        {
            label += "\\nop: ";
            switch (op)
            {
            case OpType::ADD:
                label += "+";
                break;
            case OpType::SUB:
                label += "-";
                break;
            default:
                break; // Should not happen if op != NONE
            }
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (left)
        {
            ss << "  node" << node_id << " -> node" << left->GetNodeID()
               << " [label=\"left\"];\n";
            ss << left->DumpDOT();
        }

        if (op != OpType::NONE && right)
        {
            ss << "  node" << node_id << " -> node" << right->GetNodeID()
               << " [label=\"right\"];\n";
            ss << right->DumpDOT();
            // Remove duplicate lines
        }

        return ss.str();
    }
};

// 关系表达式AST节点
class RelExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum OpType
    {
        NONE,
        LESS,
        GREATER,
        LESS_EQ,
        GREATER_EQ
    };

    OpType op;
    std::unique_ptr<BaseAST> left;
    std::unique_ptr<BaseAST> right;

    RelExpAST() : node_id(NewNodeID()), op(NONE) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "RelExp";
        if (op != OpType::NONE)
        {
            label += "\\nop: ";
            switch (op)
            {
            case OpType::LESS:
                label += "<";
                break;
            case OpType::GREATER:
                label += ">";
                break;
            case OpType::LESS_EQ:
                label += "<=";
                break;
            case OpType::GREATER_EQ:
                label += ">=";
                break;
            default:
                break; // Should not happen if op != NONE
            }
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (left)
        {
            ss << "  node" << node_id << " -> node" << left->GetNodeID()
               << " [label=\"left\"];\n";
            ss << left->DumpDOT();
        }

        if (op != OpType::NONE && right)
        {
            ss << "  node" << node_id << " -> node" << right->GetNodeID()
               << " [label=\"right\"];\n";
            ss << right->DumpDOT();
            // Remove duplicate lines
        }

        return ss.str();
    }
};

// 相等性表达式AST节点
class EqExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum OpType
    {
        NONE,
        EQ,
        NEQ
    };

    OpType op;
    std::unique_ptr<BaseAST> left;
    std::unique_ptr<BaseAST> right;

    EqExpAST() : node_id(NewNodeID()), op(NONE) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "EqExp";
        if (op != OpType::NONE)
        {
            label += "\\nop: ";
            switch (op)
            {
            case OpType::EQ:
                label += "==";
                break;
            case OpType::NEQ:
                label += "!=";
                break;
            default:
                break; // Should not happen if op != NONE
            }
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (left)
        {
            ss << "  node" << node_id << " -> node" << left->GetNodeID()
               << " [label=\"left\"];\n";
            ss << left->DumpDOT();
        }

        if (op != OpType::NONE && right)
        {
            ss << "  node" << node_id << " -> node" << right->GetNodeID()
               << " [label=\"right\"];\n";
            ss << right->DumpDOT();
            // Remove duplicate lines
        }

        return ss.str();
    }
};

// 逻辑与表达式AST节点
class LAndExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum OpType
    {
        NONE,
        AND
    };

    OpType op;
    std::unique_ptr<BaseAST> left;
    std::unique_ptr<BaseAST> right;

    LAndExpAST() : node_id(NewNodeID()), op(NONE) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "LAndExp";
        if (op != OpType::NONE)
        {
            label += "\\nop: &&";
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (left)
        {
            ss << "  node" << node_id << " -> node" << left->GetNodeID()
               << " [label=\"left\"];\n";
            ss << left->DumpDOT();
        }

        if (op != OpType::NONE && right)
        {
            ss << "  node" << node_id << " -> node" << right->GetNodeID()
               << " [label=\"right\"];\n";
            ss << right->DumpDOT();
            // Remove duplicate lines
        }

        return ss.str();
    }
};

// 逻辑或表达式AST节点
class LOrExpAST : public BaseAST
{
private:
    int node_id;

public:
    enum OpType
    {
        NONE,
        OR
    };

    OpType op;
    std::unique_ptr<BaseAST> left;
    std::unique_ptr<BaseAST> right;

    LOrExpAST() : node_id(NewNodeID()), op(NONE) {}

    int GetNodeID() const override
    {
        return node_id;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;

        std::string label = "LOrExp";
        if (op != OpType::NONE)
        {
            label += "\\nop: ||";
        }

        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse];\n";

        if (left)
        {
            ss << "  node" << node_id << " -> node" << left->GetNodeID()
               << " [label=\"left\"];\n";
            ss << left->DumpDOT();
        }

        if (op != OpType::NONE && right)
        {
            ss << "  node" << node_id << " -> node" << right->GetNodeID()
               << " [label=\"right\"];\n";
            ss << right->DumpDOT();
            // Remove duplicate lines
        }

        return ss.str();
    }
};
