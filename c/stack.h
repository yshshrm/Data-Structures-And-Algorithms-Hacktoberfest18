#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack_elem {
    void *value;
    struct stack_elem *next;
} stack_elem_t;

typedef struct {
    stack_elem_t *top;
} stack_t;

stack_t *stack_create(void);

void stack_push(stack_t *stack, void *val);

void *stack_pop(stack_t *stack);

void *stack_peek(stack_t *stack);

/* 
 * Free all elements on the stack and the stack itself.
 * This doesn't free the references on the stack;
 */
void stack_destroy(stack_t *stack);

/* 
 * Free all elements on the stack, the items refered to on the stack
 * and the stack itself.
 */
void stack_destroy_with_elements(stack_t *stack);

#endif 
