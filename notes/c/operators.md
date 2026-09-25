# C Operators

Operators perform operations on values and variables.

## Arithmetic

|Operator|Operation|Example|
|---|---|---|
|`+`|Addition|`a + b`|
|`-`|Subtraction|`a - b`|
|`*`|Multiplication|`a * b`|
|`/`|Division|`a / b`|
|`%`|Modulus (remainder)|`a % b`|

> Integer division discards the fractional part: `5 / 2` → `2`.

---

## Assignment

| Operator | Equivalent to |
| -------- | ------------- |
| `=`      | `a = b`       |
| `+=`     | `a = a + b`   |
| `-=`     | `a = a - b`   |
| `*=`     | `a = a * b`   |
| `/=`     | `a = a / b`   |
| `%=`     | `a = a % b`   |
| `&=`     | `a = a & b`   |
| `\|=`    | `a = a \| b`  |
| `^=`     | `a = a ^ b`   |
| `<<=`    | `a = a << b`  |
| `>>=`    | `a = a >> b`  |

---

## Comparison

Comparison operators produce `1` (true) or `0` (false).

|Operator|Meaning|
|---|---|
|`==`|Equal|
|`!=`|Not equal|
|`>`|Greater than|
|`<`|Less than|
|`>=`|Greater than or equal|
|`<=`|Less than or equal|

---

## Logical

|Operator|Meaning|
|---|---|
|`&&`|Logical AND|
|`\|`|Logical OR|
|`!`|Logical NOT|

```c
a && b    // true if both are non-zero
a || b    // true if either is non-zero
!a        // true if a is zero
```

---

## Increment / Decrement

|Operator|Operation|
|---|---|
|`++`|Increment by 1|
|`--`|Decrement by 1|

```c
i++;      // post-increment
++i;      // pre-increment

i--;      // post-decrement
--i;      // pre-decrement
```

The difference matters when the expression's value is used:

```c
int a = 5;
int b = a++;    // b = 5, a = 6

int c = 5;
int d = ++c;    // c = 6, d = 6
```

---

## Bitwise

Operate directly on individual bits.

|Operator|Operation|
|---|---|
|`&`|Bitwise AND|
|`\|`|Bitwise OR|
|`^`|Bitwise XOR|
|`~`|Bitwise NOT|
|`<<`|Left shift|
|`>>`|Right shift|

Example:

```c
unsigned char a = 0b1010;
unsigned char b = 0b1100;

a & b;    // 1000
a | b;    // 1110
a ^ b;    // 0110
~a;       // bitwise inversion
a << 1;   // 10100
a >> 1;   // 0101
```

Bitwise operators are especially important in **embedded programming** for manipulating registers and flags.

---

## Ternary Operator

```c
condition ? value_if_true : value_if_false
```

Example:

```c
int max = (a > b) ? a : b;
```

Equivalent to:

```c
int max;

if (a > b)
    max = a;
else
    max = b;
```

---
## `sizeof`

Returns the size of a type or object in bytes.

```c
sizeof x;
sizeof(x);
```

The result has type `size_t`.

---

## Address & Dereference

|Operator|Meaning|
|---|---|
|`&`|Address-of|
|`*`|Dereference|

```c
int x = 10;
int *p = &x;

*p = 20;    // changes x to 20
```

> `&` and `*` can have different meanings depending on context. With pointers, `&` obtains an address and `*` accesses the value at an address.

---

## Member Access

|Operator|Meaning|
|---|---|
|`.`|Access struct/union member|
|`->`|Access member through pointer|

```c
struct Point p;
p.x;

struct Point *ptr = &p;
ptr->x;
```

---

## Other Operators

|Operator|Purpose|
|---|---|
|`[]`|Array subscript|
|`()`|Function call|
|`(type)`|Type cast|
|`,`|Comma operator|

Examples:

```c
array[3];

function();

(int)3.14;

a = 1, b = 2;
```

---

## Operator Precedence

**Precedence** determines which operators are evaluated first.

**Associativity** determines the evaluation order when operators have the same precedence.

| Precedence | Operators                                                | Associativity |
| ---------- | -------------------------------------------------------- | ------------- |
| 1          | `()` `[]` `->` `.`                                       | Left → Right  |
| 2          | `++` `--`                                                | Left → Right  |
| 3          | `+ (unary)` `- (unary)` `!` `~` `(type)` `sizeof`        | Right → Left  |
| 4          | `*` `/` `%`                                              | Left → Right  |
| 5          | `+ (binary)` `- (binary)`                                | Left → Right  |
| 6          | `<<` `>>`                                                | Left → Right  |
| 7          | `<` `<=` `>` `>=`                                        | Left → Right  |
| 8          | `==` `!=`                                                | Left → Right  |
| 9          | `&`                                                      | Left → Right  |
| 10         | `^`                                                      | Left → Right  |
| 11         | `\|`                                                     | Left → Right  |
| 12         | `&&`                                                     | Left → Right  |
| 13         | `\|\|`                                                   | Left → Right  |
| 14         | `?:`                                                     | Right → Left  |
| 15         | `=` `+=` `-=` `*=` `/=` `%=` `&=` `\|=` `^=` `<<=` `>>=` | Right → Left  |
| 16         | `,`                                                      | Left → Right  |

> Unary `+` and `-` are included in the unary operator group: `+x` and `-x`.

> When in doubt, use parentheses to make the intended order explicit.