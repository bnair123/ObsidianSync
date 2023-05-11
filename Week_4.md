# Week 4 - Stacks and Queues

  

## Team

  

>Members:

>

>- Member one Mate Gujabidze 

>- Member two Teodor Zlatkov

>

> Date: *day* *month* 2023

  

## Provided code

  

The `zip` file on Blackboard contains the C code for this week.

The project contains three *targets*: `stacks`, `queues` and `circular-buffer`.

  

Also, the project uses a static library that provides an array and a linked list.

If you're on Windows, then run your code on WSL.

  

## Activities

  

Make sure to have the activities signed off regularly to ensure progress is tracked.

  

### Activity 1: LIFO vs FIFO

  

**FIFO** is an abbreviation for **first in, first out**. It is a method for handling data structures where the **first element** is processed first and the **newest element** is processed last.

**LIFO** is an abbreviation for **Last in, first out** is the same as first in, last out (FILO). It is a method for handling data structures where the **last element** is processed first and the **first element** is processed last.

  

### Activity 2: Stacks and LIFO

  
A character sequence is processed character-by-character, from left to right. Whenever a letter is processed, that letter is pushed to a stack, and an asterisk causes an element to be popped and printed to the console. Give the sequence of values printed to the console when processing the following character sequence in this way. 

E A S * Y * Q U E * * * S T * * * I O * N * * *

Answer:
  SYEUQTSAONIE

### Activity 3: Pushes and pops
The source code available for this week contains a CMake executable target for working with stacks. The program performs a randomly intermixed sequence of pushes and pops, of the numbers zero to nine, and prints the popped numbers to the console. Study the source code of the program. One of the four following sequences can not occur. Which one is it, and why? 
(a) 4 3 2 1 0 9 8 7 6 5 
(b) 4 6 8 7 5 3 2 9 0 1 
(c) 2 5 6 7 4 8 9 3 1 0 
(d) 4 3 2 1 0 5 6 7 8 9

b because the sequence is off  

### Activity 4: Communication through a linked list
```c
bool try_read_deque(list_t *list, char *value) { 
return list_try_remove(list, FRONT, value); 
} 

void write_deque(list_t *list, char value) {
list_add(list, REAR, value); 
}
```
  
### Activity 5: FIFO and queues

Data is written to and read from a queue, such that the first value inserted into the queue is the first value retrieved from it. A letter means write (i.e., insert the letter into the queue) and an asterisk means read (i.e., retrieve and remove the letter from the queue) in the following sequence. Give the sequence of values returned by the read operation when the following sequence of operations is performed, from left to right, on an initially empty FIFO queue. 
  

EASYQUESTION

### Activity 6: Arrays, linked lists, and queues

  

| Operation                          |      Array      |   Linked List  |

| ---------------------------------- | --------------- | -------------- |

| Insert / remove **first** element  |     O(n)      |      O(1)    |

| Insert / remove **last** element   |     O(1)      |      O(1)    |

| Peek first / last element          |     O(1)      |      O(1)    |

  


  

### Activity 7: Time complexities, once again

  

| Operation                     | Time complexity |

| ----------------------------- | --------------- |

| Insert / remove first element |    O(1)       |

| Insert / remove last element  |    O(1)       |

| Peek first / last element     |    O(1)       |

  

  

### Activity 8: Clock arithmetic
```c
size_t buffer_get_rear_idx(const buffer_t *buffer) {  
(void) buffer;  
// TODO: Implement (Activity 8)  
return (buffer->head + buffer->count) % buffer->capacity;  
}
```


  

### Activity 9: Writing into a circular buffer

```c
  bool buffer_try_write(buffer_t *buffer, char character) {  
//(void) buffer;  
//(void) character;  
// TODO: Implement (Activity 9)  
//(void) write_idx;  
size_t write_idx = buffer_get_rear_idx(buffer);  
if (buffer->count == buffer->capacity) return false;  
buffer->data[write_idx] = character;  
buffer->count += 1;  
return true;  
}
```


### Activity 10: Reading from a circular buffer

  
```c
bool buffer_try_read(buffer_t *buffer, char *character) {  
//(void) buffer;  
//(void) character;  
// TODO: Implement (Activity 10)  
if(buffer->count == 0){  
return false;  
}  
*character = buffer->data[buffer->head];  
buffer->count -= 1;  
buffer->head = (buffer->head + 1) % buffer->capacity;  
return true;  
}
```



### Activity 11: Testing the queue

main function:
```c
#include <stdio.h>  
#include <stdlib.h>  
#include "buffer.h"  
#include "test_buffer.h"  
#include <week4lib/utils.h>  
  
/// Copies an input file to an output file via a buffer, character by character  
/// \param input The file to read from  
/// \param output The file to write to  
/// \param buffer The buffer to temporarily store the characters  
void copy_file(FILE * input, FILE * output, buffer_t * buffer) {  
char value, ch;  
ch = fgetc(input);  
while (!feof(input)) {  
// write some characters from the buffer into the output file  
while (random_double() < 0.5 && buffer_try_read(buffer, &value)) {  
fputc(value, output);  
}  
  
// read next character  
if (buffer_try_write(buffer, ch)) ch = fgetc(input);  
}  
// write remaining characters from the buffer into the output file  
while (buffer_try_read(buffer, &value)) {  
fputc(value, output);  
}  
}  
  
int main(void) {  
// Activity 8: implement buffer_get_rear_idx  
test_buffer_get_write_idx();  
  
// Activity 9: implement buffer_try_write  
test_buffer_try_write();  
  
// Activity 10: implement buffer_try_read  
test_buffer_try_read();  
  
// read file char by char, write output file char by char  
FILE * input = fopen("input.txt", "r");  
FILE * output = fopen("output.txt", "w");  
  
if (input == NULL) {  
fputs("error opening input file\n", stderr);  
return 1;  
}  
if (output == NULL) {  
fputs("error creating output file\n", stderr);  
return 1;  
}  
  
buffer_t * buffer = buffer_create(20);  
copy_file(input, output, buffer);  
buffer_destroy(buffer);  
free(buffer);  
  
fclose(input);  
fclose(output);  
  
return 0;  
}
```
  

The program gives the following output

```
test_buffer_get_write_idx PASS
test_buffer_try_write PASS
test_buffer_try_read PASS

Process finished with exit code 0

```
