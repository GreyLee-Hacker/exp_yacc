%option noyywrap
%{

#include "yacc.tab.h"

%}

INTCON     [0-9]+
IDENFR     [a-zA-Z_][a-zA-Z0-9_]*
STRCON     \"([^\"\\]|\\.)*\" 

%%
"//".*$    { /* 忽略单行注释 */ }  /* 匹配从//开始到行尾的所有内容并忽略 */

"/*"    {
    int c;
    while ((c = input()) != 0) {
        if (c == '*') {
            if ((c = input()) == '/')
                break;
            unput(c);
        }
    }
}

"main"              { return MAIN; }
"const"             { return CONST; }
"int"               { return INT; }
"void"              { return VOID; }
"break"             { return BREAK; }
"continue"          { return CONTINUE; }
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"getint"            { return GETINT; }
"printf"            { return PRINTF; }
"return"            { return RETURN; }

"{"                 { return yytext[0]; }
"}"                 { return yytext[0]; }
"("                 { return yytext[0]; }
")"                 { return yytext[0]; }
";"                 { return yytext[0]; }
","                 { return yytext[0]; }
"["                 { return yytext[0]; }
"]"                 { return yytext[0]; }

"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return TIMES; }
"/"                 { return DIVIDE; }
"%"                 { return '%'; }
"="                 { return yytext[0]; }

"<"                 { return LSS; }
"<="                { return LEQ; }
">"                 { return GRE; }
">="                { return GEQ; }
"=="                { return EQL; }
"!="                { return NEQ; }
"!"                 { return '!'; }
"&&"                { return AND; }
"||"                { return OR; }

{INTCON}            { return INT_CONST; }
{IDENFR}            { return IDENT; }
{STRCON}            { return STR_CONST; }

[ \t\r\n]+          ;   // 忽略空白符
.                   { return yytext[0]; }

%%