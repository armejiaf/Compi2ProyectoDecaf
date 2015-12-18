/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_CONSTANT = 258,
    CHAR_CONSTANT = 259,
    ID = 260,
    STRING_CONSTANT = 261,
    KW_CLASS = 262,
    KW_BREAK = 263,
    KW_READ = 264,
    KW_PRINT = 265,
    KW_CONTINUE = 266,
    KW_EXTENDS = 267,
    KW_ELSE = 268,
    KW_WHILE = 269,
    KW_FOR = 270,
    KW_IF = 271,
    KW_INT = 272,
    KW_NEW = 273,
    KW_NULL = 274,
    KW_RETURN = 275,
    KW_TRUE = 276,
    KW_FALSE = 277,
    KW_VOID = 278,
    KW_BOOL = 279,
    OP_LT = 280,
    OP_GT = 281,
    OP_LTE = 282,
    OP_GTE = 283,
    OP_NE = 284,
    OP_EQ = 285,
    OP_ROT = 286,
    OP_NOT = 287,
    OP_OR = 288,
    OP_AND = 289,
    OP_SHIFT_LEFT = 290,
    OP_SHIFT_RIGHT = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "decaf.y" /* yacc.c:1909  */

    char *id_t;
    int  num_t;
    char char_t;
    ExprList * exprList_t;
    ExprVector * exprvect_t;
    IdList * idList_t;
    GlobalIdList * gIdList_t;
    ParameterDefList * pdeflist_t;
    Expr * expr_t;
    Statement *statement_t;
    DataType type_t;

#line 105 "tokens.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
