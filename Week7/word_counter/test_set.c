#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_set.h"
#include "set.h"

/// Simple comparison function that can be used in a set_t that stores <int>s, for testing purposes.
/// This function treats a and b as int pointers.
/// \param a treated as a const int pointer
/// \param b treated as a const int pointer
/// \return 0 if a and b are equal, -1 if a < b, and 1 if a > b
int int_compare(const void *a, const void *b) {
    int val_a = *(const int*) a;
    int val_b = *(const int*) b;
    if (val_a > val_b) return 1;
    else if (val_a < val_b) return -1;
    else return 0;
}

void test_set_add(void) {
    set_t * set = set_create(10, sizeof(int), int_compare);
    bool result;
    const int one = 1, two = 2, three = 3, four = 4, five = 5;
    const int also_two = 2;

    result = set_add(set, &two);
    assert(result);
    assert(set->count == 1);
    assert(((int*) set->data)[0] == 2);

    result = set_add(set, &one);
    assert(result);
    assert(set->count == 2);
    assert(((int*) set->data)[0] == 1);
    assert(((int*) set->data)[1] == 2);

    result = set_add(set, &five);
    assert(result);
    assert(set->count == 3);
    assert(((int*) set->data)[0] == 1);
    assert(((int*) set->data)[1] == 2);
    assert(((int*) set->data)[2] == 5);

    result = set_add(set, &four);
    assert(result);
    assert(set->count == 4);
    assert(((int*) set->data)[0] == 1);
    assert(((int*) set->data)[1] == 2);
    assert(((int*) set->data)[2] == 4);
    assert(((int*) set->data)[3] == 5);

    result = set_add(set, &also_two);
    assert(!result);
    assert(set->count == 4);
    assert(((int*) set->data)[0] == 1);
    assert(((int*) set->data)[1] == 2);
    assert(((int*) set->data)[2] == 4);
    assert(((int*) set->data)[3] == 5);

    result = set_add(set, &three);
    assert(result);
    assert(set->count == 5);
    assert(((int*) set->data)[0] == 1);
    assert(((int*) set->data)[1] == 2);
    assert(((int*) set->data)[2] == 3);
    assert(((int*) set->data)[3] == 4);
    assert(((int*) set->data)[4] == 5);

    set_destroy(set);
    free(set);

    fputs("test_set_add PASS\n", stderr);
}

void test_set_remove(void) {
    set_t * set = set_create(5, sizeof(int), int_compare);

    ((int*) set->data)[0] = 1;
    ((int*) set->data)[1] = 2;
    ((int*) set->data)[2] = 3;
    ((int*) set->data)[3] = 4;
    ((int*) set->data)[4] = 5;
    set->count = 5;

    const int one = 1, two = 2, three = 3, four = 4, five = 5, six = 6;

    set_remove(set, &six);
    assert(set->count == 5);
    assert(((int*) set->data)[0] == 1);
    assert(((int*) set->data)[1] == 2);
    assert(((int*) set->data)[2] == 3);
    assert(((int*) set->data)[3] == 4);
    assert(((int*) set->data)[4] == 5);

    set_remove(set, &one);
    assert(set->count == 4);
    assert(((int*) set->data)[0] == 2);
    assert(((int*) set->data)[1] == 3);
    assert(((int*) set->data)[2] == 4);
    assert(((int*) set->data)[3] == 5);

    set_remove(set, &three);
    assert(set->count == 3);
    assert(((int*) set->data)[0] == 2);
    assert(((int*) set->data)[1] == 4);
    assert(((int*) set->data)[2] == 5);

    set_remove(set, &five);
    assert(set->count == 2);
    assert(((int*) set->data)[0] == 2);
    assert(((int*) set->data)[1] == 4);

    set_remove(set, &two);
    assert(set->count == 1);
    assert(((int*) set->data)[0] == 4);

    set_remove(set, &four);
    assert(set->count == 0);

    set_destroy(set);
    free(set);

    fputs("test_set_remove PASS\n", stderr);
}

void test_set_contains(void) {
    set_t * set = set_create(5, sizeof(int), int_compare);

    ((int*) set->data)[0] = 1;
    ((int*) set->data)[1] = 2;
    ((int*) set->data)[2] = 3;
    ((int*) set->data)[3] = 4;
    ((int*) set->data)[4] = 5;
    set->count = 5;

    int one = 1, two = 2, three = 3, four = 4, five = 5, six = 6;
    assert(!set_contains(set, &six));

    assert(set_contains(set, &one));
    assert(set_contains(set, &two));
    assert(set_contains(set, &three));
    assert(set_contains(set, &four));
    assert(set_contains(set, &five));

    set_destroy(set);
    free(set);

    fputs("test_set_contains PASS\n", stderr);
}
