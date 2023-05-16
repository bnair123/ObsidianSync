#ifndef SETS_COUNTER_H
#define SETS_COUNTER_H

#include "set.h"

typedef set_t counter_t;   // a counter is really just a set of pair_t values

typedef struct pair {
    const char * key;   // the key, which is the thing we're counting
    unsigned long value;       // the count associated with the key
} pair_t;

/// Returns a pair that contains a heap-allocated copy of the string, and value set to 1
/// \param string
/// \return a pair with key set to the heap-allocated copy of string, and value set to 1
pair_t make_pair(const char * string);

/// Returns the count associated with the given string, or 0 if the string is not present
/// TODO: Implement in counter.c
/// \param counter
/// \param string
/// \return the count associated with string, or 0 if string is not in the counter
size_t counter_get_count(const counter_t *counter, const char *string);

/// Looks up the string in the counter, and increments its associated count (by one) if
/// it string was found. Otherwise, adds string to the counter with an associated count of one.
/// TODO: Implement in counter.c
/// \param counter
/// \param string
void counter_increment(counter_t *counter, const char *string);

/// Returns the address of the pair_t value stored in the counter's data array, at the given index.
/// Does not check if the index is valid, the caller must make sure that the index is valid.
/// TODO: Implement in counter.c
///   Note that this mainly requires some typecasting
/// \param counter The counter to retrieve the pair from
/// \param index The index of the pair
/// \return The address of the pair
const pair_t * counter_get_pair_at(const counter_t *counter, size_t index);

/// Initializes a counter so that it works with pair_t values
/// TODO: Implement in counter.c
///    Note that initializing a counter_t is basically initializing a set_t,
///    so think about which parameters you pass to the set_init function.
/// \param counter The counter to initialize
/// \param capacity The initial capacity of the counter
/// \return The initialized counter
counter_t *counter_init(counter_t *counter, size_t capacity);

void counter_destroy(counter_t *counter);

#endif //SETS_COUNTER_H
