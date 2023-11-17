#include <stdio.h>
#include "structures/abstract_syntax_tree.h"
#include "structures/control_flow_graph.h"
#include <time.h>
#include <stdlib.h>

extern int yyparse();

extern FILE *yyin;
extern struct ast_node *root;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc > 0) {
        FILE *input_file = fopen("../test.pas", "r");
        if (input_file) {
            yyin = input_file;
            yyparse();
            struct cfg_function_list *j = build_cfg(root);
            print_functions(j, false);
            fclose(input_file);
        } else {
            printf("File can not be open: %s\n", argv[1]);
        }
    } else {
        printf("Usage: %s input_file\n", argv[0]);
    }
    return 0;
}