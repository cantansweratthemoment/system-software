#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "control_flow_graph.h"

int graph_counter = 0;

struct cfg_node *make_cfg_node(enum cfg_node_type type, struct operation_node *ot) {
    struct cfg_node *node = (struct cfg_node *) malloc(sizeof(struct cfg_node));
    if (node == NULL) {
        fprintf(stderr, "Node can not be created: allocation failed\n");
        exit(1);
    }
    node->id = graph_counter++;
    node->type = type;
    node->ot_root = ot;
    node->visited = false;
    return node;
}

struct cfg_node *make_common_cfg_node(char *dsc, struct cfg_node *next, struct operation_node *ot) {
    struct cfg_node *node = make_cfg_node(COMMON_CFG, ot);
    strncpy(node->desciption, dsc, MAXIMUM_IDENTIFIER_LENGTH);
    return node;
}

struct cfg_node *
make_loop_cfg_node(char *dsc, struct cfg_node *next_body, struct cfg_node *end, struct operation_node *ot) {
    struct cfg_node *node = make_cfg_node(LOOP_CFG, ot);
    strncpy(node->desciption, dsc, MAXIMUM_IDENTIFIER_LENGTH);
    node->cfg_loop.next_body = next_body;
    node->cfg_loop.end = end;
    return node;
}

struct cfg_node *
make_condition_cfg_node(char *dsc, struct cfg_node *then_block, struct cfg_node *else_block,
                        struct operation_node *ot) {
    struct cfg_node *node = make_cfg_node(CONDITION_CFG, ot);
    strncpy(node->desciption, dsc, MAXIMUM_IDENTIFIER_LENGTH);
    node->cfg_condition.then_block = then_block;
    node->cfg_condition.else_block = else_block;
    return node;
}

struct cfg_function *create_new_function(char *ident, struct cfg_node *root, struct cfg_function *next) {
    struct cfg_function *function = (struct cfg_function *) malloc(sizeof(struct cfg_function));
    strncpy(function->function_name, ident, MAXIMUM_IDENTIFIER_LENGTH);
    function->root_node = root;
    function->next = next;
    function->scope = create_scope(ident);
    return function;
}

struct cfg_function_list *create_function_list(struct cfg_function *init) {
    struct cfg_function_list *list = (struct cfg_function_list *) malloc(sizeof(struct cfg_function_list));
    list->list_root = init;
    list->list_tail = init;
    return list;
}

void list_push(struct cfg_function_list *list, struct cfg_function *function) {
    function->next = NULL;
    if (list->list_tail == NULL) {
        list->list_root = function;
    } else {
        list->list_tail->next = function;
    }
    list->list_tail = function;
}

struct cfg_node *find_last_in_loop(struct cfg_node *loop) {
    struct cfg_node *current = loop->cfg_loop.next_body;
    while (current != NULL) {
        if (current->next == NULL) {
            return current;
        }
        current = current->next;
    }
}

struct cfg_node *find_last_in_then(struct cfg_node *then) {
    struct cfg_node *current = then->cfg_condition.then_block;
    while (current != NULL) {
        if (current->next == NULL) {
            return current;
        }
        current = current->next;
    }
}

struct cfg_node *find_last_in_else(struct cfg_node *else_s) {
    struct cfg_node *current = else_s->cfg_condition.else_block;
    while (current != NULL) {
        if (current->next == NULL) {
            return current;
        }
        current = current->next;
    }
}

struct cfg_node *ast_dfs_cfg(struct cfg_node *,
                             struct ast_node *,
                             struct cfg_function_list *,
                             struct cfg_function *,
                             bool is_in_block,
                             bool);

