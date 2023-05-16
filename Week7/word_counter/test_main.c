#include "test_set.h"
#include "test_counter.h"

int main(void) {
    test_set_contains();
    test_set_remove();
    test_set_add();

    // TODO (Activity 7): implement the following functions in counter.c
    //  counter_init
    //  counter_get_pair_at
    //  counter_get_count
    //  counter_increment
    //  counter_destroy
    //  All tests must pass, and the address sanitizer must find no issues
    test_counter_init();
    test_counter_get_pair_at();
    test_counter_get_count();
    test_counter_increment();

    return 0;
}
