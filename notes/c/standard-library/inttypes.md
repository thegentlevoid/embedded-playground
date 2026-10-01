# `<inttypes.h>`

## Overview

The `<inttypes.h>` header provides macros and functions for working with the integer types defined by [[stdint]].

Its most common use is **portable formatted input and output** for types such as `int32_t` and `uint64_t`.

---

## Format Macros

The `PRI*` macros are used with `printf()`-family functions.

The `SCN*` macros are used with `scanf()`-family functions.

### Signed Integer Output

|Macro|Type|
|---|---|
|`PRId8`|`int8_t`|
|`PRId16`|`int16_t`|
|`PRId32`|`int32_t`|
|`PRId64`|`int64_t`|
|`PRIi8`|`int8_t`|
|`PRIi16`|`int16_t`|
|`PRIi32`|`int32_t`|
|`PRIi64`|`int64_t`|

`d` specifies decimal output, while `i` specifies signed integer output using the same rules as `%i`.

Example:

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int32_t value = -123456;

    printf("%" PRId32 "\n", value);

    return 0;
}
```

The format string is effectively constructed by the preprocessor. For example, an implementation might turn:

```c
"%" PRId32
```

into:

```c
"%d"
```

or another appropriate format depending on the underlying type.

---

### Unsigned Integer Output

|Macro|Type|
|---|---|
|`PRIu8`|`uint8_t`|
|`PRIu16`|`uint16_t`|
|`PRIu32`|`uint32_t`|
|`PRIu64`|`uint64_t`|
|`PRIo8`|`uint8_t`|
|`PRIo16`|`uint16_t`|
|`PRIo32`|`uint32_t`|
|`PRIo64`|`uint64_t`|
|`PRIx8`|`uint8_t`|
|`PRIx16`|`uint16_t`|
|`PRIx32`|`uint32_t`|
|`PRIx64`|`uint64_t`|
|`PRIX8`|`uint8_t`|
|`PRIX16`|`uint16_t`|
|`PRIX32`|`uint32_t`|
|`PRIX64`|`uint64_t`|

The different letters select the output base:

- `u` — decimal
- `o` — octal
- `x` — lowercase hexadecimal
- `X` — uppercase hexadecimal

Example:

```c
uint32_t value = 0xDEADBEEF;

printf("%" PRIu32 "\n", value);
printf("%" PRIx32 "\n", value);
printf("%" PRIX32 "\n", value);
```

Possible output:

```text
3735928559
deadbeef
DEADBEEF
```

---

## Pointer-Sized Integer Output

`inttypes.h` also provides macros for `intptr_t` and `uintptr_t`.

|Macro|Type|
|---|---|
|`PRIdPTR`|`intptr_t`|
|`PRIiPTR`|`intptr_t`|
|`PRIuPTR`|`uintptr_t`|
|`PRIoPTR`|`uintptr_t`|
|`PRIxPTR`|`uintptr_t`|
|`PRIXPTR`|`uintptr_t`|

Example:

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int value = 42;

uintptr_t address = (uintptr_t)&value;

printf("Address: 0x%" PRIxPTR "\n", address);
```

---

## `intmax_t` and `uintmax_t`

`intmax_t` and `uintmax_t` represent the widest signed and unsigned integer types supported by the implementation.

Corresponding format macros are:

|Macro|Type|
|---|---|
|`PRIdMAX`|`intmax_t`|
|`PRIiMAX`|`intmax_t`|
|`PRIuMAX`|`uintmax_t`|
|`PRIoMAX`|`uintmax_t`|
|`PRIxMAX`|`uintmax_t`|
|`PRIXMAX`|`uintmax_t`|

Example:

```c
intmax_t value = 123456789;

printf("%" PRIdMAX "\n", value);
```

---

# `scanf()` Format Macros

The `SCN*` macros provide the equivalent functionality for `scanf()`-family functions.

### Signed

|Macro|Type|
|---|---|
|`SCNd8`|`int8_t *`|
|`SCNd16`|`int16_t *`|
|`SCNd32`|`int32_t *`|
|`SCNd64`|`int64_t *`|
|`SCNi8`|`int8_t *`|
|`SCNi16`|`int16_t *`|
|`SCNi32`|`int32_t *`|
|`SCNi64`|`int64_t *`|

