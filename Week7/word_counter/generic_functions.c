#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binsearch.h"

void print_string_array(const char ** array, size_t count) {
    printf("[%s", array[0]);
    for (size_t i = 1; i < count; ++i) printf(", %s", array[i]);
    printf("]\n");
}

int compare_strings(const void *a, const void *b) {
    const char *string1 = *(const char **)a;
    const char *string2 = *(const char **)b;

    return strcmp(string1, string2);
}

int main(void) {
    // TODO (Activity 5): create a generic function that compares two strings of which the address are passed,
    //  and use it to sort this array of strings using the qsort function
    const char * strings[] = {"Spam", "Cheese", "Knights", "Holy Grail", "Lumberjack", "Ministry", "Swallow",
                              "Silly", "Black Knight", "Camelot", "Coconut", "Parrot", "Shrubbery", "Taunt", "Argument"};

/*    qsort(strings, sizeof(strings) / sizeof(const char*), sizeof(const char*), compare_strings);

    print_string_array(strings, sizeof(strings) / sizeof(const char*));*/

    bsearch_result_t result;
    size_t num_strings = sizeof(strings) / sizeof(const char*);

    const char* search_string_HolyGrail = "Holy Grail";
    result = binary_search(&search_string_HolyGrail, strings, num_strings, sizeof(const char*), compare_strings);
    if (result.found) {
        printf("Found 'Holy Grail' at index %lld\n", result.index);
    } else {
        printf("'Holy Grail' not found\n");
    }

    const char* search_string_Parrot = "Parrot";
    result = binary_search(&search_string_Parrot, strings, num_strings, sizeof(const char*), compare_strings);
    if (result.found) {
        printf("Found 'Parrot' at index %lld\n", result.index);
    } else {
        printf("'Parrot' not found\n");
    }

    const char* search_string_Rabbit = "Rabbit";
    result = binary_search(&search_string_Rabbit, strings, num_strings, sizeof(const char*), compare_strings);
    if (result.found) {
        printf("Found 'Rabbit' at index %lld\n", result.index);
    } else {
        printf("'Rabbit' not found\n");
    }

    return 0;
}
