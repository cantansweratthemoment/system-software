#ifndef SYSTEM_SOFTWARE_OPERATION_TREE_H
#define SYSTEM_SOFTWARE_OPERATION_TREE_H
#define MAXIMUM_IDENTIFIER_LENGTH 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct operation_node {
    int id;
    char type[MAXIMUM_IDENTIFIER_LENGTH];
    bool is_left;
    bool is_right;
    union {
        char left_operand[MAXIMUM_IDENTIFIER_LENGTH];
        struct operation_node *left_next;
    };
    union {
        char right_operand[MAXIMUM_IDENTIFIER_LENGTH];
        struct operation_node *right_next;
    };
};

struct operation_node *create_operation_node(char *, struct operation_node *, struct operation_node *);

struct operation_node *create_operation_node_leaf(char *, char *, char *);

#endif //SYSTEM_SOFTWARE_OPERATION_TREE_H
