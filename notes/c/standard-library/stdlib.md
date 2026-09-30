# `<stdlib.h>`

## Overview

The `<stdlib.h>` header provides general-purpose utility functions for:

* Dynamic memory allocation
* Program termination
* Numeric string conversion
* Pseudo-random number generation
* Integer arithmetic
* Searching and sorting
* Environment and process control

## Functions

| Function                | Prototype                                                                                                                 | Description                                                                          |
| ----------------------- | ------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| [`malloc()`](#malloc)   | `void *malloc(size_t size);`                                                                                              | Allocates `size` bytes of uninitialized memory.                                      |
| [`calloc()`](#calloc)   | `void *calloc(size_t nmemb, size_t size);`                                                                                | Allocates memory for an array of `nmemb` elements and initializes all bytes to zero. |
| [`realloc()`](#realloc) | `void *realloc(void *ptr, size_t size);`                                                                                  | Changes the size of a previously allocated memory block.                             |
| [`free()`](#free)       | `void free(void *ptr);`                                                                                                   | Releases dynamically allocated memory.                                               |
| [`abort()`](#abort)     | `void abort(void);`                                                                                                       | Terminates the program abnormally.                                                   |
| [`atexit()`](#atexit)   | `int atexit(void (*func)(void));`                                                                                         | Registers a function to be called when the program terminates normally.              |
| [`exit()`](#exit)       | `void exit(int status);`                                                                                                  | Terminates the program normally.                                                     |
| [`_Exit()`](#_Exit)     | `void _Exit(int status);`                                                                                                 | Terminates the program immediately without performing normal termination processing. |
| [`getenv()`](#getenv)   | `char *getenv(const char *name);`                                                                                         | Retrieves the value of an environment variable.                                      |
| [`system()`](#system)   | `int system(const char *string);`                                                                                         | Passes a command to the host environment for execution.                              |
| [`rand()`](#rand)       | `int rand(void);`                                                                                                         | Generates a pseudo-random integer.                                                   |
| [`srand()`](#srand)     | `void srand(unsigned int seed);`                                                                                          | Seeds the pseudo-random number generator.                                            |
| [`atoi()`](#atoi)       | `int atoi(const char *nptr);`                                                                                             | Converts a string to an `int`.                                                       |
| [`atol()`](#atol)       | `long int atol(const char *nptr);`                                                                                        | Converts a string to a `long int`.                                                   |
| [`strtol()`](#strtol)   | `long int strtol(const char * restrict nptr, char ** restrict endptr, int base);`                                         | Converts a string to a `long int` with a specified base.                             |
| [`strtoul()`](#strtoul) | `unsigned long int strtoul(const char * restrict nptr, char ** restrict endptr, int base);`                               | Converts a string to an `unsigned long int` with a specified base.                   |
| [`strtod()`](#strtod)   | `double strtod(const char * restrict nptr, char ** restrict endptr);`                                                     | Converts a string to a `double`.                                                     |
| [`abs()`](#abs)         | `int abs(int j);`                                                                                                         | Returns the absolute value of an `int`.                                              |
| [`labs()`](#labs)       | `long int labs(long int j);`                                                                                              | Returns the absolute value of a `long int`.                                          |
| [`div()`](#div)         | `div_t div(int numer, int denom);`                                                                                        | Performs integer division and returns both quotient and remainder.                   |
| [`ldiv()`](#ldiv)       | `ldiv_t ldiv(long int numer, long int denom);`                                                                            | Performs `long int` division and returns both quotient and remainder.                |
| [`bsearch()`](#bsearch) | `void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));` | Searches an array using binary search.                                               |
| [`qsort()`](#qsort)     | `void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));`                           | Sorts an array using a comparison function.                                          |

---

## 1. Dynamic Memory

### `malloc()`

```c
void *malloc(size_t size);
```

`malloc()` allocates a block of memory containing at least `size` bytes.

```c
int *numbers = malloc(5 * sizeof(*numbers));

if (numbers == NULL)
    return 1;
```

The contents of newly allocated memory are **indeterminate**.

```c
int *numbers = malloc(5 * sizeof(*numbers));

/* Do not assume these are zero */
```

The allocated memory must eventually be released with `free()`.

```c
free(numbers);
```

---

### `calloc()`

```c
void *calloc(size_t nmemb, size_t size);
```

`calloc()` allocates memory for an array and initializes all allocated bytes to zero.

```c
int *numbers = calloc(5, sizeof(*numbers));

if (numbers == NULL)
    return 1;
```

For integer types, zero-initialized storage can be used as zero values.

```c
for (size_t i = 0; i < 5; i++)
    printf("%d\n", numbers[i]);
```

---

### `realloc()`

```c
void *realloc(void *ptr, size_t size);
```

`realloc()` changes the size of an existing allocation.

```c
int *numbers = malloc(5 * sizeof(*numbers));

int *tmp = realloc(numbers, 10 * sizeof(*numbers));

if (tmp == NULL) {
    free(numbers);
    return 1;
}

numbers = tmp;
```

If the new size is larger, the newly added portion has **indeterminate values**. `realloc()` does not initialize the new memory.

A temporary pointer should be used so that the original allocation is not lost if `realloc()` fails.

---

### `free()`

```c
void free(void *ptr);
```

`free()` releases memory allocated by `malloc()`, `calloc()`, or `realloc()`.

```c
int *numbers = malloc(10 * sizeof(*numbers));

if (numbers == NULL)
    return 1;

/* use numbers */

free(numbers);
```

After `free()`, the pointer becomes invalid to dereference.

```c
free(numbers);
numbers = NULL;
```

Setting the pointer to `NULL` is useful when the pointer will remain in scope and might otherwise accidentally be reused.

---

## 2. Program Termination

### `exit()`

```c
void exit(int status);
```

`exit()` terminates the program normally.

```c
exit(EXIT_SUCCESS);
```

or:

```c
exit(EXIT_FAILURE);
```

The macros `EXIT_SUCCESS` and `EXIT_FAILURE` are also provided by `<stdlib.h>`.

Functions registered with `atexit()` are called during normal termination.

---

### `abort()`

```c
void abort(void);
```

`abort()` terminates the program abnormally.

```c
if (ptr == NULL)
    abort();
```

Unlike `exit()`, it does not perform normal program termination processing.

---

### `atexit()`

```c
int atexit(void (*func)(void));
```

`atexit()` registers a function that will be called when the program terminates normally.

```c
#include <stdio.h>
#include <stdlib.h>

void cleanup(void)
{
    printf("Cleaning up...\n");
}

int main(void)
{
    atexit(cleanup);

    printf("Program running\n");

    return 0;
}
```

Multiple functions can be registered. They are called in reverse order of registration.

---

### `_Exit()`

```c
void _Exit(int status);
```

`_Exit()` terminates the program immediately.

```c
_Exit(EXIT_FAILURE);
```

It does not perform the normal termination processing performed by `exit()`.

`_Exit()` was introduced in C99.

---

## 3. String Conversion

### `atoi()`

```c
int atoi(const char *nptr);
```

`atoi()` converts the initial portion of a string to an `int`.

```c
int value = atoi("123");

printf("%d\n", value);
```

It is simple but provides no way to detect conversion errors.

For more robust conversion, use `strtol()`.

---

### `atol()`

```c
long int atol(const char *nptr);
```

`atol()` converts a string to a `long int`.

```c
long value = atol("123456");

printf("%ld\n", value);
```

Like `atoi()`, it provides limited error handling.

---

### `strtol()`

```c
long int strtol(const char * restrict nptr, char ** restrict endptr, int base);
```

`strtol()` converts a string to a `long int` and provides much better control over the conversion.

```c
char *end;

long value = strtol("123abc", &end, 10);

printf("value: %ld\n", value);
printf("remaining: %s\n", end);
```

The `base` argument specifies the number system:

```c
strtol("123", NULL, 10);  /* decimal */
strtol("7B",  NULL, 16);  /* hexadecimal */
strtol("101", NULL, 2);   /* binary */
```

`endptr` points to the first character that was not part of the converted number.

---

### `strtoul()`

```c
unsigned long int strtoul(const char * restrict nptr, char ** restrict endptr, int base);
```

`strtoul()` is the unsigned counterpart of `strtol()`.

```c
char *end;

unsigned long value = strtoul("123", &end, 10);
```

It is useful when converting strings representing unsigned values.

---

### `strtod()`

```c
double strtod(const char * restrict nptr, char ** restrict endptr);
```

`strtod()` converts a string to a `double`.

```c
char *end;

double value = strtod("3.14159", &end);

printf("%f\n", value);
```

Like `strtol()`, `endptr` identifies where conversion stopped.

---

## 4. Random Numbers

### `rand()`

```c
int rand(void);
```

`rand()` generates a pseudo-random integer between `0` and `RAND_MAX`.

```c
int value = rand();

printf("%d\n", value);
```

To generate a value in a range:

```c
int value = rand() % 10;
```

This produces values from `0` through `9`, although modulo reduction can introduce bias.

---

### `srand()`

```c
void srand(unsigned int seed);
```

`srand()` initializes the pseudo-random number generator.

```c
srand(42);

int value = rand();
```

Using the same seed produces the same sequence.

A common example is seeding with the current time:

```c
#include <stdlib.h>
#include <time.h>

srand((unsigned)time(NULL));
```

---

## 5. Integer Utilities

### `abs()`

```c
int abs(int j);
```

`abs()` returns the absolute value of an `int`.

```c
int value = -42;

printf("%d\n", abs(value));
```

Result:

```text
42
```

---

### `labs()`

```c
long int labs(long int j);
```

`labs()` performs the same operation for `long int`.

```c
long value = -123456L;

printf("%ld\n", labs(value));
```

---

### `div()`

```c
div_t div(int numer, int denom);
```

`div()` performs integer division and returns both quotient and remainder.

```c
typedef struct {
    int quot;
    int rem;
} div_t;
```

```c
div_t result = div(17, 5);

printf("quotient: %d\n", result.quot);
printf("remainder: %d\n", result.rem);
```

Result:

```text
quotient: 3
remainder: 2
```

---

### `ldiv()`

```c
ldiv_t ldiv(long int numer, long int denom);
```

`ldiv()` is the `long int` version of `div()`.

```c
typedef struct {
    long int quot;
    long int rem;
} ldiv_t;
```

```c
ldiv_t result = ldiv(100L, 30L);

printf("quotient: %ld\n", result.quot);
printf("remainder: %ld\n", result.rem);
```

---

## 6. Searching and Sorting

### `qsort()`

```c
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
```

`qsort()` sorts an array using a user-provided comparison function.

```c
#include <stdlib.h>

int compare_ints(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main(void)
{
    int numbers[] = {4, 1, 5, 2, 3};

    qsort(
        numbers,
        5,
        sizeof(numbers[0]),
        compare_ints
    );
}
```

After sorting:

```text
1 2 3 4 5
```

The comparison function must return:

* negative value if `a < b`
* zero if `a == b`
* positive value if `a > b`

---

### `bsearch()`

```c
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
```

`bsearch()` performs a binary search on a **sorted** array.

```c
int key = 3;

int *result = bsearch(
    &key,
    numbers,
    5,
    sizeof(numbers[0]),
    compare_ints
);

if (result != NULL)
    printf("Found: %d\n", *result);
```

The array must already be sorted according to the same comparison function.

---

## 7. Environment and System Functions

### `getenv()`

```c
char *getenv(const char *name);
```

`getenv()` retrieves the value of an environment variable.

```c
char *path = getenv("PATH");

if (path != NULL)
    printf("%s\n", path);
```

If the variable does not exist, `getenv()` returns `NULL`.

---

### `system()`

```c
int system(const char *string);
```

`system()` passes a command string to the host environment.

```c
system("echo Hello");
```

Its behavior depends on the host operating system and environment, so it is generally not appropriate for portable embedded code.

---

## 8. Important Macros

### `EXIT_SUCCESS`

Indicates successful program termination.

```c
return EXIT_SUCCESS;
```

---

### `EXIT_FAILURE`

Indicates unsuccessful program termination.

```c
return EXIT_FAILURE;
```

---

### `RAND_MAX`

Specifies the maximum value returned by `rand()`.

```c
printf("%d\n", RAND_MAX);
```
