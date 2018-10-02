#include "stack.h"

stack_t *stack_create(void) {
    return (stack_t *)calloc(1, sizeof(stack_t));
}

void stack_push(stack_t *stack, void *val) {
    stack_elem_t* new_elem = (stack_elem_t *)malloc(sizeof(stack_elem_t));
    new_elem->value = val;
    new_elem->next = stack->top;
    stack->top = new_elem;
}

void *stack_pop(stack_t *stack) {
    if (!stack) { return NULL; }
    void *val = NULL;
    stack_elem_t *top_frame = stack->top;
    if (top_frame) {
        val = top_frame->value;
        stack->top = top_frame->next;
        free(top_frame);
    } else {
        stack->top = NULL; 
    } 
    return val;
}

void *stack_peek(stack_t *stack) {
    if (!stack || !stack->top) { return NULL; }
    return stack->top->value;
}

void stack_destroy(stack_t *stack) {
    stack_elem_t *current_frame = stack->top;
    while (current_frame) {
        stack_elem_t *next = current_frame->next;
        free(current_frame);
        current_frame = next;
    }
    free(stack); 
}

void stack_destroy_with_elements(stack_t *stack) {
    stack_elem_t *current_frame = stack->top;
    while (current_frame) {
        stack_elem_t *next = current_frame->next;
        free(current_frame->value);
        free(current_frame);
        current_frame = next;
    }
    free(stack);
}
