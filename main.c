#include <stdio.h>
#include "grammer.tab.h"
#include "ast.h"

extern int yyparse();
extern FILE *yyin;
extern struct ast_node *root;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *input_file = fopen(argv[1], "r");
        if (input_file) {
            yyin = input_file;
            yyparse();
            print_ast(root);
            fclose(input_file);
        } else {
            printf("File can not be open: %s\n", argv[1]);
        }
    } else {
        printf("Usage: %s input_file\n", argv[0]);
    }
    return 0;
}