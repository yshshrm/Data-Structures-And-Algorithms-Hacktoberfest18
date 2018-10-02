#ifndef _hashmap_
#define _hashmap_

#include <stdlib.h>
#include "vector.h"

// User-provided comparator function
typedef int (*hashmap_compare_function)(const void *elem_addr1, const void *elem_addr2);

// User-provided free function
typedef void (*hashmap_free_function)(void *elem_addr);

// User-provided hash function
typedef int (*hashmap_hash_function)(const void *elem_addr, int num_buckets);

typedef struct {
  void *key;
  void *value;
} pair;

typedef struct {
  size_t log_len;
  size_t value_size;
  size_t key_size;
  size_t num_buckets;
  vector *elems;
  hashmap_hash_function hashfn;
  hashmap_free_function freefn;
  hashmap_compare_function cmpfn;
} hashmap;

void hashmap_new(hashmap *m, size_t key_size, size_t value_size, size_t num_buckets,
  hashmap_compare_function cmpfn, hashmap_free_function freefn, hashmap_hash_function hashfn);

void hashmap_put(hashmap *m, void *key, void *value);

void hashmap_remove(hashmap *m, void *key);

int hashmap_contains_key(hashmap *m, void *key);

void hashmap_dispose(hashmap *m);

void hashmap_get(hashmap *m, void *key, void *dest);

int hashmap_length(hashmap *m);

int hashmap_is_empty(hashmap *m);

#endif
