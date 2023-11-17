#ifndef SYSTEM_SOFTWARE_PROCESSOR_H
#define SYSTEM_SOFTWARE_PROCESSOR_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "control_flow_graph.h"

enum masks {
    INT,
    LONG,
    BYTE,
    BOOL,
    CHAR
};

enum addressation {
    STRCT_VL,
    STRCT_OFF,
    OFF,
    VL
};

struct array {
    unsigned int offset_start;
};

struct value_placer {
    char name[MAXIMUM_IDENTIFIER_LENGTH];
    enum masks type;
    bool is_custom;
    bool is_array;
    union {
        unsigned int offset;
        struct array *array;
    };
};

static const char *addressation_mnm[] = {
        [STRCT_VL] = "sv",
        [STRCT_OFF] = "so",
        [OFF] = "o",
        [VL] = ""
};

static const uint16_t masks[] = {
        [INT] = 0x0fff,
        [LONG] = 0xffff,
        [BYTE] = 0x00ff,
        [CHAR] = 0x00ff,
        [BOOL] = 0x0001
};

static const int types_s[] = {
        [INT] = 12,
        [LONG] = 16,
        [BYTE] = 8,
        [CHAR] = 8,
        [BOOL] = 1
};

struct variable_list_node {
    struct value_placer *placer;
    struct variable_list_node *next;
};

struct scope {
    char function_name[MAXIMUM_IDENTIFIER_LENGTH];
    unsigned int offset_counter;
    struct variable_list *list;
};

unsigned int ot_dfs(struct operation_node *node, struct scope *scope);

void process_condition(int level, int);

void process_call(struct cfg_node *node);

void process_loop(int level);

struct value_placer *create_value_placer(char *name, enum masks type, unsigned int offset);

struct variable_list_node *
create_new_variable(char *, enum masks type, unsigned int offset, struct variable_list_node *);

void v_list_push(struct variable_list *, struct variable_list_node *);

struct variable_list_node *variable_search(struct variable_list *, char *);

struct scope *create_scope(char *name);

#endif
