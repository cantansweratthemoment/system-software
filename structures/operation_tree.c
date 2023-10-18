#include "operation_tree.h"

int list_counter = 0;

struct operation_node *make_list_node(char *type) {
    struct operation_node *node = (struct list_node *) malloc(sizeof(struct operation_node));
    node->id = list_counter++;
    strncpy(node->type, type, MAXIMUM_IDENTIFIER_LENGTH);
    return node;
}

struct operation_node *create_operation_node(char *type, struct operation_node *left, struct operation_node *right) {
    struct operation_node *node = make_list_node(type);
    strncpy(node->type, type, MAXIMUM_IDENTIFIER_LENGTH);
    node->left_next = left;
    node->right_next = right;
    node->is_left = true;
    node->is_right = true;
    return node;
}

struct operation_node *create_operation_node_leaf(char *type, char *left, char *right) {
    struct operation_node *node = make_list_node(type);
    strncpy(node->left_operand, left, MAXIMUM_IDENTIFIER_LENGTH);
    if (right != NULL) {
        strncpy(node->right_operand, right, MAXIMUM_IDENTIFIER_LENGTH);
    }
    strncpy(node->type, type, MAXIMUM_IDENTIFIER_LENGTH);
    node->is_left = false;
    node->is_right = false;
    return node;
}