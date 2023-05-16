add_executable(letter_counter main_letters.c letter_counter.c letter_counter.h langugage_recognizer.c langugage_recognizer.h)

target_compile_options(letter_counter PRIVATE -Wall -Wextra -pedantic -Werror)

if (USE_ASAN)
    target_compile_options(letter_counter PRIVATE -fsanitize=address)
    target_link_options(letter_counter PRIVATE -fsanitize=address)
endif()
