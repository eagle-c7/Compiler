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

%option yylineno


/* 空白符和注释 */
WHTIESPACE              [ \t\n\r]*
LINECOMMET              "//".*
BLOCKCOMMET             "/*"[^*]*[*]+([^*/][^*]*[*]+)*"/"

/* 整数字面量 */
DECIMAL                 [1-9][0-9]*
OCTAL                   0[0-7]*
HEXADECIMAL             0[xX][0-9a-fA-F]+

/* 浮点数 */
REAL                    [0-9]+\.[0-9]+

/* 字符串 */
STRING                  \"(\\.|[^\"\\])*?\"

/* 标识符 */
IDENTIFIER              [a-zA-Z_][a-zA-Z0-9_]*

%%

    /* 空白符和注释 */
{WHTIESPACE}            {;}
{LINECOMMET}            {;}
{BLOCKCOMMET}           {;}

    /* 运算符 */
    /* 关系运算符 */
"=="                    {return EQU;}
"!="                    {return NEQ;}
"<"                     {return LES;}
"<="                    {return LEQ;}
">"                     {return GRE;}
">="                    {return GEQ;}

    /* 算术运算符 */
"+"                     {return ADD;}
"-"                     {return SUB;}
"*"                     {return MUL;}
"/"                     {return DIV;}
"%"                     {return MOD;}

    /* 逻辑运算符 */
"&&"                    {return AND;}
"||"                    {return OR;}
"!"                     {return NOT;}

    /* 位运算符 */
"&"                     {return BAND;}
"|"                     {return BOR;}
"^"                     {return BXOR;}

    /*分隔符*/
"("             		{ return LPAREN; }
")"             		{ return RPAREN; }
"{"             		{ return LBRACE; }
"}"             		{ return RBRACE; }
"["						{return LBRACKET;}
"]"						{return RBRACKET;}
","                     {return COMMA;}
";"                     {return SEMI;}

    /* 赋值运算符 */
"="                     {return ASSIGN;}

    /* 特殊符号 */
"."                     {return DOT;}
":"                     {return COLON;}
"?"                     {return QUES;}
"..."					{return ELLIPSES;}
"ptr"				    {return PTR;}

    /* 关键字 */
    /* 数据类型 */
"int"                   {SAVE_TOKEN; return INT;}
"short"                 {SAVE_TOKEN; return SHORT;}
"char"                  {SAVE_TOKEN; return CHAR;}
"void"                  {SAVE_TOKEN; return VOID;}
"double"                {SAVE_TOKEN; return DOUBLE;}

    /* 跳转结构 */
"return"                {return RETURN;}
"continue"              {SAVE_TOKEN; return CONTINUE;}
"break"                 {SAVE_TOKEN; return BREAK;}

    /* 分支结构 */
"if"                    {SAVE_TOKEN; return IF;}
"else"                  {SAVE_TOKEN; return ELSE;}

    /* 循环结构 */
"for"                   {SAVE_TOKEN; return FOR;}
"while"                 {SAVE_TOKEN; return WHILE;}

"static"                {SAVE_TOKEN; return STATIC;}

{STRING}                {
                            yylval.strVal = new std::string("");
                            for (int i = 1; i <= yyleng-2; i++){
                                if (yytext[i] == '\\') {
                                    i ++; 
                                    switch(yytext[i]) {
                                        case 'n': yylval.strVal->push_back('\n'); break; 
                                        case 't': yylval.strVal->push_back('\t'); break; 
                                        default: yylval.strVal->push_back(yytext[i]);
                                    }
                                }
                                else {
                                    yylval.strVal->push_back(yytext[i]);
                                }
                            }
                            return CONST_STR;
                        }


{IDENTIFIER}            {SAVE_TOKEN; return IDENTIFIER;}


{DECIMAL}               { yylval.intVal = strtol(yytext, nullptr, 0); return CONST_INT; }
{OCTAL}                 { yylval.intVal = strtol(yytext, nullptr, 0); return CONST_INT; }
{HEXADECIMAL}           { yylval.intVal = strtol(yytext, nullptr, 0); return CONST_INT; }
 
{REAL}                  { double tmp; sscanf(yytext, "%lf", &tmp);yylval.douVal = tmp; return CONST_DOUBLE; }

"\'"[^\\']"\'"			{ yylval.charVal = yytext[1]; return CONST_CHAR; }


.                       { printf("Unknown token!/n");}

%%