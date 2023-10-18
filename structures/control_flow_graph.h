#ifndef SYSTEM_SOFTWARE_CONTROL_FLOW_GRAPH_H
#define SYSTEM_SOFTWARE_CONTROL_FLOW_GRAPH_H
#define MAXIMUM_IDENTIFIER_LENGTH 1024

#include "operation_tree.h"
#include "abstract_syntax_tree.h"

enum cfg_node_type {
    COMMON_CFG,
    LOOP_CFG,
    CONDITION_CFG
};

struct cfg_common {
};

struct cfg_loop {
    struct cfg_node *next_body;
    struct cfg_node *end;
};

struct cfg_condition {
    struct cfg_node *then_block;
    struct cfg_node *else_block;
};

struct cfg_node {
    char desciption[MAXIMUM_IDENTIFIER_LENGTH];
    enum cfg_node_type type;
    unsigned long long id;
    struct cfg_node *next;
    struct operation_node *ot_root;
    union {
        struct cfg_common cfg_common;
        struct cfg_loop cfg_loop;
        struct cfg_condition cfg_condition;
    };
};

struct cfg_function {
    char function_name[MAXIMUM_IDENTIFIER_LENGTH];
    struct cfg_node *root_node;
    struct cfg_function *next;
};

struct cfg_function_list {
    struct cfg_function *list_root;
    struct cfg_function *list_tail;
};

struct cfg_node *make_common_cfg_node(char *, struct cfg_node *, struct operation_node *);

struct cfg_node *make_loop_cfg_node(char *, struct cfg_node *, struct cfg_node *, struct operation_node *);

struct cfg_node *make_condition_cfg_node(char *, struct cfg_node *, struct cfg_node *, struct operation_node *);

struct cfg_function *create_new_function(char *, struct cfg_node *, struct cfg_function *);

struct cfg_function_list *create_function_list(struct cfg_function *);

void list_push(struct cfg_function_list *, struct cfg_function *);

struct cfg_function_list *build_cfg(struct ast_node *);

void print_functions(struct cfg_function_list *);

#endif //SYSTEM_SOFTWARE_CONTROL_FLOW_GRAPH_H
