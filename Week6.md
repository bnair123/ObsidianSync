# Week 6 - Sets

## Team

>Members:
>
>- Bharath Nair
>
> Date: *day* *month* 2023                                                   |      |

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

Download the provided project and open it in CLion.

### Activity 1: Comparing floating point numbers

You cannot compare floats or doubles as they are not exact representations of numbers. They are stored in binary form, and there is always some rounding error. This means that two doubles or floats that are mathematically equal may not be equal when stored in computer memory.
```c
bool equals_dbl(double d1, double d2) {  
    if( fabs(d1 - d2) < 0.00000001){  
        return true;  
    }  
    else{  
        return false;  
    }  
}  
// This works bc float point math is not 100% accurate so provide some margin of error
```
Output
``42.000000 and 42.000000 are equal
``42.000000 and 42.000000 are equal
``3.141593 and 3.141593 are equal
``3.141593 and 3.141593 are equal``

### Activity 2: Function pointers

```c
int add_ints(int a, int b) {  
    return a + b;  
}  
  
int multiply_ints(int x, int y) {  
    return x * y;  
}  
  
void fun_with_ints(int (*funptr)(int, int)) {  
    for (int r = 1; r <= 15; ++r) {  
        for (int c = 1; c <= 15; ++c) {  
            int result = funptr(r, c);  // Call the function passed to fun_with_ints  
            printf(" %5d", result);  
        }  
        printf("\n");  
    }  
    printf("\n\n");  
}
int main(void){
printf("Using the 'add' function:\n");  
fun_with_ints(add_ints);  
  
printf("Using the 'multiply' function:\n");  
fun_with_ints(multiply_ints);  
  
return 0;
}
```

```
Using the 'add' function:
     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16
     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17
     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18
     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19
     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20
     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21
     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22
     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23
    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24
    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25
    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26
    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27
    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28
    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29
    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30


Using the 'multiply' function:
     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15
     2     4     6     8    10    12    14    16    18    20    22    24    26    28    30
     3     6     9    12    15    18    21    24    27    30    33    36    39    42    45
     4     8    12    16    20    24    28    32    36    40    44    48    52    56    60
     5    10    15    20    25    30    35    40    45    50    55    60    65    70    75
     6    12    18    24    30    36    42    48    54    60    66    72    78    84    90
     7    14    21    28    35    42    49    56    63    70    77    84    91    98   105
     8    16    24    32    40    48    56    64    72    80    88    96   104   112   120
     9    18    27    36    45    54    63    72    81    90    99   108   117   126   135
    10    20    30    40    50    60    70    80    90   100   110   120   130   140   150
    11    22    33    44    55    66    77    88    99   110   121   132   143   154   165
    12    24    36    48    60    72    84    96   108   120   132   144   156   168   180
    13    26    39    52    65    78    91   104   117   130   143   156   169   182   195
    14    28    42    56    70    84    98   112   126   140   154   168   182   196   210
    15    30    45    60    75    90   105   120   135   150   165   180   195   210   225



Process finished with exit code 0
```


### Activity 3: Function implementations

```c
/// Adds a value to a set, if it is not already present
/// \param set The set to add the value to
/// \param value The value to add to the set
void set_add(set_t *set, double value) {  
    if (!ensure_capacity(set)) return;  
  
    // Check if the value is already present in the set.  
    bool is_present = false;  
    for (size_t i = 0; i < set->count; i++) {  
        if (set->eq_fun(set->data[i], value)) {  
            is_present = true;  
            break;        }  
    }  
  
    if (!is_present) {  
        set->data[set->count] = value;  
        set->count++;  
    }  
}

/// Removes a value from a set, if it is present
/// \param set The set to remove the value from
/// \param value The value to remove from the set
void set_remove(set_t *set, double value) {  
    size_t index = -1;  
    for (size_t i = 0; i < set->count; i++) {  
        if (set->eq_fun(set->data[i], value)) {  
            index = i;  
            break;        }  
    }  
  
    if (index == -1) return;  
  
    for (size_t i = index + 1; i < set->count; i++) {  
        set->data[i - 1] = set->data[i];  
    }  
  
    set->count--;  
}

/// Checks if a value is in the set
/// \param set The set to search
/// \param value The value to search for in the set
/// \return true if the value is present, false if it is not
bool set_contains(const set_t *set, double value) {  
    for (size_t i = 0; i < set->count; i++) {  
        if (set->eq_fun(set->data[i], value)) {  
            return true;  
        }  
    }  
    return false;  
}
```
Output
```
test_unsorted_set_contains PASS
test_unsorted_set_add PASS
test_unsorted_set_remove PASS

```

### Activity 4: Time complexity of unsorted set operations

| Operation | Time complexity |
|-----------| --------------- |
| Contains  |  O(n)              |
| Add       |     O(n)            |
| Remove    |        O(n)         |

The `contains` operation has a time complexity of O(n) because it iterates over all the elements in the set and compares them with the value.

The `add` operation has an ideal time complexity of O(1) because it first checks if the value is already present in the set. If the value is already present, the operation does nothing and returns. If the value is not already present, the operation adds the value to the set and returns.

The `remove` operation has a worst case time complexity of O(n) because it has to iterate over all the elements in the set to find the index of the value because in the worst case it may be at the end of the set. Once the index of the value is found, the operation can remove the value from the set in O(1) time.

### Activity 5: Binary search

