# Header Files

Header files (`.h`) are used to share **declarations and type definitions** between multiple C source files.

They help organize larger programs into separate modules.

---

## What Goes in a Header?

A header generally contains things that other source files need to know about:

- Function declarations
- `struct` definitions
- `union` definitions
- `enum` definitions
- `typedef`s
- Constants and macros

For example:

```c
/* math_utils.h */

int add(int a, int b);
int multiply(int a, int b);
```

The header declares the functions, while the implementations belong in a `.c` file:

```c
/* math_utils.c */

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}
```

The header describes the **interface**, while the source file contains the **implementation**.

---

# Multi-File Projects

Larger programs are normally divided into multiple `.c` files.

For example:

```text
project/
├── main.c
├── math_utils.c
├── math_utils.h
├── motor.c
├── motor.h
├── uart.c
└── uart.h
```

Each source file is compiled separately:

```text
main.c       → main.o
math_utils.c → math_utils.o
motor.c      → motor.o
uart.c       → uart.o
```

The resulting object files are then linked together:

```text
main.o
math_utils.o
motor.o
uart.o
    │
    ▼
program
```

So the build process can be thought of as:

```text
.c files
   ↓
Compilation
   ↓
.o files
   ↓
Linking
   ↓
Executable
```

---

# Example Multi-File Project

### `math_utils.h`

```c
int add(int a, int b);
int multiply(int a, int b);
```

### `math_utils.c`

```c
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}
```

### `main.c`

```c
#include "math_utils.h"

int main(void)
{
    int result = add(10, 20);

    return 0;
}
```

The header allows `main.c` to know the declaration of `add()` without knowing how `add()` is implemented.

---

# Header Guards

A header can be included indirectly through multiple files.

Without protection, the same declarations or definitions could appear multiple times in a translation unit.

For example:

```c
/* person.h */

struct Person
{
    char name[50];
    int age;
};
```

If this header is processed twice, the compiler could see:

```c
struct Person
{
    char name[50];
    int age;
};

struct Person
{
    char name[50];
    int age;
};
```

This results in a redefinition error.

A **header guard** prevents the contents of a header from being processed more than once per translation unit.

---

## Creating a Header Guard

The standard portable pattern is:

```c
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);
int multiply(int a, int b);

#endif
```

The process is:

```c
#ifndef MATH_UTILS_H
```

Check whether `MATH_UTILS_H` has already been defined.

```c
#define MATH_UTILS_H
```

If it hasn't, define it.

The contents of the header follow.

```c
#endif
```

End the conditional section.

If the header is encountered again, `MATH_UTILS_H` is already defined, so its contents are skipped.

---

# Complete Header Example

```c
#ifndef MOTOR_H
#define MOTOR_H

typedef enum
{
    MOTOR_STOPPED,
    MOTOR_RUNNING,
    MOTOR_ERROR
} MotorState;

void motor_init(void);
void motor_start(void);
void motor_stop(void);
MotorState motor_get_state(void);

#endif
```

The header exposes the module's public interface:

```text
motor.h
   │
   ├── Types
   └── Function declarations
```

while `motor.c` contains the implementations.

---

# Translation Units

Each `.c` file, together with the headers processed as part of it, forms a **translation unit**.

For example:

```text
main.c
 ├── header A
 ├── header B
 └── header C
       │
       ▼
 translation unit
       │
       ▼
     main.o
```

Each `.c` file produces its own translation unit and is compiled independently.

Header guards prevent a header from being processed multiple times within the same translation unit.

---

# `#pragma once`

Some compilers support:

```c
#pragma once
```

as an alternative to traditional header guards.

For example:

```c
#pragma once

int add(int a, int b);
```

However, `#pragma once` is **not part of the C89/C90 or C99 standard**.

For portable C, use traditional header guards:

```c
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/* declarations */

#endif
```

---

# Header Design

A useful mental model is:

```text
┌─────────────────┐
│    module.h     │
│                 │
│   Public API    │
│   Types         │
│   Declarations  │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│    module.c     │
│                 │
│ Implementation  │
└─────────────────┘
```

Keep headers focused on what other source files need to **know**, while keeping implementation details in the corresponding `.c` file.

## Key Points

- `.h` files provide interfaces and shared declarations.
- `.c` files contain implementations.
- Large projects can be divided into multiple `.c` files.
- Each `.c` file is compiled separately.
- Object files are combined during linking.
- Header guards prevent duplicate processing within a translation unit.
- Traditional header guards are portable C89/C90/C99.
- `#pragma once` is compiler-specific, not standard C.