void connect_next(struct cfg_node *last, struct cfg_node *current) {
    if (last == NULL) return;
    switch (last->type) {
        case COMMON_CFG: {
            last->next = current;
            break;
        }
        case LOOP_CFG: {
            if (last->cfg_loop.next_body == NULL) {
                last->cfg_loop.next_body = current;
                break;
            }
            last->cfg_loop.end = find_last_in_loop(last);
            last->cfg_loop.end->next = last;
            last->next = current;
            break;
        }
        case CONDITION_CFG: {
            if (last->cfg_condition.then_block == NULL) {
                last->cfg_condition.then_block = current;
                break;
            }
            if (last->cfg_condition.else_block == NULL) {
                last->cfg_condition.else_block = current;
                break;
            }
            find_last_in_then(last)->next = current;
            find_last_in_else(last)->next = current;
            last->next = current;
            break;
        }
        default:
            break;
    }
}

struct cfg_node *process_common_ast_node(struct cfg_node *cfg_node,
                                         struct ast_node *node,
                                         struct cfg_function_list *list,
                                         struct cfg_function *current_function) {
    if (!strcmp(node->ast_common.node_name, "block_item")) {
        struct ast_node *current = node;
        struct ast_node *left = NULL;
        struct cfg_node *cfg_node_c = cfg_node;
        do {
            left = current->ast_common.left;
            struct cfg_node *statement = ast_dfs_cfg(cfg_node_c,
                                                     current->ast_common.right,
                                                     list,
                                                     current_function,
                                                     true, true);
            connect_next(cfg_node_c, statement);
            cfg_node_c = statement;
            current = left;
        } while (current != NULL);

    } else {
        ast_dfs_cfg(cfg_node, node->ast_common.left, list, current_function, false, true);
        ast_dfs_cfg(cfg_node, node->ast_common.right, list, current_function, false, true);
    }
}

struct operation_node *create_ot(char *oper, struct ast_node *node) {
    if (node == NULL) return NULL;
    switch (node->type) {
        case EXPR: {
            struct operation_node *left;
            struct operation_node *right;
            if (!strcmp(node->ast_expression.oper_name, "rb")) {
                left = create_ot("WRITE_IDENT", node->ast_expression.left);
                right = create_ot("", node->ast_expression.right);
            } else if (!strcmp(node->ast_expression.oper_name, "wb")) {
                left = create_ot("READ_IDENT", node->ast_expression.left);
                right = create_ot("", node->ast_expression.right);
            } else {
                left = create_ot("", node->ast_expression.left);
                right = create_ot("", node->ast_expression.right);
            }
            bool v1 = false;
            bool v2 = false;
            if (node->ast_expression.right && node->ast_expression.right->type == IDENTIFIER) v2 = true;
            if (node->ast_expression.left && node->ast_expression.left->type == IDENTIFIER) v1 = true;
            return create_operation_node(node->ast_expression.oper_name, left, right, v1, v2, true, false);
        }
        case ASS: {
            struct operation_node *left = create_ot("WRITE_IDENT", node->ast_ass.left);
            struct operation_node *right = create_ot("READ", node->ast_ass.right);
            bool v2 = false;
            if (node->ast_ass.right->type == IDENTIFIER) v2 = true;
            return create_operation_node("ASSIGMENT", right, left, true, v2, true, false);
        }
        case IDENTIFIER: {
            if (!strcmp(oper, "WRITE_IDENT")) {
                return create_operation_node_leaf(oper, node->ast_identifier.name, NULL, true, NULL);
            }
            if (!strcmp(oper, "READ_FNC")) {
                return create_operation_node_leaf("READ_FNC", node->ast_identifier.name, NULL, false, NULL);
            }
            return create_operation_node_leaf("READ_IDENT", node->ast_identifier.name, NULL, true, NULL);
        }
        case VALUE: {
            return create_operation_node_leaf("PUSH_VLE", node->ast_value.value, NULL, false, NULL);
        }
        case COMMON: {
            if (!strcmp(node->ast_common.node_name, "indexer")) {
                struct operation_node *left = create_ot("READ", node->ast_common.left);
                struct operation_node *right = create_ot("READ", node->ast_common.right);
                bool v2 = false;
                if (node->ast_common.right
                    && node->ast_common.right->ast_common.left
                    && node->ast_common.right->ast_common.left->type == IDENTIFIER)
                    v2 = true;
                if (!strcmp(oper, "WRITE_IDENT")) {
                    return create_operation_node("WRITE_BY_ADDRESS", left, right, true, v2, false, true);
                }
                return create_operation_node("READ_BY_ADDRESS", left, right, true, v2, false, true);
            } else if (node->ast_common.left->type == VALUE) {
                return create_ot("", node->ast_common.left);
            } else if (strcmp(node->ast_common.node_name, "call_list") && node->ast_common.left->type == IDENTIFIER) {
                return create_ot("", node->ast_common.left);
            } else {
                struct operation_node *left = create_ot("READ_IDENT", node->ast_common.left);
                struct operation_node *right = NULL;
                if (node->ast_common.right != NULL) {
                    right = create_ot("READ", node->ast_common.right);
                }
                bool v1 = false;
                bool v2 = false;
                if (node->ast_common.right && node->ast_common.right->type == IDENTIFIER) v2 = true;
                if (node->ast_common.left && node->ast_common.left->type == IDENTIFIER) v1 = true;
                return create_operation_node("READ_LIST", left, right, v1, v2, true, false);
            }
        }
        default:
            break;
    }
}

