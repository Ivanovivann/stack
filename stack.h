#ifndef SAS_STACK_H
#define SAS_STACK_H

#include <stdio.h>
#include <stdlib.h>

//===============================================================================================

#define BEGIN_CAPACITY 2
#define CANARY 0xDABADEDABADADABA
#define CANARY1 0xBBAADDDDEEAADDFF

typedef int type_of_stack;

typedef struct
{
    unsigned long long canary1;
    unsigned long long hash;
    void* data;
    unsigned size;
    unsigned capacity;
    unsigned long long canary2;
}Stack;

enum Stack_error
{
    no_errors,
    stack_nullptr,
    bad_size,
    no_free_memory,
    stack_is_empty,
    stack_canary_left_in_danger,
    stack_canary_right_in_danger,
    data_canary_left_in_danger,
    data_canary_right_in_danger,
    hash_error,
};

const type_of_stack poison = 0xBADDEAD;

//===============================================================================================

void fill_poison (Stack* stack, unsigned prev_capacity);

void* poison_realloc (Stack* stack, unsigned prev_capacity, unsigned capacity);

Stack_error construct_stack (Stack* stack);

Stack_error verificator (Stack* stack);

Stack_error push_stack (Stack* stack, type_of_stack value);

Stack_error pop_stack (Stack* stack, type_of_stack* value);

void dump_stack (Stack* stack);

void destruct_stack (Stack* stack);

void test_stack (Stack* stack);

unsigned long long make_hash (Stack* stack);

unsigned long long ROL (unsigned long long value);

unsigned long long ROR (unsigned long long value);

#endif
