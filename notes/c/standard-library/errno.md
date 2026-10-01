# `<errno.h>`

## Overview

The `<errno.h>` header provides a mechanism for reporting errors from certain C standard library functions.

It provides:

- `errno`
- standard error macros such as `EDOM`, `ERANGE`, and `EILSEQ`

---

## `errno`

`errno` is a modifiable integer object used to indicate an error condition.

```c
errno
```

A library function may set `errno` when an error occurs.

Example:

```c
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *end;
    long value;

    errno = 0;

    value = strtol("999999999999999999999999", &end, 10);

    if (errno == ERANGE)
    {
        printf("Value is outside the representable range\n");
    }

    return 0;
}
```

### Important

A successful library function call is **not generally required to reset `errno` to zero**.

Therefore, don't do this:

```c
errno = 0;

some_function();

if (errno != 0)
{
    /* assume some_function failed */
}
```

unless the documentation for that specific function says that `errno` is meaningful on failure.

Instead, first check the function's documented failure indication, then inspect `errno` if appropriate.

---

# Standard Error Macros

The standard defines several macros that can be used as error codes.

|Macro|Meaning|
|---|---|
|`EDOM`|Domain error|
|`ERANGE`|Range error|
|`EILSEQ`|Illegal byte sequence|

The exact numeric values are implementation-defined.

---

## `EDOM`

```c
EDOM
```

Indicates a **domain error**.

A domain error occurs when an argument to a mathematical function is outside the function's valid domain.

For example:

```c
#include <errno.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    double result;

    errno = 0;

    result = sqrt(-1.0);

    if (errno == EDOM)
    {
        printf("Domain error\n");
    }

    return 0;
}
```

The behavior of floating-point functions can also depend on the implementation's floating-point environment.

---

## `ERANGE`

```c
ERANGE
```

Indicates a **range error**.

A range error occurs when the result of a function is outside the range of representable values.

For example, a conversion using `strtol()` may set `errno` to `ERANGE` if the converted value cannot be represented by `long`.

```c
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char *end;
    long value;

    errno = 0;

    value = strtol("999999999999999999999999", &end, 10);

    if (errno == ERANGE)
    {
        printf("Range error\n");
    }

    return 0;
}
```

`ERANGE` is also used by certain mathematical functions when their result is outside the representable range.

---

## `EILSEQ`

```c
EILSEQ
```

Indicates an **illegal byte sequence**.

It is primarily associated with multibyte character and wide-character conversions.

For example, a multibyte character sequence that cannot be interpreted according to the current locale may result in `EILSEQ`.

This is more relevant when using:

```c
#include <wchar.h>
#include <locale.h>
```

than in typical ASCII-oriented embedded code.

---

# Checking `errno` Correctly

A common pattern is:

```c
#include <errno.h>

errno = 0;

/* Call a function that documents errno as meaningful. */

if (/* function-specific failure condition */)
{
    if (errno == ERANGE)
    {
        /* Handle range error */
    }
}
```

The important point is that **`errno` is secondary to the function's documented return value**.

For example, `strtol()` returns a value and uses `errno` to indicate range errors.

---

# `errno` Is a Macro

Although `errno` looks like a variable:

```c
errno = 0;
```

the C standard specifies it as a macro that expands to an identifier designating a modifiable object.

This allows implementations to provide the appropriate mechanism for accessing the error state.

You should therefore simply use:

```c
errno
```

rather than making assumptions about how it is implemented.

---

# Error State

`errno` retains its value until it is changed.

For example:

```c
errno = ERANGE;

/* Later operations do not automatically reset errno. */
```

Therefore, if you need to determine whether a particular operation set `errno`, set it to zero before that operation:

```c
errno = 0;
```

Then inspect it afterward **if the function's documentation makes `errno` relevant**.

---

# Example with `strtol()`

`strtol()` is a useful example because it combines:

- a return value
    
- an end pointer
    
- `errno`
    

```c
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *end;
    long value;

    errno = 0;

    value = strtol("12345", &end, 10);

    if (end == NULL || *end != '\0')
    {
        printf("Invalid input\n");
    }
    else if (errno == ERANGE)
    {
        printf("Value is out of range\n");
    }
    else
    {
        printf("Value: %ld\n", value);
    }

    return 0;
}
```

For robust code, the order and exact checks should follow the function's documented failure behavior.

---

# `errno` and Embedded Systems

On bare-metal embedded systems, `errno` may be less useful than on a desktop or POSIX system.

For example:

```text
Bare-metal
    ↓
minimal C library
    ↓
limited filesystem / I/O
    ↓
fewer functions that meaningfully use errno
```

However, `errno` can still appear when using:

- floating-point functions
- numeric conversion functions
- file/system libraries
- third-party libraries
- RTOS or embedded libc implementations

Whether `errno` is available and how it is implemented depends on the C library and target environment.

---

### Typical Pattern

```c
#include <errno.h>

errno = 0;

/* Call function */

if (/* documented failure */)
{
    if (errno == ERANGE)
    {
        /* Handle range error */
    }
}
```

Remember: **don't treat a nonzero `errno` by itself as proof that the immediately preceding function failed.** Check the function's documented return value or failure condition first.