### Unsigned

|Macro|Type|
|---|---|
|`SCNu8`|`uint8_t *`|
|`SCNu16`|`uint16_t *`|
|`SCNu32`|`uint32_t *`|
|`SCNu64`|`uint64_t *`|
|`SCNo8`|`uint8_t *`|
|`SCNo16`|`uint16_t *`|
|`SCNo32`|`uint32_t *`|
|`SCNo64`|`uint64_t *`|
|`SCNx8`|`uint8_t *`|
|`SCNx16`|`uint16_t *`|
|`SCNx32`|`uint32_t *`|
|`SCNx64`|`uint64_t *`|

Example:

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t value;

    scanf("%" SCNu32, &value);

    printf("Value: %" PRIu32 "\n", value);

    return 0;
}
```

The `SCN` macros are particularly useful because the underlying type of `uint32_t`, for example, is implementation-defined.

---

# `intmax_t` and `uintmax_t` Input

There are also scanning macros for the maximum-width integer types:

|Macro|Type|
|---|---|
|`SCNdMAX`|`intmax_t *`|
|`SCNiMAX`|`intmax_t *`|
|`SCNuMAX`|`uintmax_t *`|
|`SCNoMAX`|`uintmax_t *`|
|`SCNxMAX`|`uintmax_t *`|

Example:

```c
intmax_t value;

scanf("%" SCNdMAX, &value);
```

---

# Integer Conversion Functions

`<inttypes.h>` also provides functions for converting strings to `intmax_t` and `uintmax_t`.

## `strtoimax()`

```c
intmax_t strtoimax(
    const char * restrict nptr,
    char ** restrict endptr,
    int base
);
```

Converts a string to `intmax_t`.

```c
#include <inttypes.h>

char *end;
intmax_t value;

value = strtoimax("12345", &end, 10);
```

The `base` argument determines the number system:

```text
2   binary
8   octal
10  decimal
16  hexadecimal
```

Using `0` allows the prefix to determine the base:

```c
strtoimax("123", &end, 0);
strtoimax("0123", &end, 0);
strtoimax("0x123", &end, 0);
```

---

## `strtoumax()`

```c
uintmax_t strtoumax(
    const char * restrict nptr,
    char ** restrict endptr,
    int base
);
```

Converts a string to `uintmax_t`.

Example:

```c
uintmax_t value;

value = strtoumax("FF", &end, 16);
```

---

# `imaxdiv()`

C99 also provides `imaxdiv()` for dividing two `intmax_t` values.

```c
imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);
```

The result contains both the quotient and remainder.

```c
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    imaxdiv_t result;

    result = imaxdiv(17, 5);

    printf("quotient: %" PRIdMAX "\n", result.quot);
    printf("remainder: %" PRIdMAX "\n", result.rem);

    return 0;
}
```

The corresponding type is:

```c
typedef struct {
    intmax_t quot;
    intmax_t rem;
} imaxdiv_t;
```

---

# Why Use `<inttypes.h>`?

Consider:

```c
uint32_t value = 123;
printf("%u\n", value);
```

This may work on a particular implementation, but `uint32_t` is allowed to be based on different underlying integer types.

`PRIu32` allows the implementation to provide the correct format:

```c
printf("%" PRIu32 "\n", value);
```

This is especially useful for portable code targeting different architectures and compilers.

---

# `<stdint.h>` vs `<inttypes.h>`

These headers are closely related but serve different purposes.

### `<stdint.h>`

Provides integer types:

```c
uint8_t
int16_t
uint32_t
uint64_t
intmax_t
uintptr_t
```

### `<inttypes.h>`

Provides:

- `printf()` format macros
- `scanf()` format macros
- integer conversion functions
- `imaxdiv_t`
- `imaxdiv()`

For example:

```c
#include <stdint.h>
#include <inttypes.h>

uint32_t value = 100;

printf("%" PRIu32 "\n", value);
```