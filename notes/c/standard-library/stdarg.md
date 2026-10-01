# `<stdarg.h>`

## Overview

The `<stdarg.h>` header provides macros for defining and processing **variadic functions** — functions that accept a variable number of arguments.

The main functions are:

| Function           | Prototype                                  | Purpose                         |
| ------------------ | ------------------------------------------ | ------------------------------- |
| [`va_start()`](#va_start)  | `void va_start(va_list ap, parmN);`        | Initializes a `va_list`         |
| [`va_arg()`](#va_arg)    | `type va_arg(va_list ap, type);`           | Retrieves the next argument     |
| [`va_end()`](#va_end)    | `void va_end(va_list ap);`                 | Finishes processing a `va_list` |
| [`va_copy()`](#va_copy)   | `void va_copy(va_list dest, va_list src);` | Creates a copy of a `va_list`   |

---

## `va_list`

`va_list` is the type used to access the arguments passed through `...`.

```c
va_list args;
```

It is normally used with `va_start()`, `va_arg()`, and `va_end()`.

---

## `va_start()`

```c
void va_start(va_list ap, parmN);
```

Initializes `ap` so that the arguments following `parmN` can be accessed.

`parmN` is the parameter immediately before `...`.

```c
void print_values(int count, ...)
{
    va_list args;

    va_start(args, count);

    /* use va_arg() */

    va_end(args);
}
```

---

## `va_arg()`

```c
type va_arg(va_list ap, type);
```

Retrieves the next argument and advances `ap` to the following argument.

```c
#include <stdio.h>
#include <stdarg.h>

void print_values(int count, ...)
{
    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++)
        printf("%d\n", va_arg(args, int));

    va_end(args);
}
```

The type passed to `va_arg()` must match the actual argument type after **default argument promotions**.

For example:

```text
char  -> int
short -> int
float -> double
```

Therefore, a `float` argument must be retrieved as:

```c
double value = va_arg(args, double);
```

---

## `va_end()`

```c
void va_end(va_list ap);
```

Finishes processing a variable argument list.

Every `va_start()` should have a corresponding `va_end()`.

```c
va_start(args, count);

/* use va_arg() */

va_end(args);
```

After `va_end()`, the `va_list` must not be used again unless it is reinitialized.

---

## `va_copy()` — C99

```c
void va_copy(va_list dest, va_list src);
```

Creates a copy of a `va_list`, allowing the arguments to be traversed independently.

```c
va_list args;
va_list copy;

va_start(args, count);
va_copy(copy, args);

/* use args and copy independently */

va_end(copy);
va_end(args);
```

Use `va_copy()` rather than assigning one `va_list` to another:

```c
va_list copy = args;    /* not portable */
```

---

## Example: Variadic `errorf()`

A variadic function needs some way to determine how to interpret its arguments. A format string is one common approach.

```c
#include <stdio.h>
#include <stdarg.h>

void errorf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    fprintf(stderr, "Error: ");
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");

    va_end(args);
}

int main(void)
{
    errorf("failed to open %s (code %d)", "config.txt", 404);
    return 0;
}
```

The `vfprintf()` call is responsible for processing the `va_list`; see [[stdio]] for the `v*` formatted I/O functions.

---

## Important Notes

C does not provide a way for a variadic function to automatically determine:

* how many arguments were passed
* what types those arguments have

The function must obtain this information through something such as a count:

```c
void print_values(int count, ...);
```

or a format string:

```c
void errorf(const char *format, ...);
```

Arguments passed through `...` undergo the **default argument promotions**, so the type used with `va_arg()` must account for those promotions.