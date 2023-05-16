cmake_minimum_required(VERSION 3.21)
project(dictionaries C)

set(CMAKE_C_STANDARD 17)

list(APPEND files alice0.txt alice1.txt alice2.txt alice3.txt)

foreach(file IN LISTS files)
    configure_file(${file} ./word_counter/${file} COPYONLY)
    configure_file(${file} ./letter_counter/${file} COPYONLY)
endforeach()

add_subdirectory(letter_counter)
add_subdirectory(word_counter)