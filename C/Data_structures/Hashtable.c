#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct HashNode {
    void *value;
    void *key;
    struct HashNode *next;
};

struct HTable {
    struct HashNode **htable;
    size_t size;
    size_t items;
    float loadFactor;

    size_t (*hash)(void *key);

    bool (*equals_to)(void *key1, void *key2);

    void (*free)(void *key, void *value);
};

typedef enum {
    SUCCESS,
    ENOMEM,
    KEYEXIST,
    NULLVAL
} errCode;

#define __HT_MODE_CLEAR    0x00
#define __HT_MODE_DESTROY  0x01

// *********************************
// *          HASHTABLE            *
// *********************************

static struct HashNode *__ht_search_node(struct HTable *htable, void *key) {
    struct HashNode *cursor;
    size_t index;
    if (key != NULL && htable->htable != NULL) {
        index = htable->hash(key) % htable->size;
        for (cursor = htable->htable[index]; cursor != NULL; cursor = cursor->next)
            if (htable->equals_to(cursor->key, key))
                return cursor;
    }
    return NULL;
}

bool ht_contains(struct HTable *htable, void *key) {
    return __ht_search_node(htable, key) != NULL;
}

static errCode __ht_rehash(struct HTable *htable) {
    struct HashNode **newtable;
    struct HashNode *prev;
    struct HashNode *cursor;
    struct HashNode *next;
    size_t newsize;
    size_t oldsize;
    size_t newhash;

    newsize = htable->size * 2;
    oldsize = htable->size;

    if ((newtable = (struct HashNode **) realloc(htable->htable, newsize * sizeof(struct HashNode *))) == NULL)
        return ENOMEM;
    for (size_t i = oldsize; i < newsize; i++)
        newtable[i] = NULL;
    for (size_t i = 0; i < oldsize; i++) {
        for (prev = NULL, cursor = newtable[i]; cursor != NULL; cursor = next) {
            newhash = htable->hash(cursor->key) % newsize;
            next = cursor->next;
            if (newhash == i) {
                prev = cursor;
                continue;
            }
            cursor->next = newtable[newhash];
            newtable[newhash] = cursor;
            if (prev != NULL)
                prev->next = next;
            else
                newtable[i] = next;
        }
    }
    htable->htable = newtable;
    htable->size = newsize;
    return SUCCESS;
}

errCode __ht_insert(struct HTable *htable, void *key, void *value, bool override) {
    struct HashNode *cursor;

    if (value == NULL || key == NULL)
        return NULLVAL;

    if (htable->htable == NULL) {
        if ((htable->htable = (struct HashNode **) calloc(htable->size, sizeof(struct HashNode *))) == NULL)
            return ENOMEM;
    }

    if (((float) htable->items + 1) / htable->size > htable->loadFactor) {
        errCode err;
        if ((err = __ht_rehash(htable)) != SUCCESS)
            return err;
    }

    size_t index = htable->hash(key) % htable->size;
    if ((cursor = __ht_search_node(htable, key)) != NULL) {
        if (override) {
            if (htable->free != NULL)
                htable->free(cursor->key, cursor->value);
            cursor->key = key;
            cursor->value = value;
            return SUCCESS;
        } else
            return KEYEXIST;
    }

    if ((cursor = (struct HashNode *) malloc(sizeof(struct HashNode))) == NULL)
        return ENOMEM;
    cursor->value = value;
    cursor->key = key;
    cursor->next = htable->htable[index];
    htable->htable[index] = cursor;
    htable->items++;
    return SUCCESS;
}

errCode ht_put(struct HTable *htable, void *key, void *value) {
    return __ht_insert(htable, key, value, false);
}

errCode ht_set(struct HTable *htable, void *key, void *value) {
    return __ht_insert(htable, key, value, true);
}

void *ht_get(struct HTable *htable, void *key) {
    struct HashNode *node;
    if ((node = __ht_search_node(htable, key)) != NULL)
        return node->value;
    return NULL;
}