struct cfg_node *ast_dfs_cfg(struct cfg_node *cfg_node,
                             struct ast_node *node,
                             struct cfg_function_list *list,
                             struct cfg_function *current_function,
                             bool is_in_block,
                             bool need_connect) {
    if (node == NULL) return NULL;
    struct cfg_node *cfg_node_next = NULL;
    switch (node->type) {
        case EXPR: {
            struct operation_node *node2 = create_ot(NULL, node);
            cfg_node_next = make_common_cfg_node("expression", NULL, node2);
            if (!is_in_block && need_connect) {
                connect_next(cfg_node, cfg_node_next);
            }
            if (node->ast_expression.right && node->ast_expression.right->type == COMMON) {
                if (!strcmp(node->ast_expression.right->ast_common.node_name, "indexer")) {
                    ast_dfs_cfg(cfg_node, node->ast_expression.right, list, current_function, false, true);
                }
            }
            if (node->ast_expression.left && node->ast_expression.left->type == COMMON) {
                if (!strcmp(node->ast_expression.left->ast_common.node_name, "indexer")) {
                    ast_dfs_cfg(cfg_node, node->ast_expression.left, list, current_function, false, true);
                }
            }
            break;
        }
        case ASS: {
            struct operation_node *node2 = create_ot(NULL, node);
            cfg_node_next = make_common_cfg_node("assigment", NULL, node2);
            if (!is_in_block) {
                connect_next(cfg_node, cfg_node_next);
            }
            if (node->ast_ass.right->type == COMMON) {
                if (!strcmp(node->ast_ass.right->ast_common.node_name, "indexer")) {
                    ast_dfs_cfg(cfg_node, node->ast_ass.right, list, current_function, false, true);
                }
            }
            if (node->ast_ass.left->type == COMMON) {
                if (!strcmp(node->ast_ass.left->ast_common.node_name, "indexer")) {
                    ast_dfs_cfg(cfg_node, node->ast_ass.left, list, current_function, false, true);
                }
            }
            break;
        }
        case SOURCE: {
            ast_dfs_cfg(cfg_node, node->ast_source.source, list, current_function, false, true);
            ast_dfs_cfg(cfg_node, node->ast_source.source_item, list, current_function, false, true);
            break;
        }
        case BRANCH: {
            cfg_node_next = make_condition_cfg_node("if", NULL, NULL, NULL);
            if (!is_in_block) {
                connect_next(cfg_node, cfg_node_next);
            }
            ast_dfs_cfg(cfg_node_next, node->ast_branch.if_statement, list, current_function, false, true);
            ast_dfs_cfg(cfg_node_next, node->ast_branch.else_statement, list, current_function, false, true);
            cfg_node_next->ot_root = create_ot(NULL, node->ast_branch.if_expr);
            break;
        }
        case BLOCK: {
            ast_dfs_cfg(cfg_node, node->ast_block.block_items, list, current_function, false, true);
            break;
        }
        case LOOP: {
            cfg_node_next = make_loop_cfg_node(node->ast_loop.loop_type, NULL, NULL, NULL);
            if (!is_in_block) {
                connect_next(cfg_node, cfg_node_next);
            }
            ast_dfs_cfg(cfg_node_next, node->ast_loop.statement, list, current_function,
                        false, true);
            struct cfg_node *expression = ast_dfs_cfg(cfg_node_next, node->ast_loop.expression, list, current_function,
                                                      false, false);
            cfg_node_next->ot_root = expression->ot_root;
            break;
        }
        case COMMON: {
            if (!strcmp(node->ast_common.node_name, "list_var")) {
                struct variable_list_node *variable_s = create_new_variable(node->ast_common.left->ast_identifier.name,
                                                                            LONG,
                                                                            current_function->scope->offset_counter,
                                                                            NULL);

                v_list_push(current_function->scope->list, variable_s);
                current_function->scope->offset_counter++;
            }
            process_common_ast_node(cfg_node, node, list, current_function);
            break;
        }
        default:
            break;
    }

    return cfg_node_next;
}

