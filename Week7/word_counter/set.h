#ifndef DICTIONARIES_SET_H
#define DICTIONARIES_SET_H

#include <stddef.h>
#include <stdbool.h>

// Function pointer type to point to a function that compares two arbitrary things
// and returns -1, 0, or 1
typedef int (*compare_fun_t)(const void *, const void *);
typedef struct set {
    compare_fun_t cmp_fun;  // function for comparing keys
    void *data;             // dynamic generic array
    size_t item_size;
    size_t capacity;        // current capacity of data
    size_t count;           // current nr. of items in data
} set_t;

/// Checks if a item is in the set
/// \param set The set to search
/// \param item The item to search for in the set
/// \return true if the item is present, false if it is not
bool set_contains(const set_t *set, const void* item);

/// Adds a value to a set, if it is not already present
/// \param set The set to add the value to
/// \param value The value to add to the set
/// \return true if the value was added, false if it was already present or no memory could be allocated
bool set_add(set_t *set, const void* item);

/// Removes an item from a set, if it is present
/// \param set The set to remove the item from
/// \param item The item to remove from the set
void set_remove(set_t *set, const void* item);

/// Heap-allocates a set and initializes it
/// \param init_cap The initial capacity for the set
/// \param init_size The size (nr. of bytes) of a single item
/// \param cmp_fun The function used to compare two keys
/// \return An initialized set, or NULL if it could not be created
set_t *set_create(size_t init_cap, size_t item_size, compare_fun_t cmp_fun);

/// Initializes a set
/// \param set The set to initialize
/// \param init_cap The initial capacity for the set
/// \param init_size The size (nr. of bytes) of a single item
/// \param cmp_fun The function used to compare two values
/// \return The initialized set
set_t *set_init(set_t *set, size_t init_cap, size_t item_size, compare_fun_t cmp_fun);

/// Ensures that the set can store at least one more element
/// \param set The set
/// \return true if the set can store at least one more element, false otherwise
bool set_ensure_capacity(set_t *set);

/// Deallocates the dynamic memory resources used by the set
/// \param set The set to destroy
void set_destroy(set_t *set);

#endif //DICTIONARIES_SET_H
