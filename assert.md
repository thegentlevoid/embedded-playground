# `<assert.h>`

## Overview

The `<assert.h>` header provides the `assert()` macro for detecting programming errors during development.

---

## `assert()`

```c
assert(expression);
```

Evaluates `expression` and checks whether it is true.

|Condition|Behavior|
|---|---|
|`expression != 0`|Nothing happens|
|`expression == 0`|Diagnostic is printed and `abort()` is called|

Example:

```c
#include <assert.h>
#include <stdio.h>

int main(void)
{
    int value = 10;

    assert(value > 0);

    printf("Value: %d\n", value);

    return 0;
}
```

If `value > 0` is true, execution continues normally.

If it is false, the program is terminated.

A typical diagnostic may look like:

```text
Assertion failed: value > 0, file main.c, line 9
```

The exact format of the diagnostic is implementation-defined.

---

## Using `assert()` for Preconditions

Assertions are useful for checking assumptions that should always be true if the program is correct.

```c
#include <assert.h>

int divide(int a, int b)
{
    assert(b != 0);

    return a / b;
}
```

Here, `b != 0` is a precondition of the function.

Assertions are generally intended for **programming errors and internal assumptions**, not normal runtime input validation.

For example, this is usually inappropriate:

```c
assert(user_input >= 0);
```

if negative input is something the program is expected to handle.

Instead, handle it explicitly:

```c
if (user_input < 0)
{
    /* Handle invalid input */
}
```

---

# `NDEBUG`

The `NDEBUG` macro controls whether assertions are enabled.

If `NDEBUG` is defined **before including `<assert.h>`**:

```c
#define NDEBUG
#include <assert.h>
```

then:

```c
assert(expression);
```

is disabled.

The expression is not evaluated.

For example:

```c
#define NDEBUG
#include <assert.h>
#include <stdio.h>

int main(void)
{
    int value = 0;

    assert(value != 0);

    printf("Program continues\n");

    return 0;
}
```

The assertion does nothing because `NDEBUG` is defined.

---

## Debug and Release Builds

A common pattern is to enable assertions during development and disable them in production builds.

### Debug build

```c
#include <assert.h>

assert(pointer != NULL);
assert(index < size);
```

### Release build

Compile with `NDEBUG` defined:

```text
-DNDEBUG
```

For example with GCC:

```bash
gcc -DNDEBUG main.c -o main
```

This disables assertions without requiring changes to the source code.

---

# Important: Don't Put Required Side Effects in `assert()`

Avoid:

```c
assert(i++);
```

or:

```c
assert(read_sensor());
```

When `NDEBUG` is enabled, the expression is not evaluated.

That means the behavior changes between debug and release builds.

Instead:

```c
i++;

assert(i > 0);
```

Or, if the operation itself must always happen:

```c
if (!read_sensor())
{
    /* Handle error */
}

assert(sensor_is_valid);
```

---

# `assert()` and `abort()`

When an assertion fails, the implementation calls `abort()`.

Conceptually:

```text
assert(expression)
       │
       ├── expression != 0 → continue
       │
       └── expression == 0
                │
                ├── diagnostic
                │
                └── abort()
```

`abort()` is provided by `<stdlib.h>`.

See [[stdlib]] for `abort()` and other program termination functions.

---

# Embedded Considerations

Assertions can be particularly useful during embedded development for detecting invalid internal states:

```c
#include <assert.h>

void set_buffer(uint8_t *buffer, size_t size)
{
    assert(buffer != NULL);
    assert(size > 0);

    /* ... */
}
```

However, blindly relying on the standard `abort()` behavior may not be appropriate for a bare-metal system.

An embedded implementation may provide its own assertion handler, for example:

```c
#define assert(expr) \
    ((expr) ? (void)0 : assertion_failed(#expr, __FILE__, __LINE__))
```

The exact mechanism is platform- and project-specific.

---
### Typical Pattern

```c
#include <assert.h>

void process(int *buffer, size_t size)
{
    assert(buffer != NULL);
    assert(size > 0);

    /* ... */
}
```

Use `assert()` for **conditions that indicate a programming error or violated internal assumption**, not for ordinary runtime error handling.