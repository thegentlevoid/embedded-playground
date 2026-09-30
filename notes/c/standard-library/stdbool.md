# `<stdbool.h>`

The `<stdbool.h>` header provides macros for working with boolean values.

It was introduced in **C99** and provides a convenient way to use the `bool` type and the boolean constants `true` and `false`.

---

## Boolean Type

Before C99, C did not have a dedicated boolean type. Boolean values were commonly represented using integers:

```c
int is_valid = 1;
```

C99 introduced the `bool` type through `<stdbool.h>`:

```c
#include <stdbool.h>

bool is_valid = true;
bool is_empty = false;
```

A `bool` object can represent either `true` or `false`.

```c
bool ready = true;

if (ready) {
    printf("Ready!\n");
}
```
---

## Macros

### `bool`

Expands to the C boolean type:

```c
bool flag = true;
```

In C99–C17, `bool` is provided by `<stdbool.h>` as a macro for `_Bool`.

### `true`

Represents a true boolean value.

```c
bool connected = true;
```

### `false`

Represents a false boolean value.

```c
bool connected = false;
```

### `__bool_true_false_are_defined`

This macro was provided to indicate that the `bool`, `true`, and `false` macros are defined.

It is not generally needed in normal C programs.

## `_Bool`

The actual built-in C boolean type is `_Bool`.

```c
_Bool flag = 1;
```

In C99–C17:

```c
#include <stdbool.h>

bool flag = true;
```

is effectively using `_Bool` through the `bool` macro.

`_Bool` can represent:

```text
0 → false
1 → true
```

When an integer value is assigned to `_Bool`, zero becomes `0` and any nonzero value becomes `1`.

```c
_Bool a = 0;   // false
_Bool b = 42;  // true
_Bool c = -5;  // true
```

The same conversion applies to `bool`.

```c
bool a = 0;    // false
bool b = 42;   // true
```
---

## Example

```c
#include <stdio.h>
#include <stdbool.h>

bool is_even(int value)
{
    return value % 2 == 0;
}

int main(void)
{
    int number = 42;

    bool even = is_even(number);

    printf("Is even: %d\n", even);

    if (even) {
        printf("%d is even\n", number);
    }

    return 0;
}
```

Output:

```text
Is even: 1
42 is even
```
---

## Summary

|Name|Purpose|
|---|---|
|`bool`|Boolean type|
|`true`|True boolean value|
|`false`|False boolean value|
|`_Bool`|Built-in C boolean type|
|`__bool_true_false_are_defined`|Indicates availability of boolean macros|
