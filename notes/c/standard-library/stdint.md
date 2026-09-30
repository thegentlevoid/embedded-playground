# `<stdint.h>`

`<stdint.h>` provides integer types with specified width and range requirements.

It was introduced in **C99**.

---

## Integer Types and Boundaries

The header provides several families of integer types. The exact-width types are optional; the minimum-width and fast-width types are available for the widths supported by the implementation.

| Type             |    Minimum Width |                Minimum Value |                Maximum Value |
| ---------------- | ---------------- | ---------------------------- | ---------------------------- |
| `int8_t`         |   exactly 8 bits |                       `-128` |                        `127` |
| `uint8_t`        |   exactly 8 bits |                          `0` |                        `255` |
| `int16_t`        |  exactly 16 bits |                    `-32,768` |                     `32,767` |
| `uint16_t`       |  exactly 16 bits |                          `0` |                     `65,535` |
| `int32_t`        |  exactly 32 bits |             `-2,147,483,648` |              `2,147,483,647` |
| `uint32_t`       |  exactly 32 bits |                          `0` |              `4,294,967,295` |
| `int64_t`        |  exactly 64 bits | `-9,223,372,036,854,775,808` |  `9,223,372,036,854,775,807` |
| `uint64_t`       |  exactly 64 bits |                          `0` | `18,446,744,073,709,551,615` |
| `int_least8_t`   |         ≥ 8 bits |              `-(2⁷)` or less |          `2⁷ - 1` or greater |
| `uint_least8_t`  |         ≥ 8 bits |                          `0` |          `2⁸ - 1` or greater |
| `int_least16_t`  |        ≥ 16 bits |             `-(2¹⁵)` or less |         `2¹⁵ - 1` or greater |
| `uint_least16_t` |        ≥ 16 bits |                          `0` |         `2¹⁶ - 1` or greater |
| `int_least32_t`  |        ≥ 32 bits |             `-(2³¹)` or less |         `2³¹ - 1` or greater |
| `uint_least32_t` |        ≥ 32 bits |                          `0` |         `2³² - 1` or greater |
| `int_least64_t`  |        ≥ 64 bits |             `-(2⁶³)` or less |         `2⁶³ - 1` or greater |
| `uint_least64_t` |        ≥ 64 bits |                          `0` |         `2⁶⁴ - 1` or greater |
| `int_fast8_t`    |         ≥ 8 bits |              `-(2⁷)` or less |          `2⁷ - 1` or greater |
| `uint_fast8_t`   |         ≥ 8 bits |                          `0` |          `2⁸ - 1` or greater |
| `int_fast16_t`   |        ≥ 16 bits |             `-(2¹⁵)` or less |         `2¹⁵ - 1` or greater |
| `uint_fast16_t`  |        ≥ 16 bits |                          `0` |         `2¹⁶ - 1` or greater |
| `int_fast32_t`   |        ≥ 32 bits |             `-(2³¹)` or less |         `2³¹ - 1` or greater |
| `uint_fast32_t`  |        ≥ 32 bits |                          `0` |         `2³² - 1` or greater |
| `int_fast64_t`   |        ≥ 64 bits |             `-(2⁶³)` or less |         `2⁶³ - 1` or greater |
| `uint_fast64_t`  |        ≥ 64 bits |                          `0` |         `2⁶⁴ - 1` or greater |
| `intmax_t`       | widest supported |       implementation-defined |       implementation-defined |
| `uintmax_t`      | widest supported |                          `0` |       implementation-defined |
| `intptr_t`       |  pointer-capable |       implementation-defined |       implementation-defined |
| `uintptr_t`      |  pointer-capable |                          `0` |       implementation-defined |

---

### Important

The exact-width types:

```c
int8_t
int16_t
int32_t
int64_t

uint8_t
uint16_t
uint32_t
uint64_t
```

are **optional**. They are provided only when the implementation has an integer type with exactly that width.

For example, `int64_t` does not have to exist on an implementation without a suitable exactly-64-bit integer type.

The `int_leastN_t` and `int_fastN_t` families provide **at least** the requested number of bits, so their actual width can be larger.

For example:

```c
int_least32_t
```

could be 64 bits on an implementation where that is the smallest suitable integer type.

---

## Exact-Width Integer Types

These types provide an integer type with **exactly** the specified number of bits, if the implementation supports such a type.

```c
int8_t
int16_t
int32_t
int64_t
```

Unsigned equivalents:

```c
uint8_t
uint16_t
uint32_t
uint64_t
```

Example:

```c
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint8_t flags = 0x80;
    int16_t temperature = -250;

    printf("flags: %u\n", flags);
    printf("temperature: %d\n", temperature);

    return 0;
}
```

---

## Minimum-Width Integer Types

`int_leastN_t` provides a signed integer type with **at least N bits**.

```c
int_least8_t
int_least16_t
int_least32_t
int_least64_t
```

Unsigned versions:

```c
uint_least8_t
uint_least16_t
uint_least32_t
uint_least64_t
```

---

## Fast Integer Types

`int_fastN_t` provides a signed integer type with **at least N bits** that is intended to be the fastest type available for that width.

```c
int_fast8_t
int_fast16_t
int_fast32_t
int_fast64_t
```

Unsigned versions:

