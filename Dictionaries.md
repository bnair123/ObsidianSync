# Week 7 - Dictionaries

## Team

>Members:
>
>-  Bharath Nair
>
> Date: *19* *May* 2023                                                   |      |

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

Download the provided project and open it in CLion.

### Activity 1: The ctype header file

| # | Function | Description |
| --- | --- | --- |
|1 | isalnum() | Checks if the argument is an alphanumeric character. 
|2 | isalpha() | Checks if the argument is an alphabetic character. 
|3 | iscntrl() | Checks if the argument is a control character. 
|4 | isdigit() | Checks if the argument is a numeric character. 
|5 | isgraph() | Checks if the argument is a graphic character. 
|6 | islower() | Checks if the argument is a lowercase alphabetic character. 
|7 | isprint() | Checks if the argument is a printable character. 
|8 | ispunct() | Checks if the argument is a punctuation character. 
|9 | isspace() | Checks if the argument is a whitespace character. 
|10 | isupper() | Checks if the argument is an uppercase alphabetic character. 
|11 | isxdigit() | Checks if the argument is a hexadecimal digit character. 
|12 | tolower() | Converts the argument to lowercase. 
|13 | toupper() | Converts the argument to uppercase.

### Activity 2: Count letters in a string

```c
unsigned long count_letters(unsigned long counts[static 26], const char* str){  
    unsigned long count = 0;  
  
    for (int i = 0; str[i] != '\0'; ++i) {  
        if (isalpha(str[i])) {  
            char letter = tolower(str[i]);  
            counts[letter - 'a']++;  
            count++;  
        }  
    }  
  
    return count;  
}

int main(void){
	unsigned long counts[26] = {0};
	const char* text = "The Quick Brown Fox Jumps Over The Lazy Dog.";
	unsigned long total = countLetters(&counts[0], text);
	assert(35 == total);
	printCounts(&counts[0], false, true);
}
```
Output:
```
a: 3.85%
b: 0.00%
c: 3.85%
d: 0.00%
e: 11.54%
f: 0.00%
g: 3.85%
h: 7.69%
i: 3.85%
j: 0.00%
k: 3.85%
l: 0.00%
m: 3.85%
n: 3.85%
o: 11.54%
p: 3.85%
q: 0.00%
r: 7.69%
s: 3.85%
t: 0.00%
u: 7.69%
v: 3.85%
w: 3.85%
x: 3.85%
y: 3.85%
z: 3.85%
```


### Activity 3: Recognizing languages

```c
const char* make_signature(const unsigned long counts[static 26]){
    static char signature[7]; //Buffer ready to be stored into
    signature[6] = '\0'; // null terminator for the string (stops it at the end)

    unsigned long sorted_counts[26];
    size_t shift = sort_counts((unsigned long*)counts, sorted_counts); //Sort using sort_counts

    for (int i = 0; i < 6; ++i) { //copy only the first 5
        signature[i] = (char)(sorted_counts[i] >> shift); //right shift operation. value sorted_counts[i] is shifted to the right by the number of positions specified by the shift variable.
    }

    return &signature; //shouldn't really use locally made pointer
}

int main(void) {
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
```

| File       | Signature | Language |
| ---------- | --------- | -------- |
| alice0.txt |     etaoin      |     en     |
| alice1.txt |      iantes      |   it       |
| alice2.txt |        eaionr   |     it     |
| alice3.txt |      enisra     |   de       |

### Activity 4: Find out: dictionaries in other languages

| Language | Dictionary type |
|------------|-------------------|
| C# | Dictionary<TKey, TValue> |
| Python | dict|
| C++ | unordered_map |
| Java | HashMap<K, V> |
| Swift | Dictionary<Key, Value> |

Python Functions:
`dict[key] = value, del dict[key], key in dict`, `dict[key]`
C# functions:
`dict.Add(key, value)`, `dict.Remove(key)`, `dict.ContainsKey(key)`, `dict[key]`

### Activity 5: Generic sorting in C

```c
int compare_strings(const void *a, const void *b) {  
    const char *string1 = *(const char **)a; //has to be converted to string from void bc ortherwise strcmp does not work  
    const char *string2 = *(const char **)b;  
  
    return strcmp(string1, string2);  
}

int main(void) {
    const char * strings[] = {"Spam", "Cheese", "Knights", "Holy Grail", "Lumberjack", "Ministry", "Swallow",  
                          "Silly", "Black Knight", "Camelot", "Coconut", "Parrot", "Shrubbery", "Taunt", "Argument"};  
  
qsort(strings, sizeof(strings) / sizeof(const char*), sizeof(const char*), compare_strings);  
  
print_string_array(strings, sizeof(strings) / sizeof(const char*));
	return 0;
}
```
Output
```
[Argument, Black Knight, Camelot, Cheese, Coconut, Holy Grail, Knights, Lumberjack, Ministry, Parrot, Shrubbery, Silly,
Spam, Swallow, Taunt]
```
### Activity 6: Generic searching in C

```c
int main(void) {
    const char * strings[] = {"Spam", "Cheese", "Knights", "Holy Grail", "Lumberjack", "Ministry", "Swallow",
                              "Silly", "Black Knight", "Camelot", "Coconut", "Parrot", "Shrubbery", "Taunt", "Argument"};
	bsearch_result_t result;  
size_t num_strings = sizeof(strings) / sizeof(const char*);  
  
const char* search_string_HolyGrail = "Holy Grail";  
result = binary_search(&search_string_HolyGrail, strings, num_strings, sizeof(const char*), compare_strings);  
if (result.found) {  
    printf("Found 'Holy Grail' at index %lld\n", result.index);  
} else {  
    printf("'Holy Grail' not found\n");  
}  
  
const char* search_string_parrot = "Parrot";  
result = binary_search(&search_string_parrot, strings, num_strings, sizeof(const char*), compare_strings);  
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
```

output:
```
Found 'Holy Grail' at index 3
Found 'Holy Grail' at index 11
'Rabbit' not found
```

### Activity 7: Counter - function implementations

```c
counter_t *counter_init(counter_t *counter, size_t capacity) {
}

const pair_t *counter_get_pair_at(const counter_t *counter, size_t index) {
}

size_t counter_get_count(const counter_t *counter, const char *string) {
}

void counter_increment(counter_t *counter, const char *string) {
}

void counter_destroy(counter_t *counter) {
}
```

### Activity 8: Find out: function `strtok`

Record your answer here

### Activity 9: How many words?

Record your answer here

### Activity 10: Most frequent words

```c
int main(void) {

}
```

Record your answer here

## Looking back

### What we've learnt

Formulate at least one lesson learned.

### What were the surprises

Fill in...

### What problems we've encountered

Fill in...

### What was or still is unclear

Fill in...

### How did the group perform?

How was the collaboration? What were the reasons for hick-ups? What worked well? What can be improved next time?