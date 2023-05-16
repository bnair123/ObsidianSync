#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "test_counter.h"
#include "counter.h"

typedef struct {
    char * key;         // the non-const key
    size_t value;       // the count associated with the key
} internal_pair_t;

void test_counter_init(void) {
    counter_t counter;
    counter_init(&counter, 10);
    assert(counter.item_size == sizeof(pair_t));
    assert(counter.count == 0);
    assert(counter.capacity == 10);

    pair_t one = { .key = "A", .value = 1};
    pair_t two = { .key = "A", .value = 2};
    pair_t three = { .key = "B", .value = 1};

    assert(counter.cmp_fun(&one, &two) == 0);
    assert(counter.cmp_fun(&one, &three) < 0);
    assert(counter.cmp_fun(&three, &two) > 0);

    counter_destroy(&counter);

    fputs("test_counter_init PASS\n", stderr);
}

void test_counter_get_count(void) {
    counter_t counter;
    counter_init(&counter, 2);

    assert(counter_get_count(&counter, "Alice") == 0);

    ((pair_t *) counter.data)[0] = (pair_t) { .key = malloc(20), .value = 1 };
    ((pair_t *) counter.data)[1] = (pair_t) { .key = malloc(20), .value = 10 };
    strcpy( ((internal_pair_t*)counter.data)[0].key, "Alice" );
    strcpy( ((internal_pair_t*)counter.data)[1].key, "Rabbit" );
    counter.count = 2;

    assert(counter_get_count(&counter, "Alice") == 1);
    assert(counter_get_count(&counter, "Rabbit") == 10);
    assert(counter_get_count(&counter, "Alice") == 1);

    counter_destroy(&counter);

    fputs("test_counter_get_count PASS\n", stderr);
}

void test_counter_increment(void) {
    counter_t counter;
    counter_init(&counter, 2);

    ((pair_t *) counter.data)[0] = (pair_t) { .key = malloc(20), .value = 1 };
    ((pair_t *) counter.data)[1] = (pair_t) { .key = malloc(20), .value = 10 };
    strcpy( ((internal_pair_t*)counter.data)[0].key, "Alice" );
    strcpy( ((internal_pair_t*)counter.data)[1].key, "Rabbit" );
    counter.count = 2;

    counter_increment(&counter, "Alice");
    assert(counter.count == 2);

    assert(strcmp(((pair_t *) counter.data)[0].key, "Alice") == 0);
    assert(((pair_t *) counter.data)[0].value == 2);
    assert(strcmp(((pair_t *) counter.data)[1].key, "Rabbit") == 0);
    assert(((pair_t *) counter.data)[1].value == 10);

    counter_increment(&counter, "Potion");
    assert(counter.count == 3);

    assert(strcmp(((pair_t *) counter.data)[0].key, "Alice") == 0);
    assert(((pair_t *) counter.data)[0].value == 2);
    assert(strcmp(((pair_t *) counter.data)[1].key, "Potion") == 0);
    assert(((pair_t *) counter.data)[1].value == 1);
    assert(strcmp(((pair_t *) counter.data)[2].key, "Rabbit") == 0);
    assert(((pair_t *) counter.data)[2].value == 10);

    counter_destroy(&counter);

    fputs("test_counter_increment PASS\n", stderr);
}

void test_counter_get_pair_at(void) {
    counter_t counter;
    counter_init(&counter, 3);

    ((pair_t *) counter.data)[0] = (pair_t) { .key = malloc(20), .value = 2 };
    ((pair_t *) counter.data)[1] = (pair_t) { .key = malloc(20), .value = 1 };
    ((pair_t *) counter.data)[2] = (pair_t) { .key = malloc(20), .value = 10 };
    counter.count = 3;

    strcpy( ((internal_pair_t*)counter.data)[0].key, "Alice" );
    strcpy( ((internal_pair_t*)counter.data)[1].key, "Potion" );
    strcpy( ((internal_pair_t*)counter.data)[2].key, "Rabbit" );

    const pair_t * pair = counter_get_pair_at(&counter, 0);
    assert(strcmp(pair->key, "Alice") == 0);
    assert(pair->value == 2);

    pair = counter_get_pair_at(&counter, 1);
    assert(strcmp(pair->key, "Potion") == 0);
    assert(pair->value == 1);

    pair = counter_get_pair_at(&counter, 2);
    assert(strcmp(pair->key, "Rabbit") == 0);
    assert(pair->value == 10);

    counter_destroy(&counter);

    fputs("test_counter_get_pair_at PASS\n", stderr);
}
