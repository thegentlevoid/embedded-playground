# `<limits.h>`

## Overview

The `<limits.h>` header defines macros describing the minimum and maximum values supported by the standard integer types.

These limits are **implementation-defined**, so their values can differ between systems and compilers.

---

## Character Limits

| Macro       | Meaning                          |
| ----------- | -------------------------------- |
| `CHAR_BIT`  | Number of bits in a `char`       |
| `CHAR_MIN`  | Minimum value of `char`          |
| `CHAR_MAX`  | Maximum value of `char`          |
| `SCHAR_MIN` | Minimum value of `signed char`   |
| `SCHAR_MAX` | Maximum value of `signed char`   |
| `UCHAR_MAX` | Maximum value of `unsigned char` |

`CHAR_BIT` is particularly important in embedded systems because a byte is defined by the C standard as the size of a `char`, not necessarily 8 bits.

Typical desktop and ARM systems have:

```c
CHAR_BIT == 8
```

---

## `short` Limits

| Macro       | Meaning                           |
| ----------- | --------------------------------- |
| `SHRT_MIN`  | Minimum value of `short`          |
| `SHRT_MAX`  | Maximum value of `short`          |
| `USHRT_MAX` | Maximum value of `unsigned short` |

The C standard guarantees that `short` is at least 16 bits wide.

Example:

```c
#include <limits.h>
#include <stdio.h>

int main(void)
{
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %u\n", USHRT_MAX);

    return 0;
}
```

---

## `int` Limits

| Macro      | Meaning                         |
| ---------- | ------------------------------- |
| `INT_MIN`  | Minimum value of `int`          |
| `INT_MAX`  | Maximum value of `int`          |
| `UINT_MAX` | Maximum value of `unsigned int` |

The C standard guarantees that `int` is at least 16 bits wide.

On a typical 32-bit or 64-bit system:

```text
INT_MIN = -2147483648
INT_MAX =  2147483647
UINT_MAX = 4294967295
```

However, you should not assume these values on every implementation.

---

## `long` Limits

| Macro       | Meaning                          |
| ----------- | -------------------------------- |
| `LONG_MIN`  | Minimum value of `long`          |
| `LONG_MAX`  | Maximum value of `long`          |
| `ULONG_MAX` | Maximum value of `unsigned long` |

The C standard guarantees that `long` is at least 32 bits wide.

Example:

```c
#include <limits.h>

if (value > LONG_MAX)
{
    /* value is outside the range of long */
}
```

---

## `long long` Limits

C99 added `long long` support.

| Macro        | Meaning                               |
| ------------ | ------------------------------------- |
| `LLONG_MIN`  | Minimum value of `long long`          |
| `LLONG_MAX`  | Maximum value of `long long`          |
| `ULLONG_MAX` | Maximum value of `unsigned long long` |

The standard guarantees that `long long` is at least 64 bits wide.

```c
#include <limits.h>
#include <stdio.h>

int main(void)
{
    printf("long long: %lld to %lld\n",
           LLONG_MIN, LLONG_MAX);

    printf("unsigned long long: 0 to %llu\n",
           ULLONG_MAX);

    return 0;
}
```

---

## Minimum Guaranteed Ranges

These are the minimum ranges that a conforming implementation must provide:

| Type                 | Minimum Range                                   |
| -------------------- | ----------------------------------------------- |
| `signed char`        | `-127` to `127`                                 |
| `unsigned char`      | `0` to `255`                                    |
| `short`              | `-32767` to `32767`                             |
| `unsigned short`     | `0` to `65535`                                  |
| `int`                | `-32767` to `32767`                             |
| `unsigned int`       | `0` to `65535`                                  |
| `long`               | `-2147483647` to `2147483647`                   |
| `unsigned long`      | `0` to `4294967295`                             |
| `long long`          | `-9223372036854775807` to `9223372036854775807` |
| `unsigned long long` | `0` to `18446744073709551615`                   |

These are **guaranteed minimum ranges**, not necessarily the actual ranges on your implementation.

For example, the standard only requires `int` to support at least:

```text
-32767 ... 32767
```

but a typical modern implementation provides:

```text
-2147483648 ... 2147483647
```

---

## Why Use `<limits.h>`?

Instead of assuming a particular implementation's limits:

```c
if (value == 2147483647)
{
    /* ... */
}
```

use the appropriate limit macro:

```c
if (value == INT_MAX)
{
    /* ... */
}
```

This makes the code portable across implementations with different integer widths.

This is especially useful in embedded development, where the sizes of fundamental types can vary between architectures and toolchains.

---

## `<limits.h>` vs `<stdint.h>`

The two headers solve different problems.

### `<limits.h>`

Describes the limits of **fundamental C integer types**:

```c
INT_MAX
UINT_MAX
LONG_MAX
CHAR_BIT
```

### `<stdint.h>`

Provides **fixed-width and width-oriented integer types**:

```c
int8_t
uint8_t
int32_t
uint32_t
int_least16_t
uint_fast32_t
```

For example:

```c
#include <limits.h>
#include <stdint.h>

int main(void)
{
    int a = INT_MAX;
    uint32_t b = UINT32_MAX;

    return 0;
}
```

Use `<limits.h>` when you care about the limits of a C fundamental type, and `<stdint.h>` when you need a specific integer width or minimum width.
