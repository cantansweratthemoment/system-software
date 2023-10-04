/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     ARRAY = 259,
     OF = 260,
     AP = 261,
     SOP = 262,
     SCP = 263,
     OP = 264,
     CP = 265,
     MINUS = 266,
     NOT = 267,
     BIN_EQUALS = 268,
     BIN_GREATER = 269,
     BIN_LESS = 270,
     BIN_MOD = 271,
     BIN_DIV = 272,
     BIN_MUL = 273,
     BIN_PLUS = 274,
     BIN_OR = 275,
     BIN_AND = 276,
     TRUE = 277,
     FALSE = 278,
     STR = 279,
     CHAR = 280,
     HEX = 281,
     BIN = 282,
     DEC = 283,
     METHOD = 284,
     WHILE = 285,
     REPEAT = 286,
     DO = 287,
     BREAK = 288,
     UNTIL = 289,
     IF = 290,
     THEN = 291,
     ELSE = 292,
     COLON = 293,
     SEMICOLON = 294,
     COMMA = 295,
     VAR = 296,
     BEGINING = 297,
     END = 298,
     TYPE = 299
   };
#endif
/* Tokens.  */
#define IDENT 258
#define ARRAY 259
#define OF 260
#define AP 261
#define SOP 262
#define SCP 263
#define OP 264
#define CP 265
#define MINUS 266
#define NOT 267
#define BIN_EQUALS 268
#define BIN_GREATER 269
#define BIN_LESS 270
#define BIN_MOD 271
#define BIN_DIV 272
#define BIN_MUL 273
#define BIN_PLUS 274
#define BIN_OR 275
#define BIN_AND 276
#define TRUE 277
#define FALSE 278
#define STR 279
#define CHAR 280
#define HEX 281
#define BIN 282
#define DEC 283
#define METHOD 284
#define WHILE 285
#define REPEAT 286
#define DO 287
#define BREAK 288
#define UNTIL 289
#define IF 290
#define THEN 291
#define ELSE 292
#define COLON 293
#define SEMICOLON 294
#define COMMA 295
#define VAR 296
#define BEGINING 297
#define END 298
#define TYPE 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "grammer.y"
{
  struct ast_node* node;
}
/* Line 1529 of yacc.c.  */
#line 141 "grammer.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

