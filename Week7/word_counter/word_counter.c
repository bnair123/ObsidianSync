#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counter.h"

void process_word(counter_t* counter, const char* word) {
    (void) counter;
    (void) word;
}

void process_line(counter_t* counter, char* line) {
    const char* sep = "\t” (),.;:?!\"\r\n'_-*";

    // TODO: How does this function work? (Activity 9)
    char* token = strtok(line, sep);
    while (token) {
        if (strlen(token) > 0) process_word(counter, token);
        token = strtok(NULL, sep);
    }
}

bool process_file(const char* filename, counter_t * counter) {
    FILE* fp = fopen(filename, "r");
    if (fp != NULL) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), fp)) {
            process_line(counter, buffer);
        }
        return true;
    }
    return false;
}

int main(void) {
    // TODO (Activity 9): Determine word count in file "alice0.txt"
    counter_t counter;
    counter_init(&counter, 10);

    // TODO (Activity 10):
    //  Make a copy of the counter's data into a new array
    //  use the qsort function to sort the pairs in the new array by value

    counter_destroy(&counter);
    return 0;
}
