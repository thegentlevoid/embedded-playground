# `<stddef.h>`

## Overview

The `<stddef.h>` header defines several fundamental types and macros used throughout the C standard library.

It provides:
- `size_t`
- `ptrdiff_t`
- `wchar_t`
- `NULL`
- `offsetof()`

---

## `size_t`

`size_t` is an unsigned integer type capable of representing the size of any object in bytes.

It is commonly returned by `sizeof()` and functions such as `strlen()`.

```c
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main(void)
{
    int numbers[10];
    const char *text = "Hello";

    size_t array_size = sizeof(numbers);
    size_t length = strlen(text);

    printf("Array size: %zu\n", array_size);
    printf("String length: %zu\n", length);

    return 0;
}
```

Use `size_t` when storing object sizes, byte counts, or values returned by APIs that represent sizes.

---

## `ptrdiff_t`

`ptrdiff_t` is a signed integer type capable of representing the difference between two pointers into the same array.

```c
#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40};

    int *p1 = &numbers[1];
    int *p2 = &numbers[3];

    ptrdiff_t difference = p2 - p1;

    printf("%td\n", difference);

    return 0;
}
```

Output:

```text
2
```

Unlike `size_t`, `ptrdiff_t` is signed because a pointer difference can be negative.

---

## `wchar_t`

`wchar_t` is an integer type capable of representing the distinct codes of all members of the largest extended character set supported by the implementation.

```c
#include <stddef.h>
#include <wchar.h>

wchar_t character = L'A';
```

Wide-character functionality is primarily provided by `<wchar.h>` and `<wctype.h>`.

---

## `NULL`

`NULL` is a null pointer constant used to indicate that a pointer does not point to an object.

```c
#include <stddef.h>

int *ptr = NULL;
```

It can be used when checking pointers:

```c
if (ptr == NULL)
{
    /* pointer is null */
}
```

The exact definition of `NULL` is implementation-defined. It is commonly defined as `0` or `((void *)0)`.

---

## `offsetof()`

```c
size_t offsetof(type, member);
```

Returns the offset, in bytes, of a structure member from the beginning of the structure.

```c
#include <stdio.h>
#include <stddef.h>

struct Packet
{
    char type;
    int length;
    char data[16];
};

int main(void)
{
    printf("type:   %zu\n", offsetof(struct Packet, type));
    printf("length: %zu\n", offsetof(struct Packet, length));
    printf("data:   %zu\n", offsetof(struct Packet, data));

    return 0;
}
```

The result accounts for any padding inserted by the compiler between structure members.

`offsetof()` is particularly useful when working with binary data structures, memory layouts, and embedded systems.