void ht_init(struct HTable *htable, size_t size, float loadFactor, size_t (*hash)(void *key),
             bool (*equals_to)(void *key1, void *key2), void (*free)(void *key, void *value)) {
    htable->htable = NULL;
    htable->size = size;
    htable->items = 0;
    htable->loadFactor = loadFactor;
    htable->hash = hash;
    htable->equals_to = equals_to;
    htable->free = free;
}

void *ht_remove(struct HTable *htable, void *key) {
    struct HashNode *cursor;
    struct HashNode *prev;
    void *value = NULL;
    size_t index;

    if (htable->htable != NULL) {
        index = htable->hash(key) % htable->size;
        for (prev = NULL, cursor = htable->htable[index]; cursor != NULL; prev = cursor, cursor = prev->next) {
            if (htable->equals_to(cursor->key, key)) {
                value = cursor->value;
                if (htable->free != NULL)
                    htable->free(cursor->key, NULL);
                if (prev == NULL)
                    htable->htable[index] = cursor->next;
                else
                    prev->next = cursor->next;
                free(cursor);
                htable->items--;
                break;
            }
        }
    }
    return value;
}

static void __ht_clear_table(struct HTable *htable, int mode) {
    struct HashNode *cursor;
    struct HashNode *tmp;

    if (htable->htable == NULL)
        return;

    for (size_t i = 0; i < htable->size; i++) {
        for (cursor = htable->htable[i]; cursor != NULL; cursor = tmp) {
            tmp = cursor->next;
            if (htable->free != NULL)
                htable->free(cursor->key, cursor->value);
            free(cursor);
        }
        htable->htable[i] = NULL;
    }
    htable->items = 0;
    switch (mode) {
        case __HT_MODE_DESTROY:
            free(htable->htable);
            memset(htable, 0x00, sizeof(struct HTable));
            htable->htable = NULL;
            break;
        default:    // __HT_MODE_CLEAR
            break;
    }
}

void ht_cleanup(struct HTable *htable) {
    __ht_clear_table(htable, __HT_MODE_DESTROY);
}

void ht_clear(struct HTable *htable, bool size_reset) {
    __ht_clear_table(htable, __HT_MODE_CLEAR);
}

// *********************************
// *            UTILS              *
// *********************************

bool eq4str(void *str1, void *str2) {
    return strcmp((char *) str1, (char *) str2) == 0;
}

// djb2
size_t hash4str(void *str) {
    unsigned char *s = (unsigned char *) str;
    size_t hash = 5381;
    int c;

    while ((c = *s++) != 0)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void g2free(void *obj1, void *obj2) {
    free(obj1);
    free(obj2);
}

// *********************************
// *            MAIN               *
// *********************************

int main(int argc, char **argv) {
    struct HTable table;
    char *key;
    char *value;

    ht_init(&table, 3, 0.75, hash4str, eq4str, g2free);
    ht_put(&table, strdup("h20"), strdup("water"));
    assert(ht_put(&table, strdup("h20"), strdup("err")) == KEYEXIST);
    ht_put(&table, strdup("ch4"), strdup("methane"));
    ht_put(&table, strdup("ch3"), strdup("methyl"));
    assert(ht_contains(&table, "ch4") == true);
    ht_put(&table, strdup("c6h6"), strdup("benzene"));
    ht_put(&table, strdup("rcooh"), strdup("carboxylic acid"));
    assert(ht_contains(&table, "ch4") == true);
    ht_put(&table, strdup("c8h16"), strdup("3-octane"));
    assert(strcmp(((char *) ht_get(&table, "c8h16")), "3-octane") == 0);
    ht_set(&table, strdup("c8h16"), strdup("ethylcyclohexane"));
    assert(strcmp(((char *) ht_get(&table, "c8h16")), "ethylcyclohexane") == 0);
    assert(strcmp(((char *) ht_get(&table, "ch3")), "methyl") == 0);

    free(ht_remove(&table, "ch3"));
    assert(ht_get(&table, "ch3") == NULL);
    ht_clear(&table, true);
    assert(ht_contains(&table, "ch4") == false);
    ht_put(&table, strdup("ch4"), strdup("methane"));
    ht_put(&table, strdup("ch3"), strdup("methyl"));
    assert(strcmp(((char *) ht_get(&table, "ch3")), "methyl") == 0);
    ht_cleanup(&table);
}
