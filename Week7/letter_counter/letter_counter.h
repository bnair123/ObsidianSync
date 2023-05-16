//
// Created by Dawid Zalewski on 06/12/2020.
//

#ifndef WORDS_COUNTING_LETTERCOUNTER_H
#define WORDS_COUNTING_LETTERCOUNTER_H

#include <stdlib.h>

#define ALPHABET_SIZE ('Z' - 'A' + 1)

extern unsigned long count_letters(unsigned long counts[static 26], const char* str);

// prints the counts of letters in a nice way
extern void print_counts(unsigned long counts[static 26], _Bool sorted, _Bool asFrequencies);

extern const char* make_signature(const unsigned long counts[static 26]);

#endif //WORDS_COUNTING_LETTERCOUNTER_H
