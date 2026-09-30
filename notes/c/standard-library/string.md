# `<string.h>`

`<string.h>` provides functions for manipulating **null-terminated strings**, character arrays, and raw blocks of memory.

Most of its functions operate on arrays of `char`, but several functions such as `memcpy()` and `memset()` work with arbitrary memory.

```c
#include <string.h>
```

## String Functions

| Function                  | Prototype                                                                | Description                                                                                 |
| ------------------------- | ------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------- |
| [`strcpy()`](#strcpy)     | `char *strcpy(char * restrict s1, const char * restrict s2);`            | Copies a null-terminated string from `s2` to `s1`.                                          |
| [`strncpy()`](#strncpy)   | `char *strncpy(char * restrict s1, const char * restrict s2, size_t n);` | Copies up to `n` characters from `s2` to `s1`. May not null-terminate.                      |
| [`strcat()`](#strcat)     | `char *strcat(char * restrict s1, const char * restrict s2);`            | Appends the string `s2` to the end of `s1`.                                                 |
| [`strncat()`](#strncat)   | `char *strncat(char * restrict s1, const char * restrict s2, size_t n);` | Appends at most `n` characters from `s2` to `s1`, then adds `'\0'`.                         |
| [`strcmp()`](#strcmp)     | `int strcmp(const char *s1, const char *s2);`                            | Compares two null-terminated strings.                                                       |
| [`strncmp()`](#strncmp)   | `int strncmp(const char *s1, const char *s2, size_t n);`                 | Compares at most the first `n` characters of two strings.                                   |
| [`strchr()`](#strchr)     | `char *strchr(const char *s, int c);`                                    | Finds the first occurrence of character `c` in `s`.                                         |
| [`strrchr()`](#strrchr)   | `char *strrchr(const char *s, int c);`                                   | Finds the last occurrence of character `c` in `s`.                                          |
| [`strspn()`](#strspn)     | `size_t strspn(const char *s1, const char *s2);`                         | Returns the length of the initial part of `s1` containing only characters from `s2`.        |
| [`strcspn()`](#strcspn)   | `size_t strcspn(const char *s1, const char *s2);`                        | Returns the length of the initial part of `s1` containing none of the characters from `s2`. |
| [`strpbrk()`](#strpbrk)   | `char *strpbrk(const char *s1, const char *s2);`                         | Finds the first character in `s1` that matches any character in `s2`.                       |
| [`strstr()`](#strstr)     | `char *strstr(const char *s1, const char *s2);`                          | Finds the first occurrence of string `s2` inside `s1`.                                      |
| [`strtok()`](#strtok)     | `char *strtok(char * restrict s1, const char * restrict s2);`            | Splits a string into tokens using characters from `s2` as delimiters.                       |
| [`strlen()`](#strlen)     | `size_t strlen(const char *s);`                                          | Returns the length of a string, excluding the terminating `'\0'`.                           |
| [`strerror()`](#strerror) | `char *strerror(int errnum);`                                            | Returns a message describing an error number.                                               |

## Memory Functions

| Function                | Prototype                                                                | Description                                                  |
| ----------------------- | ------------------------------------------------------------------------ | ------------------------------------------------------------ |
| [`memcpy()`](#memcpy)   | `void *memcpy(void * restrict s1, const void * restrict s2, size_t n);`  | Copies `n` bytes from `s2` to `s1`. Memory must not overlap. |
| [`memmove()`](#memmove) | `void *memmove(void *s1, const void *s2, size_t n);`                     | Copies `n` bytes and safely handles overlapping memory.      |
| [`memset()`](#memset)   | `void *memset(void *s, int c, size_t n);`                                | Sets the first `n` bytes of `s` to the byte value `c`.       |
| [`memcmp()`](#memcmp)   | `int memcmp(const void *s1, const void *s2, size_t n);`                  | Compares the first `n` bytes of two memory regions.          |
| [`memchr()`](#memchr)   | `void *memchr(const void *s, int c, size_t n);`                          | Searches the first `n` bytes of `s` for byte `c`.            |

> **Note:** `restrict` is a C99 feature. In C89/C90, the same functions existed without `restrict` in their declarations.

---

# String Copying

## `strcpy()`

```c
char *strcpy(char * restrict s1, const char * restrict s2);
```

Copies the string from `s2` to `s1`, including the terminating `'\0'`.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char source[] = "Hello";
    char destination[10];

    strcpy(destination, source);

    printf("%s\n", destination);

    return 0;
}
```

`destination` must have enough space for the entire string, including `'\0'`.

### Important

This is unsafe if the destination is too small:

```c
char destination[4];

strcpy(destination, "Hello");  /* ERROR: buffer overflow */
```

---

## `strncpy()`

```c
char *strncpy(char * restrict s1, const char * restrict s2, size_t n);
```

Copies at most `n` characters from `s2`.

```c
char destination[10];

strncpy(destination, "Hello", sizeof(destination));
```

Unlike `strcpy()`, `strncpy()` does **not always add a null terminator**.

For example:

```c
char destination[5];

strncpy(destination, "Hello", sizeof(destination));
```

The result is:

```text
'H' 'e' 'l' 'l' 'o'
```

There is no room for `'\0'`.

Therefore, don't assume that `strncpy()` always produces a valid C string.

---

# String Concatenation

## `strcat()`

```c
char *strcat(char * restrict s1, const char * restrict s2);
```

Appends `s2` to the end of `s1`.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char message[20] = "Hello ";

    strcat(message, "World");

    printf("%s\n", message);

    return 0;
}
```

Result:

```text
Hello World
```

The destination must have enough unused space for the appended string and its null terminator.

---

## `strncat()`

```c
char *strncat(char * restrict s1, const char * restrict s2, size_t n);
```

Appends at most `n` characters from `s2`.

Unlike `strncpy()`, `strncat()` always adds a terminating `'\0'`.

```c
char message[20] = "Hello ";

strncat(message, "World", 3);
```

Result:

```text
Hello Wor
```

---

# String Comparison

## `strcmp()`

```c
int strcmp(const char *s1, const char *s2);
```

Compares two strings lexicographically.

It returns:

```text
< 0    s1 comes before s2
  0    s1 and s2 are equal
> 0    s1 comes after s2
```

Example:

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    if (strcmp("apple", "apple") == 0)
        printf("Strings are equal\n");

    return 0;
}
```

Do not check for a specific positive or negative value:

```c
if (strcmp(a, b) == 1)    /* WRONG */
```

Only the sign of the result matters.

---

## `strncmp()`

```c
int strncmp(const char *s1, const char *s2, size_t n);
```

Compares at most the first `n` characters.

```c
if (strncmp("Hello World", "Hello", 5) == 0)
    printf("First five characters match\n");
```

---

# String Length

## `strlen()`

```c
size_t strlen(const char *s);
```

Returns the number of characters before the terminating `'\0'`.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[] = "Hello";

    printf("Length: %lu\n", (unsigned long)strlen(text));

    return 0;
}
```

For:

```c
"Hello"
```

`strlen()` returns:

```text
5
```

The `'\0'` is **not included**.

### Important

`strlen()` must search through the string until it finds `'\0'`.

Therefore, its complexity is **O(n)**.

---

# Character Searching

## `strchr()`

```c
char *strchr(const char *s, int c);
```

Finds the **first occurrence** of a character.

```c
char text[] = "Hello World";

char *p = strchr(text, 'W');

if (p != NULL)
    printf("%s\n", p);
```

Output:

```text
World
```

The returned pointer points directly into the original string.

---

## `strrchr()`

```c
char *strrchr(const char *s, int c);
```

Finds the **last occurrence** of a character.

```c
char text[] = "hello world";

char *p = strrchr(text, 'o');

if (p != NULL)
    printf("%s\n", p);
```

Output:

```text
orld
```

---

# Substring Searching

## `strstr()`

```c
char *strstr(const char *s1, const char *s2);
```

Finds the first occurrence of `s2` inside `s1`.

```c
char text[] = "Hello embedded world";

char *p = strstr(text, "embedded");

if (p != NULL)
    printf("%s\n", p);
```

Output:

```text
embedded world
```

If the substring is not found, `NULL` is returned.

---

# Character-Set Searching

## `strspn()`

```c
size_t strspn(const char *s1, const char *s2);
```

Returns the length of the initial portion of `s1` containing **only characters found in `s2`**.

```c
size_t n = strspn("12345abc", "0123456789");
```

Result:

```text
5
```

The first five characters are digits.

---

## `strcspn()`

```c
size_t strcspn(const char *s1, const char *s2);
```

Returns the length of the initial portion of `s1` containing **none of the characters found in `s2`**.

```c
size_t n = strcspn("hello,world", ",");
```

Result:

```text
5
```

The first comma occurs after five characters.

---

## `strpbrk()`

```c
char *strpbrk(const char *s1, const char *s2);
```

Finds the first character in `s1` that matches **any character** in `s2`.

```c
char text[] = "hello world";

char *p = strpbrk(text, "aeiou");

if (p != NULL)
    printf("%c\n", *p);
```

Output:

```text
e
```

---

# Tokenization

## `strtok()`

```c
char *strtok(char * restrict s1, const char * restrict s2);
```

Splits a string into tokens using characters from `s2` as delimiters.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[] = "one,two,three";

    char *token = strtok(text, ",");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
```

Output:

```text
one
two
three
```

### Important

`strtok()` **modifies the original string** by replacing delimiters with `'\0'`.

Therefore, don't pass a string literal:

```c
strtok("one,two,three", ",");   /* WRONG */
```

Use a modifiable array:

```c
char text[] = "one,two,three";
```

`strtok()` also maintains internal state between calls, which makes it unsuitable for some reentrant or nested parsing situations.

---

# Memory Functions

Unlike the string functions, these functions operate on **raw bytes** and do not look for `'\0'`.

## `memcpy()`

```c
void *memcpy(void * restrict s1, const void * restrict s2, size_t n);
```

Copies `n` bytes from `s2` to `s1`.

```c
char source[] = "Hello";
char destination[10];

memcpy(destination, source, sizeof(source));
```

### Important

The source and destination **must not overlap**.

For overlapping regions, use `memmove()`.

---

## `memmove()`

```c
void *memmove(void *s1, const void *s2, size_t n);
```

Copies `n` bytes while correctly handling overlapping memory regions.

```c
char text[] = "abcdef";

memmove(text + 2, text, 4);
```

Because the source and destination overlap, `memmove()` should be used instead of `memcpy()`.

---

## `memset()`

```c
void *memset(void *s, int c, size_t n);
```

Sets the first `n` bytes of memory to the value represented by the unsigned-char conversion of `c`.

```c
char buffer[10];

memset(buffer, 0, sizeof(buffer));
```

This sets every byte to zero.

### Common mistake

`memset()` works **byte by byte**.

Therefore:

```c
int array[10];

memset(array, 1, sizeof(array));
```

does **not** set every integer to `1`.

Instead, every byte becomes `0x01`.

For a typical 32-bit `int`, each element would become:

```text
0x01010101
```

---

## `memcmp()`

```c
int memcmp(const void *s1, const void *s2, size_t n);
```

Compares the first `n` bytes of two memory regions.

Return value:

```text
< 0    first differing byte in s1 is smaller
  0    all n bytes are equal
> 0    first differing byte in s1 is larger
```

Example:

```c
char a[] = "abc";
char b[] = "abc";

if (memcmp(a, b, 3) == 0)
    printf("Memory is equal\n");
```

Unlike `strcmp()`, `memcmp()` does not stop at `'\0'`.

---

## `memchr()`

```c
void *memchr(const void *s, int c, size_t n);
```

Searches the first `n` bytes of a memory region for a byte.

```c
char data[] = { 10, 20, 30, 40, 50 };

int *p = memchr(data, 30, sizeof(data));
```

The return value is a pointer to the first matching byte, or `NULL` if no match is found.

Because `memchr()` returns `void *`, it can be converted to an appropriate pointer type.

---

# Error Messages

## `strerror()`

```c
char *strerror(int errnum);
```

Returns a pointer to an implementation-defined string describing an error number.

It is commonly used with `errno`.

```c
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("missing.txt", "r");

    if (file == NULL)
        printf("Error: %s\n", strerror(errno));

    return 0;
}
```

`strerror()` is useful when converting an error number into a human-readable message.

---

# String vs Memory Functions

The most important distinction is whether the operation is **string-oriented** or **byte-oriented**.

|String Function|Memory Function|Main Difference|
|---|---|---|
|`strcpy()`|`memcpy()`|Strings vs raw bytes|
|`strncpy()`|—|Bounded string copying|
|`strcat()`|—|String concatenation|
|`strcmp()`|`memcmp()`|Null-terminated strings vs fixed number of bytes|
|`strlen()`|—|Searches for `'\0'`|
|`strchr()`|`memchr()`|Searches string vs fixed number of bytes|

For example:

```c
char a[] = "abc\0xyz";
```

`strlen()` sees:

```text
abc
```

because it stops at `'\0'`.

But:

```c
memcmp(a, "abc\0xyz", 7);
```

can compare all seven bytes because `memcmp()` does not treat `'\0'` specially.

---

# Important Rules

### Always provide enough space

```c
char destination[6];

strcpy(destination, "Hello");
```

Correct because:

```text
H e l l o \0
```

requires 6 bytes.

---

### `strlen()` does not include `'\0'`

```c
strlen("Hello") == 5
```

but the storage required is:

```text
5 + 1 = 6 bytes
```

---

### `strncpy()` may not terminate

```c
char buffer[5];

strncpy(buffer, "Hello", sizeof(buffer));
```

does not leave room for `'\0'`.

---

### `memcpy()` does not handle overlap

```c
memcpy(buffer + 2, buffer, 5);   /* undefined behavior if regions overlap */
```

Use:

```c
memmove(buffer + 2, buffer, 5);
```

instead.

---

### `memset()` works with bytes

```c
memset(buffer, 0, sizeof(buffer));
```

is commonly used to zero memory.

But:

```c
memset(array, 1, sizeof(array));
```

does not initialize an integer array to `1`.