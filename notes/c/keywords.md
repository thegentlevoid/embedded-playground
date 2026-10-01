# Common Keywords in Embedded C

C provides several keywords that affect how variables and functions are stored, accessed, optimized, or modified.

## Table of Contents

1. [`auto`](#auto)
2. [`register`](#register)
3. [`static`](#static)
    - Static local variables
    - Static global variables
4. [`extern`](#extern)
5. [`volatile`](#volatile)
6. [`inline`](#inline)
7. [`const`](#const)
    - Pointer to const data
    - Const pointer
    - Const pointer to const data
8. [Combining Qualifiers](#combining-qualifiers)

## `auto`

`auto` specifies **automatic storage duration**.

For local variables, `auto` is the default, so it is rarely written explicitly.

```c
void foo(void)
{
    auto int x = 10;
    int y = 20;       // equivalent
}
```

Automatic variables:

- are created when execution enters their block
- are destroyed when execution leaves their block
- normally live on the stack
- have no guaranteed initial value if not initialized

```c
void foo(void)
{
    int x;       // indeterminate value
    int y = 10;  // initialized
}
```

> `auto` does **not** mean type inference in C.  
> Unlike C++, `auto` cannot be used to automatically determine a variable's type.

---

## `register`

`register` suggests that a variable should be stored in a **CPU register** rather than memory.

```c
void foo(void)
{
    register int counter;
    for (counter = 0; counter < 1000; counter++);
}
```

The compiler is **not required** to honor the request. Modern compilers generally perform their own register allocation and usually ignore the hint.

An important restriction is that you cannot use the address-of operator on a `register` variable:

```c
register int x = 10;

// int *p = &x;   // invalid
```

`register` is therefore mostly a historical keyword and rarely needs to be used in modern C.

---

## `static`

`static` has different effects depending on where it is used.

### Static local variables

A local `static` variable has **static storage duration**.

It is initialized only once and retains its value between function calls.

```c
void counter(void)
{
    static int count = 0;

    count++;
    printf("%d\n", count);
}
```

Calling `counter()` repeatedly produces:

```text
1
2
3
4
```

Without `static`, `count` would be created again each time the function is called.

```c
void counter(void)
{
    int count = 0;

    count++;
    printf("%d\n", count);
}
```

This produces:

```text
1
1
1
1
```

A static local variable exists for the entire execution of the program, but its **scope remains limited to the block**.

---

### Static global variables

At file scope, `static` gives an object or function **internal linkage**.

```c
static int counter = 0;

static void helper(void)
{
}
```

These names can only be accessed from the current source file.

This is useful for keeping implementation details private:

```c
// math.c

static int internal_value;

static void helper(void)
{
}

void public_function(void)
{
    helper();
}
```

Other source files cannot directly access `internal_value` or `helper`.

---

## `extern`

`extern` declares an object or function that is **defined elsewhere**.

For example:

```c
// file1.c
int counter = 0;
```

Another source file can access it using:

```c
// file2.c
extern int counter;

void foo(void)
{
    counter++;
}
```

`extern` usually tells the compiler:

> "This name exists, but its definition is somewhere else."

A declaration such as:

```c
extern int counter;
```

does not normally allocate storage for `counter`.

The actual definition is:

```c
int counter = 0;
```

`extern` is commonly used when sharing global objects between multiple source files.

---

# `volatile`

`volatile` tells the compiler that a value can change **unexpectedly**, so accesses to that object must not be optimized away or assumed to be unchanged.

```c
volatile int status;
```

For example, hardware registers are commonly accessed through `volatile`:

```c
volatile unsigned int *status =
    (volatile unsigned int *)0x40000000;
```

A value can also be changed by:

- hardware
- an interrupt handler
- another execution context where appropriate

For example:

```c
volatile int ready = 0;

while (!ready)
    ;
```

Without `volatile`, the compiler might assume `ready` cannot change inside the loop and optimize the loop incorrectly for a memory-mapped or externally modified object.

### Important

`volatile` does **not** make an operation atomic.

```c
volatile int counter;

counter++;
```

`counter++` can still involve multiple operations:

```text
read
modify
write
```

Therefore `volatile` is **not a replacement for atomic operations or synchronization**.

---

# `inline`

`inline` suggests that a function's code could be substituted directly at its call site.

```c
inline int square(int x)
{
    return x * x;
}
```

Instead of:

```c
int result = square(5);
```

the compiler may effectively generate something similar to:

```c
int result = 5 * 5;
```

However, `inline` is only a **request to the compiler**. The compiler decides whether to actually inline the function.

Modern compilers can also inline functions that are not marked `inline`.

`inline` can be particularly useful for small functions where avoiding function-call overhead may be beneficial.

> `inline` does not guarantee better performance.

---

# `const`

`const` specifies that an object should not be modified through that particular access path.

```c
const int x = 10;

// x = 20;    // error
```

The object should be initialized when it is defined:

```c
const int max_users = 100;
```

### Pointer and `const`

The position of `const` matters.

#### Pointer to const data

```c
const int *p;
```

or:

```c
int const *p;
```

The pointed-to value cannot be modified through `p`.

```c
int x = 10;
const int *p = &x;

// *p = 20;    // error
x = 20;        // allowed
```

#### Const pointer

```c
int *const p = &x;
```

The pointer itself cannot be changed:

```c
*p = 20;       // allowed

// p = &y;     // error
```

#### Const pointer to const data

```c
const int *const p = &x;
```

Neither the pointer nor the pointed-to value can be modified through `p`.

---

# Combining Qualifiers

These keywords can be combined when they serve different purposes.

For example:

```c
volatile const int status;
```

means:

- `const`: the program should not modify `status`
- `volatile`: the value may change unexpectedly

This combination can make sense for a hardware register that the program can only read:

```c
volatile const unsigned int STATUS =
    *(volatile const unsigned int *)0x40000000;
```