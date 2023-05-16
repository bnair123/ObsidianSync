# Week 7 - Dictionaries

This week's activities are split into two parts: counting letters and counting words. The code for these two parts can
be found in the directories `letter_counter` and `word_counter`. You'll work on the letter counting in the first three
activities, and on counting words in the last ones.

The `word_counter` subproject contains three targets: in `generic_functions` you'll work with two generic algorithms
that you've seen before - sorting and binary search. Activities five and six cover these two algorithms.

The `test_counter` target tests your implementation of a specialized kind of dictionary - the counter. You use this
target in activity seven.

Finally, you'll be counting words in a large text file, using the counter implementation. This is done in the last two
activities, and involves working with target `letter_counter`. The main file for this target is `word_counter.c`.

Note that the counter (which is, as mentioned before, a dictionary) data structure is in fact a set implemented as a sorted array.
It thus follows the same approach as the set you implemented in week 6.
The difference, though, is that the set implementation available in `set.h` is generic, which means that it can be used to store any type of data.
The counter / dictionary that you'll be implementing is thus basically a set that stores key-value pairs and keeps these pairs sorted by key.
You do need to provide the set implementation with a comparison function, which it uses to keep the elements in the set sorted -- it uses binary search internally when adding, removing and finding values.
For the counter functionality that you need to implement, you can use the functions already provided in `set.h`.

As always, make sure to use the provided `test_....` functions to test your code, and use an address sanitizer to verify
that your code is accessing memory correctly.