Value to find: 46:

| Binary search step | lo  | hi  | mid |
|--------------------|-----|-----|-----|
| 1                  | 0   | 16  | 8  |
| 2                  | 9    | 16    | 12    |
| 3                  | 13    | 16    | 14    |
| 4                  | 13    | 14    | 13    |
| 5                  | N/A    | N/A    | N/A    |
There for it is at position 13

Value to find: 4:

| Binary search step | lo  | hi  | mid |
|--------------------|-----|-----|-----|
| 1                  | 0   | 16  | 8  |
| 2                  | 0    | 7    | 4    |
| 3                  | 5    | 7    |  6   |
| 4                  |   5  |  5   |  5   |
| 5                  |     |     |     |
Therefore at pos 5.

### Activity 6: Ordering doubles

```c
int cmp_dbl(double d1, double d2) {  
    if (fabs(d1 - d2) < 0.00000001) {  
        return 0;  
    }  
  
    // If the first value is smaller than the second, return -1.  
    if (d1 < d2) {  
        return -1;  
    }  
      
    // If the first value is greater than the second, return 1.  
    return 1;  
}
```
Output
```
compare(42.000000, 42.000000) == 0
compare(42.000000, 42.000000) == 0
compare(3.1415927, 3.1415929) == -1
compare(3.1415929, 3.1415927) == 1
```

### Activity 7: Implementing binary search

```c
size_t set_index_of(const set_t *set, double value) {  
    size_t lo = 0;  
    size_t hi = set->count;  
  
    while (lo < hi) {  
        size_t mid = (lo + (hi - lo)) / 2;  
  
        int cmp_result = set->cmp_fun(set->data[mid], value);  
        if (cmp_result == 0) {  
            return mid;  // Value found at index mid  
        } else if (cmp_result < 0) {  
            lo = mid + 1;  // Value is in the right half  
        } else {  
            hi = mid;  // Value is in the left half  
        }  
    }  
  
    return -1;  // Value not found, return the insertion point  
}
```
Output
```
test_sorted_set_index_of PASS
```



### Activity 8: Binary search - Time complexity

| Array size | Lookups |
|------------|---------|
| 16         | 5       |
| 32         |    6     |
| 64         |     6    |
| 128        |      8   |
| 256        |       9  |
| 1000       |  10       |
| 4000       |    12     |
| 10000      |      14   |
| 1048576    |        21 |

```c
// Create a set with 16 elements  
    const size_t sizes[] = {16, 32, 54, 128, 256, 1000, 4000, 10000, 1048576};  
    const size_t num_sizes = sizeof(sizes) / sizeof(sizes[0]);  
  
    for (size_t i = 0; i < num_sizes; i++) {  
        size_t set_size = sizes[i];  
  
        // Create a set and fill it with values  
        set_t* set = set_create(set_size, cmp_dbl);  
        for (size_t j = 0; j < set_size; j++) {  
            set->data[j] = j * 2.0;  
            set->count++;  
        }  
  
        // Test binary search comparisons  
        g_comparisons = 0; // Reset the global comparisons count  
        set_index_of(set, -1.0); // Search for a value not present  
        printf("Set Size: %zu, Comparisons: %zu\n", set_size, g_comparisons);  
  
        // Destroy the set to free memory  
        set_destroy(set);
```


### Activity 9: Finalizing the sorted array

```c
/// Adds a value to a set, if it is not already present
/// \param set The set to add the value to
/// \param value The value to add to the set
void set_add(set_t * set, double value) {  
    size_t index = set_index_of(set, value);  
  
    if (index >= set->count || set->cmp_fun(set->data[index], value) != 0) {  
        if (!ensure_capacity(set)) return;  
  
        // Shift elements to the right to make space for the new value  
        for (size_t i = set->count; i > index; i--) {  
            set->data[i] = set->data[i - 1];  
        }  
  
        set->data[index] = value;  
        set->count++;  
    }  
}

/// Removes a value from a set, if it is present
/// \param set The set to remove the value from
/// \param value The value to remove from the set
void set_remove(set_t * set, double value) {  
    size_t index = set_index_of(set, value);  
  
    if (index < set->count && set->cmp_fun(set->data[index], value) == 0) {  
        // Shift elements to the left to remove the value  
        for (size_t i = index; i < set->count - 1; i++) {  
            set->data[i] = set->data[i + 1];  
        }  
  
        set->count--;  
    }  
}

/// Checks if a value is in the set
/// \param set The set to search
/// \param value The value to search for in the set
/// \return true if the value is present, false if it is not
bool set_contains(const set_t * set, double value) {  
    if (set->count == 0) {  
        return false;  
    }  
    size_t index = set_index_of(set, value);  
  
    // If the index is not -1, then the value is in the set.  
    return (index < set->count && set->cmp_fun(set->data[index], value) == 0);  
}
```

Record your answer here
```
test_sorted_set_contains PASS
test_sorted_set_add PASS
test_sorted_set_remove PASS
```


### Activity 10: Time complexity of the sorted set

| Operation | Time complexity |
|-----------| --------------- |
| Add       |  O(n)               |
| Remove    |   O(n)              |
| Contains  |      O(log n)           |

For `add` the lookup has O(log n) but the shift has a normal for loop
For ``remove``  the lookup has O(log n) but the shift has a normal for loop
For ``contains`` its only the lookup therefor only O(log n)
