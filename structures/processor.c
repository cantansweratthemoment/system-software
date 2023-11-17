#include "processor.h"
#include <time.h>
#include <stdlib.h>

unsigned int ot_dfs(struct operation_node *node, struct scope *scope) {
    if (node == NULL) return 0;
    if (!strcmp(node->type, "jmp")) {
        printf("prcall\n", node->type);
        ot_dfs(node->right_next, scope);
        printf("jmp %s\n", node->left_next->left_operand);
        return 0;
    }
    char *command = malloc(sizeof(char) * 32);
    if (node->is_expression && !strcmp(node->type, "rb")) {
        printf("%s\n", node->type);
    }
    if (node->is_expression && node->is_left) {
        ot_dfs(node->left_next, scope);
    }
    if (node->is_expression && node->is_right) {
        ot_dfs(node->right_next, scope);
    }
    command = strcat(command, node->type);
    if (strcmp(command, "ASSIGMENT")
        && strcmp(command, "READ_LIST")
        && strcmp(command, "rb")
        && strcmp(command, "return")) {
        printf("%s\n", command);
    }
}

struct value_placer *create_value_placer(char *name, enum masks type, unsigned int offset) {
    struct value_placer *node = (struct value_placer *) malloc(sizeof(struct value_placer));
    if (node == NULL) {
        fprintf(stderr, "Node can not be created: allocation failed\n");
        exit(1);
    }
    node->is_custom = 0;
    node->is_array = 0;
    strncpy(node->name, name, 1024);
    node->offset = offset;
    node->type = type;
    return node;
}

struct value_placer *create_value_placer_array(char *name, enum masks type, unsigned int offset_s) {
    struct value_placer *node = (struct value_placer *) malloc(sizeof(struct value_placer));
    struct array *array = (struct array *) malloc(sizeof(struct array));
    if (node == NULL) {
        fprintf(stderr, "Node can not be created: allocation failed\n");
        exit(1);
    }
    array->offset_start = offset_s;
    node->is_custom = 0;
    node->is_array = 1;
    strncpy(node->name, name, MAXIMUM_IDENTIFIER_LENGTH);
    node->array = array;
    node->type = type;
    return node;
}

struct variable_list_node *
create_new_variable(char *name, enum masks type, unsigned int offset, struct variable_list_node *next) {
    struct variable_list_node *node = (struct variable_list_node *) malloc(sizeof(struct variable_list_node));
    node->placer = create_value_placer(name, type, offset);
    node->next = next;
    return node;
}

struct variable_list_node *variable_search(struct variable_list *list, char *name) {
    if (list == NULL) return NULL;
    if (list->list_root == NULL) return NULL;
    struct variable_list_node *current = list->list_root;
    while (strcmp(current->placer->name, name)) {
        current = current->next;
        if (current == NULL) return NULL;
    }
    if (strcmp(current->placer->name, name)) {
        return NULL;
    }
    return current;
}

struct scope *create_scope(char *name) {
    struct scope *node = (struct scope *) malloc(sizeof(struct scope));
    strncpy(node->function_name, name, MAXIMUM_IDENTIFIER_LENGTH);
    node->offset_counter = 0;
    node->list = NULL;
    return node;
}

void process_condition(int level, int uuid) {
    char *bff1 = malloc(sizeof(char) * 32);
    for (int i = 0; i < level; i++) {
        bff1 = strcat(bff1, ".");
    }
    char str[55];
    sprintf(str, "else_block%d\n", uuid);
    bff1 = strcat(bff1, str);
    printf("jmpiz %s", bff1);
    free(bff1);
}

void process_loop(int level) {
    char *bff = malloc(sizeof(char) * 32);
    char *bff1 = malloc(sizeof(char) * 32);
    for (int i = 0; i < level; i++) {
        bff = strcat(bff, "\t");
        bff1 = strcat(bff1, ".");
    }
    bff1 = strcat(bff1, "end\n");
    printf("%sjmpinz %s", bff, bff1);
    free(bff);
    free(bff1);
}