struct cfg_function_list *build_cfg(struct ast_node *root) {
    struct cfg_function_list *list = create_function_list(NULL);
    ast_dfs_cfg(NULL, root, list, NULL, false, true);
    return list;
}


void print_ot(struct operation_node *node) {
    if (node == NULL) return;
    if (strcmp(node->type, "NULL")) {
        printf(" %s ", node->type);
    }
    if (!node->is_left) {
        printf("%s", node->left_operand);
    } else {
        print_ot(node->left_next);
    }
    if (strcmp(node->type, "NULL")) {
        printf(" %s ", node->type);
    }
    if (!node->is_right) {
        printf("%s", node->right_operand);
    } else {
        print_ot(node->right_next);
    }
}

void print_cfg_node(struct cfg_node *left, struct cfg_node *right) {
    if (left == NULL || right == NULL) return;
    printf("\"value: %s, id: %llu", left->desciption, left->id);
    printf(", ot: ");
    print_ot(left->ot_root);
    printf("\"");
    printf(" -> ");
    printf("\"value: %s, id: %llu", right->desciption, right->id);
    printf(", ot: ");
    print_ot(right->ot_root);
    printf("\";\n");

}

void dfs_cfg_print(struct cfg_node *node) {
    if (node == NULL) return;
    node->visited = true;
    switch (node->type) {
        case COMMON_CFG: {
            if (node->next != NULL) {
                print_cfg_node(node, node->next);
                if (!node->next->visited) {
                    dfs_cfg_print(node->next);
                }
            }
            break;
        }
        case CONDITION_CFG: {
            if (node->cfg_condition.then_block != NULL) {
                print_cfg_node(node, node->cfg_condition.then_block);
                if (!node->cfg_condition.then_block->visited) {
                    dfs_cfg_print(node->cfg_condition.then_block);
                }
            }

            if (node->cfg_condition.else_block != NULL) {
                print_cfg_node(node, node->cfg_condition.else_block);
                if (!node->cfg_condition.else_block->visited) {
                    dfs_cfg_print(node->cfg_condition.else_block);
                }
            }
            break;
        }
        case LOOP_CFG: {
            if (node->cfg_loop.next_body != NULL) {
                print_cfg_node(node, node->cfg_loop.next_body);
                if (!node->cfg_loop.next_body->visited) {
                    dfs_cfg_print(node->cfg_loop.next_body);
                }
            }
            if (node->next != NULL) {
                print_cfg_node(node, node->next);
                if (!node->next->visited) {
                    dfs_cfg_print(node->next);
                }
            }
            break;
        }
        default:
            break;
    }
}


void print_functions(struct cfg_function_list *list, bool need) {
    struct cfg_function *current = list->list_root;
    printf("digraph G {\n");
    int sub_id = 1;
    while (current != NULL) {
        printf("subgraph ");
        printf("%d", sub_id++);
        printf(" {\n");
        printf("node [shape=egg, fillcolor=aquamarine, style=\"filled\"];\n");
        dfs_cfg_print(current->root_node);
        printf("}\n");
        current = current->next;
    }
    printf("}\n");
}