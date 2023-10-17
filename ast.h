#ifndef _AST_H_
#define _AST_H_

#include <stdbool.h>

#define MAXIMUM_IDENTIFIER_LENGTH 1024

enum ast_node_type {
    COMMON,
    EXPR,
    SOURCE,
    FUNC_SIGN,
    BRANCH,
    BLOCK,
    LOOP,
    TYPE_NODE,
    VALUE,
    IDENTIFIER
};


static const char *ast_names[] = {
        [COMMON] = "common",
        [EXPR] = "expression",
        [SOURCE] = "source",
        [FUNC_SIGN] = "function_signature",
        [BRANCH] = "branch",
        [BLOCK] = "block",
        [LOOP] = "loop",
        [TYPE_NODE] = "type",
        [VALUE] = "value",
        [IDENTIFIER] = "identifier"
};

struct ast_node;

struct ast_expression {
    char oper_name[MAXIMUM_IDENTIFIER_LENGTH];
    struct ast_node *left;
    struct ast_node *right;
};

struct ast_common {
    char node_name[MAXIMUM_IDENTIFIER_LENGTH];
    struct ast_node *left;
    struct ast_node *right;
};

struct ast_loop {
    char loop_type[MAXIMUM_IDENTIFIER_LENGTH];
    struct ast_node *statement;
    struct ast_node *expression;
};

struct ast_block {
    struct ast_node *block_items;
};

struct ast_branch {
    struct ast_node *if_expr;
    struct ast_node *if_statement;
    struct ast_node *else_statement;
};

struct ast_function_signature {
    struct ast_node *ident;
    struct ast_node *args;
    struct ast_node *type_ref;
};

struct ast_source {
    struct ast_node *source;
    struct ast_node *source_item;
};

struct ast_value {
    char type_name[MAXIMUM_IDENTIFIER_LENGTH];
    char value[MAXIMUM_IDENTIFIER_LENGTH];
};

struct ast_type {
    char type_name[MAXIMUM_IDENTIFIER_LENGTH];
};

struct ast_identifier {
    char name[MAXIMUM_IDENTIFIER_LENGTH];
};

struct ast_node {
    enum ast_node_type type;
    unsigned long long id;
    union {
        struct ast_expression ast_expression;
        struct ast_source ast_source;
        struct ast_function_signature ast_function_signature;
        struct ast_branch ast_branch;
        struct ast_block ast_block;
        struct ast_loop ast_loop;
        struct ast_common ast_common;
        struct ast_type ast_type;
        struct ast_value ast_value;
        struct ast_identifier ast_identifier;
    };
};

struct ast_node *make_common_node(char *, struct ast_node *, struct ast_node *);

struct ast_node *make_expr_node(char *, struct ast_node *, struct ast_node *);

struct ast_node *make_loop_node(char *, struct ast_node *, struct ast_node *);

struct ast_node *make_branch_node(struct ast_node *, struct ast_node *, struct ast_node *);

struct ast_node *make_block(struct ast_node *);

struct ast_node *make_function_signature(struct ast_node *, struct ast_node *, struct ast_node *);

struct ast_node *make_source(struct ast_node *, struct ast_node *);

struct ast_node *make_value_node(char *, char *);

struct ast_node *make_type_node(char *);

struct ast_node *make_ident_node(char *);

void print_ast(struct ast_node *);

#endif // _AST_H_