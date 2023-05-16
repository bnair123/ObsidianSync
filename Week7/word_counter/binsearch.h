#ifndef SETS_BINSEARCH_H
#define SETS_BINSEARCH_H

#include <stdbool.h>
#include <stddef.h>

typedef struct bsearch_result {
    bool found;     // true if the value was found, false otherwise
    size_t index;   // index at which the value was found, or at which it should be inserted
} bsearch_result_t;

// Generic function signature used by the binary search function
typedef int (*bsearch_compare_fun)(const void*, const void*);

/// Uses binary search to locate a value in an array of values.
/// \param needle Address of the value to search for
/// \param haystack Address of the array
/// \param item_count Number of items in the array
/// \param item_size Size of a single item
/// \param cmpfun Comparison function to use
/// \return A result that has found set to true if found (false otherwise), and index into the array at which the item can be found or must be inserted to maintain a sorted order
bsearch_result_t binary_search(const void * needle, const void * haystack, size_t item_count, size_t item_size, bsearch_compare_fun cmpfun);

#endif //SETS_BINSEARCH_H
