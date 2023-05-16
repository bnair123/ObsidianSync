//
// Created by Dawid Zalewski on 06/12/2020.
//

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "letter_counter.h"
#include "langugage_recognizer.h"

unsigned long* process_file(const char* fileName) {

    unsigned long * counts = calloc(sizeof(unsigned long[ALPHABET_SIZE]), sizeof(unsigned long));

    FILE* fp = fopen(fileName, "r");
    unsigned long sum = 0;
    if (fp) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), fp)) {
            sum += count_letters(&counts[0], buffer);
        }
        printf("In total counted %ld letters.\n", sum);
    }
    return counts;
}

int main(void){
/*    *//*unsigned long counts[26] = {0};
    const char* text = "Alice in Wonderland.";
    (void) count_letters(&counts[0], text);
    print_counts(&counts[0], false, false);*//*

    unsigned long counts1[26] = {15,3,4,5,16,6,7,8,9,7,6,3,2,11,14,1,2,12,13};
    unsigned long counts2[26] = {16,4,7,5,20,7,4,3,14,5,9,1,2,18,6,12,9,13,9,15};

    assert(strcmp("eaosrn", make_signature(counts1)) == 0);
    assert(strcmp("enatir", make_signature(counts2)) == 0);*/
    const char* filenames[] = {
            "alice0.txt",
            "alice1.txt",
            "alice2.txt",
            "alice3.txt",
    };

    unsigned long* counts;
    const char* signatures;
    const char* languages;

    for (int i = 0; i < sizeof(filenames) / sizeof(filenames[0]); i++) {
        counts = process_file(filenames[i]);
        signatures = make_signature(counts);
        languages = match_language(signatures);

        printf("File: %s\nSignature: %s\nLanguage: %s\n\n", filenames[i], signatures, languages);
    }

    return 0;
}




