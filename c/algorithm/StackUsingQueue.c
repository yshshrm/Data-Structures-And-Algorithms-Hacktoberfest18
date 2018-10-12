#include <stdio.h>
#include <stdlib.h>
 
/* Queue structure */
 
#define QUEUE_EMPTY_MAGIC 0xdeadbeef
typedef struct _queue_t {
    int *arr;
    int rear, front, count, max;
} queue_t;
 
/* Queue operation function prototypes */
queue_t *queue_allocate(int n);
void queue_insert(queue_t * q, int v);
int queue_remove(queue_t * q);
int queue_count(queue_t * q);
int queue_is_empty(queue_t * q);
 
/* NOTE: Here is the stuff we are interested in */
/* Simulated stack operations START */
 
/* NOTE: passing the queue object, on which we will only operate the
 * queue operations.
 */
void stack_push(queue_t * q, int v) {
    queue_insert(q, v);
}
 
int stack_pop(queue_t * q) {
    int i, n = queue_count(q);
    int removed_element;
 
    for (i = 0; i < (n - 1); i++) {
        removed_element = queue_remove(q);
        queue_insert(q, removed_element);
        /* same as below */
        //queue_insert (q, queue_remove (q))
    }
    removed_element = queue_remove(q);
 
    return removed_element;
}
 
int stack_is_empty(queue_t * q) {
    return queue_is_empty(q);
}
 
int stack_count(queue_t * q) {
    return queue_count(q);
}
 
/* Simulated stack operations END */
 
/* Queue operations START */
 
int queue_count(queue_t * q) {
    return q->count;
}
 
queue_t *
queue_allocate(int n) {
    queue_t *queue;
 
    queue = malloc(sizeof(queue_t));
    if (queue == NULL)
        return NULL;
    queue->max = n;
 
    queue->arr = malloc(sizeof(int) * n);
    queue->rear = n - 1;
    queue->front = n - 1;
 
    return queue;
}
 
void queue_insert(queue_t * q, int v) {
    if (q->count == q->max)
        return;
 
    q->rear = (q->rear + 1) % q->max;
    q->arr[q->rear] = v;
    q->count++;
}
 
int queue_remove(queue_t * q) {
    int retval;
 
    /* magic number if queue is empty */
    if (q->count == 0)
        return QUEUE_EMPTY_MAGIC;
 
    q->front = (q->front + 1) % q->max;
    retval = q->arr[q->front];
    q->count--;
 
    return retval;
}
 
int queue_is_empty(queue_t * q) {
    return (q->count == 0);
}
 
/* Queue operations END */
 
/* For demo */
void queue_display(queue_t * q) {
    int i = (q->front + 1) % q->max, elements = queue_count(q);
 
    while (elements--) {
        printf("[%d], ", q->arr[i]);
        i = (i >= q->max) ? 0 : (i + 1);
    }
}
 
#define MAX 128
int main(void) {
    queue_t *q;
    int x, select;
    /* Static allocation */
    q = queue_allocate(MAX);
 
    do {
        printf("\n[1] Push\n[2] Pop\n[0] Exit");
        printf("\nChoice: ");
        scanf(" %d", &select);
 
        switch (select) {
        case 1:
            printf("\nEnter value to Push:");
            scanf(" %d", &x);
            /* Pushing */
            stack_push(q, x);
 
            printf("\n\n__________________________\nCurrent Queue:\n");
 
            queue_display(q);
            printf("\n\nPushed Value: %d", x);
 
            printf("\n__________________________\n");
            break;
 
        case 2:
            /* Popping */
            x = stack_pop(q);
 
            printf("\n\n\n\n__________________________\nCurrent Queue:\n");
 
            queue_display(q);
            if (x == QUEUE_EMPTY_MAGIC)
                printf("\n\nNo values removed");
            else
                printf("\n\nPopped Value: %d", x);
 
            printf("\n__________________________\n");
            break;
 
        case 0:
            printf("\nQutting.\n");
            return 0;
 
        default:
            printf("\nQutting.\n");
            return 0;
        }
    } while (1);
 
    return 0;
}
