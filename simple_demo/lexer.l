%option never-interactive
%option outfile="lexer.cpp"

%{
#include "AST.hpp"
#include "parser.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

#define SAVE_TOKEN yylval.strVal = new std::string(yytext, yyleng)
// 因为 Flex 会用到 Bison 中关于 token 的定义
// 所以需要 include Bison 生成的头文件
extern "C" int yywrap() {return 1;}

using namespace std;

%}

/* 空白符和注释 */
WhiteSpace    [ \t\n\r]*
LineComment   "//".*

/* 标识符 */
Identifier    [a-zA-Z_][a-zA-Z0-9_]*

/* 整数字面量 */
Decimal       [1-9][0-9]*
Octal         0[0-7]*
Hexadecimal   0[xX][0-9a-fA-F]+

%%

{WhiteSpace}    { /* 忽略, 不做任何操作 */ }
{LineComment}   { /* 忽略, 不做任何操作 */ }

"+"             { return ADD; }
"int"           { SAVE_TOKEN; return INT; }
"return"        { return RETURN; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

{Identifier}    { SAVE_TOKEN; return IDENTIFIER; }

{Decimal}       { yylval.intVal = strtol(yytext, nullptr, 0); return CONST_INT; }
{Octal}         { yylval.intVal = strtol(yytext, nullptr, 0); return CONST_INT; }
{Hexadecimal}   { yylval.intVal = strtol(yytext, nullptr, 0); return CONST_INT; }

.               { return yytext[0]; }

%%