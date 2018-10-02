#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#define CHILDREN_COUNT 26

typedef struct node {
    bool is_word;
    struct node *children[CHILDREN_COUNT];
} node_t;

void trie_add(node_t* root, char* word);

void trie_remove(node_t *root, char *word);

bool trie_contains(node_t* root, char* word);

void trie_destroy(node_t* root);

node_t *trie_create(void);

#endif
