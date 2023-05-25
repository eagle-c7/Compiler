/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EQU = 258,                     /* EQU  */
    NEQ = 259,                     /* NEQ  */
    LES = 260,                     /* LES  */
    LEQ = 261,                     /* LEQ  */
    GRE = 262,                     /* GRE  */
    GEQ = 263,                     /* GEQ  */
    ADD = 264,                     /* ADD  */
    SUB = 265,                     /* SUB  */
    MUL = 266,                     /* MUL  */
    DIV = 267,                     /* DIV  */
    MOD = 268,                     /* MOD  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    NOT = 271,                     /* NOT  */
    BAND = 272,                    /* BAND  */
    BOR = 273,                     /* BOR  */
    BXOR = 274,                    /* BXOR  */
    LPAREN = 275,                  /* LPAREN  */
    RPAREN = 276,                  /* RPAREN  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    COMMA = 279,                   /* COMMA  */
    SEMI = 280,                    /* SEMI  */
    ASSIGN = 281,                  /* ASSIGN  */
    DOT = 282,                     /* DOT  */
    COLON = 283,                   /* COLON  */
    QUES = 284,                    /* QUES  */
    INT = 285,                     /* INT  */
    CHAR = 286,                    /* CHAR  */
    SHORT = 287,                   /* SHORT  */
    VOID = 288,                    /* VOID  */
    RETURN = 289,                  /* RETURN  */
    CONTINUE = 290,                /* CONTINUE  */
    BREAK = 291,                   /* BREAK  */
    IF = 292,                      /* IF  */
    ELSE = 293,                    /* ELSE  */
    FOR = 294,                     /* FOR  */
    WHILE = 295,                   /* WHILE  */
    CONST = 296,                   /* CONST  */
    IDENTIFIER = 297,              /* IDENTIFIER  */
    CONST_INT = 298,               /* CONST_INT  */
    CONST_CHAR = 299,              /* CONST_CHAR  */
    CONST_FLOAT = 300,             /* CONST_FLOAT  */
    CONST_STR = 301                /* CONST_STR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "parser.y"

    std::string* strVal;
	float floatVal;
    int intVal;
    BaseAST *astVal;
	CompUnits *compUnits;
	Stmts *stmts;

#line 119 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */