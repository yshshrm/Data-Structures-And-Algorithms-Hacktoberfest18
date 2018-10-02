#include "queue.h"

#include <stdlib.h>
#include <assert.h>


queue_t *queue_create(void) {
    return (queue_t *)calloc(sizeof(queue_t), 1);
}

// Elements get inserted at the end
void enqueue(void *val, queue_t *queue) {
    assert(queue);
    queue_elem_t *new_elem = (queue_elem_t *)malloc(sizeof(queue_elem_t));
    new_elem->next = NULL;
    new_elem->data = val;
    if (queue->end) {
        queue->end->next = new_elem;
    }
    queue->end = new_elem;
    if (!queue->start) {
        queue->start = new_elem;
    }
    queue->length += 1;
}

void *dequeue(queue_t *queue) {
    assert(queue);
    queue_elem_t *res = queue->start;
    if (!res) { return NULL; };
    queue->start = res->next;
    queue->length -= 1;
    void *val = res->data;
    free(res);
    return val;
}

void queue_remove_elements(queue_t *queue) {
    queue_elem_t *next;
    queue_elem_t *elem = queue->start;
    while (elem) {
        next = elem->next;
        free(elem);
        elem = next;
    }
    queue->length = 0;
    queue->start = NULL;
    queue->end = NULL;
}

int queue_len(queue_t *queue) {
    if (!queue) {
        return 0;
    }
    return queue->length;
}
