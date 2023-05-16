#include "binsearch.h"

bsearch_result_t binary_search(
        const void *needle,
        const void *haystack,
        size_t item_count,
        size_t item_size,
        bsearch_compare_fun cmpfun) {
    const char *array = (const char *) haystack;
    size_t lo = 0, hi = item_count;
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        const char *ptr = array + item_size * mid;
        int result = cmpfun(needle, ptr);
        if (result == 0) return (bsearch_result_t) {.found = true, .index = mid};
        else if (result < 0) hi = mid;
        else lo = mid + 1;
    }
    // needle was not found, insertion position is at 'lo'
    return (bsearch_result_t) {.found = false, .index = lo};
}
