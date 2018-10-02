/*
 * Interface for Priority Queue
 * -----------------------------------------------------------------------------
 * file pqueue.h
 */

#ifndef _pqueue_
#define _pqueue_

#include "vector.h"
#include <stdlib.h>

// Client-supplied compare function.
typedef int (*pqueue_compare_function)(const void *elem_addr1, const void *elem_addr2);

// Client-supplied free function.
typedef void (*pqueue_free_function)(void *elem_addr);

// pqueue structure
typedef struct {
  size_t log_len;
  size_t elem_size;
  vector *elems;
  pqueue_compare_function cmpfn;
  pqueue_free_function freefn;
} pqueue;

// Init new pqueue;
void pqueue_new(pqueue *q, size_t elem_size,
  pqueue_compare_function cmpfn, pqueue_free_function freefn);

// Frees memeory
void pqueue_dispose(pqueue *q);

// Add new elem to pqueue;
void pqueue_push(pqueue *q, const void *elem_addr);

// Get element with the highest priority.
void pqueue_top(pqueue *q, void *dest);

// Remove element with the highest priority.
void pqueue_pop(pqueue *q);

// Returns positive integer if pqueue is empty and 0 if not;
int pqueue_is_empty(pqueue *q);

// Returns the number of elements in pqueue.
int pqueue_length(pqueue *q);

#endif
