# Types in C Programming Language

## Integer Types

|Type|Typical Size|Signed Range|Unsigned Range|
|---|--:|--:|--:|
|`char`|1 byte|−128 to 127*|0 to 255*|
|`short`|2 bytes|−32,768 to 32,767|0 to 65,535|
|`int`|4 bytes|−2³¹ to 2³¹−1|0 to 2³²−1|
|`long`|4/8 bytes|Implementation-dependent|Implementation-dependent|
|`long long`|8 bytes|−2⁶³ to 2⁶³−1|0 to 2⁶⁴−1|

* Plain `char` may be signed or unsigned.

### Signed vs Unsigned

```text
Signed:   −2^(N−1) → 2^(N−1)−1
Unsigned: 0 → 2^N−1
```

`N` = number of value bits.

---

## Floating-Point Types

|Type|Typical Size|Precision|
|---|--:|--:|
|`float`|4 bytes|~6–7 digits|
|`double`|8 bytes|~15–16 digits|
|`long double`|8/16 bytes|Implementation-dependent|

Use `<float.h>` for implementation-specific limits:

```c
FLT_MIN   FLT_MAX
DBL_MIN   DBL_MAX
LDBL_MIN  LDBL_MAX
```

---

## Other Fundamental Types

|Type|Description|
|---|---|
|`char`|Character / integer type|
|`_Bool`|Boolean type: `0` or `1`|
|`void`|No value / no type|

Most code uses:

```c
#include <stdbool.h>

bool enabled = true;
```

---

## Derived Types

|Type|Description|
|---|---|
|Pointer|Stores an address|
|Array|Collection of elements of the same type|
|Function|Defines return type and parameter types|

```c
int *ptr;
int numbers[10];
int add(int a, int b);
```

---

## User-Defined Types

|Type|Description|
|---|---|
|`struct`|Groups multiple members|
|`union`|Members share the same memory|
|`enum`|Named integer constants|
|`typedef`|Creates a type alias|

```c
struct Sensor { int value; float voltage; };

union Data { int i; float f; };

enum State { IDLE, RUNNING, ERROR };

typedef unsigned int uint;
```

> `enum` size is implementation-defined; don't assume it is 1 byte.

---

## Fixed-Width Integers

For embedded systems:

```c
#include <stdint.h>

int8_t    int16_t    int32_t    int64_t
uint8_t   uint16_t   uint32_t   uint64_t
```

|Type|Range|
|---|--:|
|`int8_t`|−128 → 127|
|`uint8_t`|0 → 255|
|`int16_t`|−32,768 → 32,767|
|`uint16_t`|0 → 65,535|
|`int32_t`|−2³¹ → 2³¹−1|
|`uint32_t`|0 → 2³²−1|
|`int64_t`|−2⁶³ → 2⁶³−1|
|`uint64_t`|0 → 2⁶⁴−1|

---

## Type Qualifiers

|Qualifier|Purpose|
|---|---|
|`const`|Prevents modification through that declaration|
|`volatile`|Value may change outside normal program flow|
|`restrict`|Pointer access optimization guarantee|
|`_Atomic`|Atomic access to an object|

For embedded programming, `volatile` is particularly important for **hardware registers and interrupt-related variables**.

---

## Useful Headers

```c
#include <limits.h>   // Integer limits
#include <float.h>    // Floating-point limits
#include <stdint.h>   // Fixed-width integers
#include <stdbool.h>  // bool, true, false
#include <stddef.h>   // size_t
```

### Important

C does **not** guarantee that:

```text
int       = 4 bytes
long      = 8 bytes
char      = 1 byte
enum      = 1 byte
```

Use `sizeof`, `<limits.h>`, and `<stdint.h>` when the actual size matters.