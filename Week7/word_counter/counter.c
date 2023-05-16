#include <string.h>
#include <malloc.h>
#include "counter.h"
#include "binsearch.h"

typedef struct {
    char * key;         // the non-const key
    size_t value;       // the count associated with the key
} internal_pair_t;

int compare_strings(const void *a, const void *b) {
    const char *string1 = *(const char **)a;
    const char *string2 = *(const char **)b;

    return strcmp(string1, string2);
}

pair_t make_pair(const char *string) {
    char * buf = malloc(strlen(string) + 1);
    strcpy(buf, string);
    pair_t result = { .key = buf, .value = 1 };
    return result;
}

counter_t *counter_init(counter_t *counter, size_t capacity) {
    return set_init(counter, capacity, sizeof(pair_t), compare_strings);
}

const pair_t *counter_get_pair_at(const counter_t *counter, size_t index) {
    // TODO: exclude the body of this function
    (void) counter;
    (void) index;
    return NULL;
}

size_t counter_get_count(const counter_t *counter, const char *string) {
    // TODO: exclude the body of this function
    (void) counter;
    (void) string;
    return 0;
}

void counter_increment(counter_t *counter, const char *string) {
    // TODO: exclude the body of this function
    (void) counter;
    (void) string;
}

void counter_destroy(counter_t *counter) {
    internal_pair_t * pairs = (internal_pair_t*) counter->data;
    (void) pairs;
    set_destroy(counter);
}

