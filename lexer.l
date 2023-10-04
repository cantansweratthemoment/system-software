%{
#include "error.h"
#include "ast.h"
#include "grammer.tab.h"
#include <string.h>
%}

%%

[0-9]+ {
    yylval.node = make_value_node("DEC", yytext);
    return DEC;
}

\"[^\"\\]*(?:\\.[^\"\\]*)*\" {
    char buffer[1024];
    strncpy(buffer, yytext+1, strlen(yytext)-2);
    buffer[strlen(buffer)-1] = 0;
    yylval.node = make_value_node("STR", buffer);
    return STR;
}
'[^']' {
    char buffer[1];
    strncpy(buffer, yytext+1, 1);
    yylval.node = make_value_node("CHAR", buffer);
    return CHAR;
}
\[,*\] {
    yylval.node = make_value_node("AP", yytext);
    return AP;
}

0[xX][0-9A-Fa-f]+ {
    char* buffer = malloc(256);
    sprintf(buffer, "%d", strtol(yytext + 2, NULL, 16));
    yylval.node = make_value_node("HEX", buffer);
    return HEX;
}

0[bB][01]+ {
    char* buffer = malloc(256);
    sprintf(buffer, "%d", strtol(yytext + 2, NULL, 2));
    yylval.node = make_value_node("BIN", buffer);
    return BIN;
}

"byte" {
           yylval.node = make_type_node(yytext);
           return TYPE;
       }
"int" {
          yylval.node = make_type_node(yytext);
          return TYPE;
      }
"uint" {
           yylval.node = make_type_node(yytext);
           return TYPE;
       }
"long" {
           yylval.node = make_type_node(yytext);
           return TYPE;
       }
"bool" {
           yylval.node = make_type_node(yytext);
           return TYPE;
       }
"ulong" {
            yylval.node = make_type_node(yytext);
            return TYPE;
        }
"char" {
           yylval.node = make_type_node(yytext);
           return TYPE;
       }
"string"  {
              yylval.node = make_type_node(yytext);
              return TYPE;
          }

"method"                            { return METHOD; }

"begin"                             { return BEGINING; }

"end"                               { return END; }

"var"                               { return VAR; }

"if"                                { return IF; }

"then"                              { return THEN; }

"else"                              { return ELSE; }

"do"                                { return DO; }

"while"                             { return WHILE; }

"repeat"                            { return REPEAT; }

"until"                             { return UNTIL; }

"break"                             { return BREAK; }

"array"                             { return ARRAY; }

"of"                                { return OF; }

"["                                 { return SOP; }

"]"                                 { return SCP; }

"true"                              {
 yylval.node = make_value_node("BOOL", "true");
 return TRUE;
 }

"false"                             {
 yylval.node = make_value_node("BOOL", "false");
 return FALSE;
 }

"%"                                 {
 return BIN_MOD;
 }

";"                                 {
 return SEMICOLON;
 }

":"                                 {
 return COLON;
 }

","                                 {
 return COMMA;
 }

"!"                                 {
 return NOT;
 }

"\|\|"                              {
 return BIN_OR;
 }

"&&"                                {
 return BIN_AND;
 }

"+"                                 {
 return BIN_PLUS;
 }

"-"                                 {
 return MINUS;
 }

"<"                                {
 return BIN_LESS;
 }

">"                                {
 return BIN_GREATER;
 }

"*"                                 {
 return BIN_MUL;
 }

"("                                 {
 return OP;
 }

")"                                 {
 return CP;
 }

"="                                 {
 return BIN_EQUALS;
 }

[a-zA-Z_][a-zA-Z_0-9]* {
    yylval.node = make_ident_node(yytext);
    return IDENT;
}

\/\/.*                              { /* Пропустить комментарии */ }
\n                                  { /* Пропустить переводы строк */ }
[ \t]                               { /* Пропустить пробелы и табуляцию */ }
.                                   {
                                        // Обработка нераспознанных символов или ошибок
                                        fprintf(stderr, "Нераспознанный символ: %s\n", yytext);
                                    }
%%

int yywrap() {
    // Your implementation here, typically returning 1 to signal EOF.
    return 1;
}