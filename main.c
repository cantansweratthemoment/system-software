#include <stdio.h>
#include "structures/abstract_syntax_tree.h"
#include "structures/control_flow_graph.h"


int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *input_file = fopen(argv[1], "r");
        if (input_file) {
            struct ast_node *root = build_ast(input_file);
            if (strcmp(argv[2], "ast")) {
                struct cfg_function_list *j = build_cfg(root);
                print_functions(j);
            } else {
                print_ast(root);
            }
            fclose(input_file);
        } else {
            printf("File can not be open: %s\n", argv[1]);
        }
    } else {
        printf("Usage: %s input_file\n", argv[0]);
    }
    return 0;
}