#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_elem_t {
    void *data;
    struct queue_elem_t *next;
} queue_elem_t;

typedef struct queue_t {
    queue_elem_t *start;
    queue_elem_t *end;
    int length;
} queue_t;

/* Creates a empty queue */
queue_t *queue_create(void);

/* Adds an element at the end of the queue */
void enqueue(void *val, queue_t *queue);

/* Returns the element at the queues front (FIFO) */
void *dequeue(queue_t *queue);

/* Removes all elements from the queue 
 * but doesn't affect the queue_t or the elements itself. */
void queue_remove_elements(queue_t *queue);

int queue_len(queue_t *queue);

#endif
