#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <search.h>

const int DEFAULT_ALLOCATION_LENGTH = 10;

// Reallocates memeory for elems.
void vector_grow(vector *v){
  void *newAlloc = realloc(v->elems, (v->allocLen + v->initialAllocation) * v->elemSize);
  assert(newAlloc != NULL);
  v->allocLen += v->initialAllocation;
  v->elems = newAlloc;
}

void vector_new(vector *v, int elemSize, VectorFreeFunction freeFn, int initialAllocation){
  v->elemSize = elemSize;
  assert(v->elemSize > 0);
  if (v->allocLen == 0){
    v->allocLen = DEFAULT_ALLOCATION_LENGTH;
    v->initialAllocation = DEFAULT_ALLOCATION_LENGTH;
  } else {
    v->allocLen = initialAllocation;
    v->initialAllocation = initialAllocation;
  }
  assert(v->allocLen > 0);
  assert(v->initialAllocation > 0);
  v->logLen = 0;
  v->elems = malloc(elemSize * v->allocLen);
  assert(v->elems != NULL);
  v->freeFn = freeFn;
  
}

void vector_dispose(vector *v){
  v->logLen = 0;
  v->allocLen = 0;
  if (v->freeFn != NULL){
    for (int i = 0; i < v->logLen; i++){
      void *currElem = (char *)v->elems + i * v->elemSize;
      v->freeFn(currElem);
    }
  }
  free(v->elems);
}

int vector_length(const vector *v){
  return v->logLen;
}

void *vector_nth(const vector *v, int position){
  assert(position >= 0 && position < v->logLen);
  return (char *)(v->elems) + position * v->elemSize;
  return NULL;
}

void vector_replace(vector *v, const void *elemAddr, int position){
  assert(position >= 0 && position < v->logLen);
  assert(elemAddr != NULL);
  void *replaceAddr = (char *)(v->elems) + position * v->elemSize;
  if (v->freeFn != NULL)
    v->freeFn(replaceAddr);
  memcpy(replaceAddr, elemAddr, v->elemSize);
}

void vector_insert(vector *v, const void *elemAddr, int position){
  assert(position >= 0 && position <= v->logLen);
  assert(elemAddr != NULL);
  if (v->logLen == v->allocLen)
    vector_grow(v);
  void *insertAddr = (char *)(v->elems) + position * v->elemSize;
  void *dest = memmove((char *)insertAddr + v->elemSize, insertAddr, (v->logLen - position) * v->elemSize);
  assert(dest != NULL);
  memcpy(insertAddr, elemAddr, v->elemSize);
  v->logLen++;
}

void vector_append(vector *v, const void *elemAddr){
  assert(elemAddr != NULL);
  if (v->logLen == v->allocLen)
    vector_grow(v);
  void *dest = (char *)v->elems + v->logLen * v->elemSize;
  memcpy(dest, elemAddr, v->elemSize);
  v->logLen++;
}

void vector_delete(vector *v, int position){
  assert(position >= 0 && position < v->logLen);
  void *deleteAddr = (char *)v->elems + position * v->elemSize;
  if (v->freeFn != NULL)
    v->freeFn(deleteAddr);
  memmove(deleteAddr, (char *)deleteAddr + v->elemSize, v->elemSize * (v->logLen - position));
  v->logLen--;
}

void vector_sort(vector *v, VectorCompareFunction compare){
  assert(compare != NULL);
  qsort(v->elems, v->logLen, v->elemSize, compare);
}

void vector_map(vector *v, VectorMapFunction mapFn, void *auxData){
  assert(mapFn != NULL);
  for (int i = 0; i < v->logLen; i++){
    void *currElem = (char *)v->elems + i * v->elemSize;
    mapFn(currElem, auxData);
  }
}

static const int kNotFound = -1;
int vector_search(const vector *v, const void *key, VectorCompareFunction searchFn, int startIndex, bool isSorted){
  assert(searchFn != NULL);
  assert(startIndex >= 0 && startIndex <= v->logLen);
  void *startPointer = (char *)v->elems + startIndex * v->elemSize;
  void *resPointer = NULL;
  size_t elemNum = v->logLen - startIndex;
  if (isSorted){
    resPointer = bsearch(key, startPointer, elemNum, v->elemSize, searchFn);
  } else {
    resPointer = lfind(key, startPointer, &elemNum, v->elemSize, searchFn);
  }
  if (resPointer == NULL)
    return kNotFound;
  return ((int)(resPointer - v->elems)) / v->elemSize;
}
