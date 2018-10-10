#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void hashmap_new(hashmap *m, size_t key_size, size_t value_size, size_t num_buckets,
  hashmap_compare_function cmpfn, hashmap_free_function freefn, hashmap_hash_function hashfn){
  m->log_len = 0;
  m->value_size = value_size;
  assert(m->value_size > 0);
  m->key_size = key_size;
  assert(m->key_size > 0);
  m->num_buckets = num_buckets;
  assert(m->num_buckets > 0);
  m->cmpfn = cmpfn;
  assert(m->cmpfn != NULL);
  m->freefn = freefn;
  m->hashfn = hashfn;
  assert(m->hashfn != NULL);
  m->elems = malloc(sizeof(vector) * num_buckets);
  assert(m->elems != NULL);
  for (int i = 0; i < m->num_buckets; i++)
    vector_new(m->elems + i, sizeof(pair), m->freefn, 0);
}

vector *key_to_vector(hashmap *m, void *key){
  int hash = m->hashfn(key, m->num_buckets);
  assert(hash >= 0 && hash < m->num_buckets);
  return m->elems + hash;
}

pair *new_pair(hashmap *m, void *key, void *value){
  pair *new_pair = malloc(sizeof(pair));
  assert(new_pair != NULL);
  new_pair->key = malloc(m->key_size);
  assert(new_pair->key != NULL);
  memcpy(new_pair->key, key, m->key_size);
  new_pair->value = malloc(m->value_size);
  assert(new_pair->value != NULL);
  memcpy(new_pair->value, value, m->value_size);
  return new_pair;
}

void hashmap_put(hashmap *m, void *key, void *value){
  assert(key != NULL);
  assert(value != NULL);
  vector *curr_vect = key_to_vector(m, key);
  pair *curr_pair = new_pair(m, key, value);
  for (int i = 0; i < vector_length(curr_vect); i++){
    if (m->cmpfn(((pair *)vector_nth(curr_vect, i))->key, key) == 0){
      vector_replace(curr_vect, curr_pair, i);
      return;
    }
  }
  vector_append(curr_vect, curr_pair);
  m->log_len++;
}

void hashmap_remove(hashmap *m, void *key){
  assert(key != NULL);
  assert(m->log_len > 0);
  vector *curr_vect = key_to_vector(m, key);
  for (int i = 0; i < vector_length(curr_vect); i++){
    if (m->cmpfn(((pair *)vector_nth(curr_vect, i))->key, key) == 0){
      vector_delete(curr_vect, i);
      m->log_len--;
    }
  }
}

int hashmap_contains_key(hashmap *m, void *key){
  assert(key != NULL);
  vector *curr_vect = key_to_vector(m, key);
  for (int i = 0; i < vector_length(curr_vect); i++)
    if (m->cmpfn(((pair *)vector_nth(curr_vect, i))->key, key) == 0)
      return 1;
  return 0;
}

void hashmap_dispose(hashmap *m){
  for (int i = 0; i < m->num_buckets; i++)
    vector_dispose(m->elems + i);
  free(m->elems);
}

void hashmap_get(hashmap *m, void *key, void *dest){
  assert(key != NULL);
  assert(dest != NULL);
  vector *curr_vect = key_to_vector(m, key);
  for (int i = 0; i < vector_length(curr_vect); i++){
    if (m->cmpfn(((pair *)vector_nth(curr_vect, i))->key, key) == 0){
      memcpy(dest, ((pair *)vector_nth(curr_vect, i))->value, m->value_size);
      return;
    }
  }
}

int hashmap_length(hashmap *m){
  return m->log_len;
}

int hashmap_is_empty(hashmap *m){
  return hashmap_length(m) == 0;
}
