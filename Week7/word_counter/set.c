#include <string.h>
#include <stdlib.h>
#include "set.h"
#include "binsearch.h"

bool set_contains(const set_t *set, const void *item) {
    // use binary search to locate the item
    bsearch_result_t result = binary_search(item, set->data, set->count, set->item_size, set->cmp_fun);
    return result.found;
}

bool set_add(set_t *set, const void* item) {
    // use binary search to locate the item
    bsearch_result_t result = binary_search(item, set->data, set->count, set->item_size, set->cmp_fun);
    if (!result.found && set_ensure_capacity(set)) {
        // get a pointer to the data that we can work with
        char * ptr = (char*) set->data;

        // shift items, making space for a new item at index result.index
        memmove(ptr + set->item_size * (result.index + 1),
                ptr + set->item_size * result.index,
                (set->count - result.index) * set->item_size);

        set->count++;

        // copy the item into the set
        memcpy(ptr + set->item_size * result.index, item, set->item_size);
        return true;
    }
    else return false;  // item wasn't or couldn't be added
}

void set_remove(set_t *set, const void *item) {
    // use binary search to locate the item
    bsearch_result_t result = binary_search(item, set->data, set->count, set->item_size, set->cmp_fun);
    if (result.found) {
        set->count--;
        // get a pointer to the data that we can work with
        char * ptr = (char*) set->data;

        // shift items, overwriting the item at index result.index
        memmove(ptr + set->item_size * result.index,
                ptr + set->item_size * (result.index + 1),
                (set->count - result.index) * set->item_size);
    }
}

set_t *set_create(size_t init_cap, size_t item_size, compare_fun_t cmp_fun) {
    return set_init((set_t *) malloc(sizeof(set_t)), init_cap, item_size, cmp_fun);
}

set_t *set_init(set_t *set, size_t init_cap, size_t item_size, compare_fun_t cmp_fun) {
    if (set != NULL) {
        set->cmp_fun = cmp_fun;
        set->item_size = item_size;
        set->data = malloc(init_cap * item_size);
        set->count = 0;
        set->capacity = set->data != NULL ? init_cap : 0;
    }
    return set;
}


/// Ensures that the set can store at least one more element
/// \param set The set
bool set_ensure_capacity(set_t *set) {
    if (set->count < set->capacity) return true;
    size_t cap = (set->capacity + 1) * 3 / 2;
    void *ptr = realloc(set->data, cap * set->item_size);
    if (ptr != NULL) {
        set->data = ptr;
        set->capacity = cap;
        return true;
    } else return false;
}

void set_destroy(set_t *set) {
    free(set->data);
    set->data = NULL;
    set->capacity = 0;
}

