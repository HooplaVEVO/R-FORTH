// int_stack.c

#include "int_stack.h"

#include <stdlib.h>
#include <stdio.h>

void int_stack_init(int_stack_t *stk, int capacity) {
    SLIST_INIT(&stk->head);
    stk->size = 0;
    stk->capacity = capacity;
}

int int_stack_push(int_stack_t *stk, int value) {
    if (stk->size >= stk->capacity) {
        printf("Stack is at full capacity.\n");
        return 0; // fail
    }

    int_entry_t *newEntry = malloc(sizeof(int_entry_t));
    if (newEntry) {
        newEntry->value = value;
        SLIST_INSERT_HEAD(&stk->head, newEntry, entries);
        stk->size++;
        return 1; //success
    }
    return 0; // fail
}

int int_stack_pop(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        int value = entry->value;
        SLIST_REMOVE_HEAD(&stk->head, entries);
        free(entry);
        stk->size--;
        *top_value = value;
        return 1; // success
    }
    return 0; // fail
}

int int_stack_top(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        *top_value = entry->value;
        return 1; // success
    }
    return 0; // fail
}

/* Functions for FORTH langauge stack operators */

int int_stack_dup(int_stack_t *stk) {
    if (stk->size < 1)
        return 0;
    int top_value;
    int_stack_top(stk, &top_value);
    return int_stack_push(stk, top_value); // success only if last operation succeeds
}

int int_stack_drop(int_stack_t *stk) {
    if (stk->size < 1)
        return 0;
    int top_value;
    return int_stack_pop(stk,&top_value);
}

int int_stack_swap(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value); // success only if last operation succeeds
}

int int_stack_over(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value); // success only if last operation succeeds
}

int int_stack_rot(int_stack_t *stk) {
    if (stk->size < 3)
        return 0;
    int top_value, second_value, third_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &second_value);
    int_stack_pop(stk, &third_value);
    int_stack_push(stk, second_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, third_value); // success only if last operation succeeds
}

int int_stack_2dup(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, next_to_top_value);
    int_stack_push(stk, top_value);
    int_stack_push(stk, next_to_top_value);
    return int_stack_push(stk, top_value); // success only if last operation succeeds
}

int int_stack_2drop(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    return int_stack_pop(stk, &next_to_top_value);
}

int int_stack_2swap(int_stack_t *stk) {
    if (stk->size < 4)
        return 0;
    int first_value, second_value, third_value, fourth_value;
    int_stack_pop(stk, &first_value);
    int_stack_pop(stk, &second_value);
    int_stack_pop(stk, &third_value);
    int_stack_pop(stk, &fourth_value);
    int_stack_push(stk, second_value);
    int_stack_push(stk, first_value);
    int_stack_push(stk, third_value);
    return int_stack_push(stk, fourth_value); // success only if last operation succeeds
}

int int_stack_2over(int_stack_t *stk) {
    if (stk->size < 4)
        return 0;
    int first_value, second_value, third_value, fourth_value;
    int_stack_pop(stk, &first_value);
    int_stack_pop(stk, &second_value);
    int_stack_pop(stk, &third_value);
    int_stack_pop(stk, &fourth_value);
    int_stack_push(stk, fourth_value);
    int_stack_push(stk, third_value);
    int_stack_push(stk, second_value);
    int_stack_push(stk, first_value);
    int_stack_push(stk, fourth_value);
    return int_stack_push(stk, third_value); // success only if last operation succeeds
}

/* Int operations */

int int_stack_add(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value + next_to_top_value);
}

int int_stack_sub(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value - next_to_top_value);
}

int int_stack_mul(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value * next_to_top_value);
}

int int_stack_div(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value / next_to_top_value);
}

void int_stack_print(int_stack_t *stk, FILE *file) {
    int_entry_t *entry;
    int pos = 0;
    if (stk->size == 0) {
        fprintf(file, "empty stack\n");
    }

    SLIST_FOREACH(entry, &stk->head, entries) {
        fprintf(file, "%d: %d\n", pos, entry->value);
        pos++;
    }
    printf("\n");
}

int int_stack_size(int_stack_t* stk) {
    return stk->size;
}

int int_stack_capacity(int_stack_t* stk) {
    return stk->capacity;
}

void int_stack_free(int_stack_t* stk){
    free(stk->size);
    free(stk->capacity);
    free(stk);
}