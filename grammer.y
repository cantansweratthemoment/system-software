%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <getopt.h>
  #include "ast.h"
  #include "error.h"

  struct ast_node *root;
%}

%error-verbose

%union {
  struct ast_node* node;
}

/* declare tokens */
%token       <node> IDENT
%token      		ARRAY
%token      	    OF
%token       <node> AP
%token              SOP SCP OP CP
%left       <node> NOT MINUS
%left       <node> BIN_PLUS BIN_MUL BIN_DIV BIN_MOD BIN_LESS BIN_GREATER BIN_EQUALS
%left       <node> BIN_AND BIN_OR
%token      <node> TRUE FALSE STR CHAR HEX BIN DEC
%token             METHOD
%token             WHILE REPEAT DO BREAK UNTIL IF THEN ELSE
%token		       COLON
%token		       SEMICOLON
%token             COMMA
%token             VAR BEGINING END
%token      <node> TYPE
%type <node> source
%type <node> body_var
%type <node> body_item
%type <node> source_item
%type <node> list_var
%type <node> type_ref
%type <node> builtin
%type <node> custom
%type <node> array
%type <node> function_signature
%type <node> list_arg
%type <node> list_arg_item
%type <node> body
%type <node> statement
%type <node> if
%type <node> block
%type <node> while
%type <node> do
%type <node> break
%type <node> expr
%type <node> expression
%type <node> unary binary
%type <node> braces
%type <node> call
%type <node> indexer
%type <node> place
%type <node> literal
%type <node> list_expr
%type <node> call_list
%type <node> block_item

%start source

%%

source: 				    {$$ = root = NULL}
	| source source_item    {$$ = root = make_source($1, $2)}
	;

source_item: METHOD function_signature body {$$ = make_common_node("source_item", $2, $3)}
    | METHOD function_signature SEMICOLON   {$$ = make_common_node("source_item", $2, NULL)}
    ;

body: block                 {$$ = make_common_node("body", $1, NULL)}
    | VAR block             {$$ = make_common_node("body", $2, NULL)}
    | VAR body_var block    {$$ = make_common_node("body", $3, $2)}
    ;

body_var:                   {$$ = NULL}
    | body_var body_item    {$$ = make_common_node("body_var", $1, $2)}
    ;

body_item: list_var SEMICOLON             {$$ = make_common_node("body_item", $1, NULL)}
    | list_var COLON type_ref SEMICOLON   {$$ = make_common_node("body_item", $1, $3)}
    ;

list_var: IDENT COMMA list_var   {$$ = make_common_node("list", $1, $3)}
    | IDENT                      {$$ = make_common_node("list", $1, NULL)}
    ;

function_signature: IDENT OP list_arg CP 	    {$$ = make_function_signature($1, $3, NULL)}
	| IDENT OP list_arg CP COLON type_ref       {$$ = make_function_signature($1, $3, $6)}
 	;

list_arg: list_arg_item COMMA list_arg   {$$ = make_common_node("list", $1, $3)}
    | list_arg_item                      {$$ = make_common_node("list", $1, NULL)}
    ;

list_arg_item: IDENT         {$$ = make_common_node("list_item", $1, NULL)}
    | IDENT COLON type_ref   {$$ = make_common_node("list_item", $1, $3)}
    ;

type_ref: builtin   {$$ = $1}
    | custom        {$$ = $1}
    | array         {$$ = $1}
    ;

builtin:
    TYPE {$$ = $1}
    ;

custom:
    IDENT {$$ = $1}
    ;

array:
    ARRAY AP OF type_ref    {$$ = make_common_node("array", $2, $4)}
    ;

statement: if       {$$ = $1}
    | block         {$$ = $1}
    | while         {$$ = $1}
    | do            {$$ = $1}
    | break         {$$ = $1}
    | expression    {$$ = $1}
    ;

if: IF expr THEN statement                    {$$ = make_branch_node($2, $4, NULL)}
    | IF expr THEN statement ELSE statement   {$$ = make_branch_node($2, $4, $6)}
    ;

block: BEGINING END SEMICOLON                {$$ = make_block(NULL)}
    | BEGINING block_item END SEMICOLON      {$$ = make_block($2)}
    ;

block_item:                   {$$ = NULL}
    | block_item statement    {$$ = make_common_node("block_item", $1, $2)}
    ;

while:
    WHILE expr DO statement   {$$ = make_loop_node("while", $2, $4)}
    ;

do: REPEAT statement WHILE expr SEMICOLON    {$$ = make_loop_node("do-while", $2, $4)}
    | REPEAT statement UNTIL expr SEMICOLON  {$$ = make_loop_node("do-until", $2, $4)}
    ;

break: BREAK SEMICOLON        {$$ = make_common_node("break", NULL, NULL)}
    ;

expression: expr SEMICOLON    {$$ = $1}
    ;

expr: unary    {$$ = $1}
    | binary   {$$ = $1}
    | braces   {$$ = $1}
    | call     {$$ = $1}
    | indexer  {$$ = $1}
    | place    {$$ = $1}
    | literal  {$$ = $1}
    ;

unary: MINUS expr   {$$ = make_expr_node("MINUS", $2, NULL)}
    | NOT expr      {$$ = make_expr_node("NOT", $2, NULL)}
    ;

binary: expr COLON BIN_EQUALS expr    {$$ = make_expr_node("ASSIGMENT", $1, $4)}
    | expr BIN_PLUS expr              {$$ = make_expr_node("BIN_PLUS", $1, $3)}
    | expr MINUS expr                 {$$ = make_expr_node("MINUS", $1, $3)}
    | expr BIN_MUL expr               {$$ = make_expr_node("BIN_MUL", $1, $3)}
    | expr BIN_DIV expr               {$$ = make_expr_node("BIN_DIV", $1, $3)}
    | expr BIN_MOD expr               {$$ = make_expr_node("BIN_MOD", $1, $3)}
    | expr BIN_EQUALS BIN_EQUALS expr {$$ = make_expr_node("EQUALITY", $1, $4)}
    | expr NOT BIN_EQUALS expr        {$$ = make_expr_node("NOTEQUAL", $1, $4)}
    | expr BIN_LESS expr              {$$ = make_expr_node("BIN_LESS", $1, $3)}
    | expr BIN_GREATER expr           {$$ = make_expr_node("BIN_GREATER", $1, $3)}
    | expr BIN_AND expr               {$$ = make_expr_node("BIN_AND", $1, $3)}
    | expr BIN_OR expr                {$$ = make_expr_node("BIN_OR", $1, $3)}
    ;

braces: OP expr CP  {$$ = make_expr_node("BRACES", $2, NULL)}
    ;

call: IDENT OP call_list CP  {$$ = make_common_node("call", $1, $3)}
    ;

call_list:       {$$ = NULL}
    | list_expr  {$$ = make_common_node("list", $1, NULL)}
    ;

list_expr: expr COMMA list_expr   {$$ = make_common_node("expr", $1, $3)}
    | expr                        {$$ = make_common_node("expr", $1, NULL)}
    ;

indexer: expr SOP list_expr SCP {$$ = make_common_node("indexer", $1, $3)}
    ;

place: IDENT {$$ = $1}
    ;

literal: TRUE {$$ = $1}
    | FALSE   {$$ = $1}
    | STR     {$$ = $1}
    | CHAR    {$$ = $1}
    | HEX     {$$ = $1}
    | BIN     {$$ = $1}
    | DEC     {$$ = $1}
    ;
%%