```c
uint_fast8_t
uint_fast16_t
uint_fast32_t
uint_fast64_t
```

The "fast" type does not necessarily have exactly the requested width.

For example:

```c
int_fast8_t
```

could be a 32-bit integer if the implementation considers that faster than using an 8-bit type.

---

## Greatest-Width Integer Types

C99 also provides:

```c
intmax_t
uintmax_t
```

`intmax_t` is a signed integer type capable of representing any value of any **signed integer type** supported by the implementation.

`uintmax_t` is the corresponding unsigned type.

---

## Integer Limits

`<stdint.h>` provides macros describing the limits of the integer types.

For example:

```c
INT8_MIN
INT8_MAX
UINT8_MAX

INT16_MIN
INT16_MAX
UINT16_MAX

INT32_MIN
INT32_MAX
UINT32_MAX

INT64_MIN
INT64_MAX
UINT64_MAX
```

Example:

```c
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    printf("int8_t:  %d to %d\n", INT8_MIN, INT8_MAX);
    printf("int16_t: %d to %d\n", INT16_MIN, INT16_MAX);
    printf("int32_t: %d to %d\n", INT32_MIN, INT32_MAX);

    return 0;
}
```

The exact-width limit macros are only defined when the corresponding exact-width type exists.

---

## Minimum and Fast Limits

The minimum-width types also have corresponding limit macros.

For example:

```c
INT_LEAST8_MIN
INT_LEAST8_MAX
UINT_LEAST8_MAX

INT_FAST8_MIN
INT_FAST8_MAX
UINT_FAST8_MAX
```

The pattern continues for 16, 32, and 64 bits.

---

## `INTMAX` Limits

The limits of the widest integer types are available as:

```c
INTMAX_MIN
INTMAX_MAX
UINTMAX_MAX
```

---

## Constant Macros

`<stdint.h>` also provides macros for creating integer constants with the appropriate type.

```c
INT8_C(100)
INT16_C(100)
INT32_C(100)
INT64_C(100)

UINT8_C(100)
UINT16_C(100)
UINT32_C(100)
UINT64_C(100)
```

There are also macros for maximum-width integer types:

```c
INTMAX_C(100000)
UINTMAX_C(100000)
```

Example:

```c
#include <stdint.h>

int32_t value = INT32_C(100000);
uint32_t mask = UINT32_C(0xFFFFFFFF);
```

---

## `intptr_t` and `uintptr_t`

C99 provides:

```c
intptr_t
uintptr_t
```

when the implementation supports integer types capable of holding converted object pointers.

`uintptr_t` is an unsigned integer type capable of holding a converted `void *`.

`intptr_t` is the corresponding signed type.

These types are optional.

---

## Why Use `<stdint.h>`?

Traditional C types such as:

```c
char
short
int
long
```

do not guarantee the same width on every implementation.

For example:

```c
int value = 100;
```

does not guarantee that `value` is exactly 32 bits.

With `<stdint.h>`:

```c
int32_t value = 100;
```

the intent is explicit: `value` must be an integer type exactly 32 bits wide.

This is particularly useful for:

- embedded systems
- hardware registers
- binary protocols
- file formats
- network packets
- bit manipulation
- memory-mapped data structures

Example:

```c
#include <stdint.h>

struct Packet
{
    uint8_t type;
    uint16_t length;
    uint32_t id;
};
```

---

## Which Type Should You Use?

### `intN_t`

Use when you need an **exact width**:

```c
uint32_t device_id;
int16_t temperature;
uint8_t register_value;
```

### `int_leastN_t`

Use when you need **at least N bits** and want the smallest suitable type:

```c
int_least32_t value;
```

### `int_fastN_t`

Use when you need **at least N bits** and want a type intended to provide fast operations:

```c
int_fast32_t counter;
```

### `intmax_t`

Use when you need the **widest signed integer type**:

```c
intmax_t value;
```

### `uintmax_t`

Use when you need the **widest unsigned integer type**:

```c
uintmax_t value;
```

### `intptr_t` / `uintptr_t`

Use when a pointer needs to be represented as an integer:

```c
uintptr_t address;
```

---

## `<stdint.h>` vs `<inttypes.h>`

`<stdint.h>` primarily provides:

- integer types
- integer limits
- integer constant macros

`<inttypes.h>` provides additional facilities for working with these types, particularly **portable formatted input/output macros**.

---

## Summary

```text
<stdint.h>
│
├── Exact-width
│   ├── int8_t / uint8_t
│   ├── int16_t / uint16_t
│   ├── int32_t / uint32_t
│   └── int64_t / uint64_t
│
├── Minimum-width
│   ├── int_leastN_t
│   └── uint_leastN_t
│
├── Fast-width
│   ├── int_fastN_t
│   └── uint_fastN_t
│
├── Maximum-width
│   ├── intmax_t
│   └── uintmax_t
│
├── Pointer-sized integers
│   ├── intptr_t
│   └── uintptr_t
│
├── Limits
│   ├── INTN_MIN / INTN_MAX
│   └── UINTN_MAX
│
└── Integer constants
    ├── INTN_C()
    └── UINTN_C()
```

`<stdint.h>` was introduced in **C99** and is especially important when integer widths matter, such as in embedded programming and binary data handling.