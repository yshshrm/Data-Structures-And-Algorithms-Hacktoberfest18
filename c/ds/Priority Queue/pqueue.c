#include "pqueue.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>


void pqueue_new(pqueue *q, size_t elem_size,
  pqueue_compare_function cmpfn, pqueue_free_function freefn){
  q->elem_size = elem_size;
  assert (q->elem_size > 0);
  q->cmpfn = cmpfn;
  assert(q->cmpfn != NULL);
  q->freefn = freefn;
  vector *elems = malloc(sizeof(vector));
  assert(elems != NULL);
  VectorNew(elems, q->elem_size, q->freefn, 0);
  q->elems = elems;
}

void pqueue_dispose(pqueue *q){
  VectorDispose(q->elems);
  free(q->elems);
}

void pqueue_push(pqueue *q, const void *elem_addr){
  assert(elem_addr != NULL);
  VectorAppend(q->elems, elem_addr);
}

void pqueue_top(pqueue *q, void *dest){
  assert(dest != NULL);
  assert(!pqueue_is_empty(q));
  void *max_elem = VectorNth(q->elems, 0);
  for (int i = 0; i < pqueue_length(q); i++)
    if (q->cmpfn(VectorNth(q->elems, i), max_elem) > 0)
      max_elem = VectorNth(q->elems, i);
  memcpy(dest, max_elem, q->elem_size);
}

void pqueue_pop(pqueue *q){
  assert(!pqueue_is_empty(q));
  int max_elem_index = 0;
  for (int i = 1; i < pqueue_length(q); i++)
    if (q->cmpfn(VectorNth(q->elems, i), VectorNth(q->elems, max_elem_index)) > 0)
      max_elem_index = i;
  VectorDelete(q->elems, max_elem_index);
}

int pqueue_is_empty(pqueue *q){
  return pqueue_length(q) == 0;
}

int pqueue_length(pqueue *q){
  return VectorLength(q->elems);
}
