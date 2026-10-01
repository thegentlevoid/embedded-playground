# `<ctype.h>`

## Overview

The `<ctype.h>` header provides functions for classifying and converting individual characters.

The functions operate on an `int` value representing either:
- an `unsigned char` value, or
- `EOF`

This matters because passing a negative `char` value directly to these functions can cause undefined behavior.

---

## Character Classification

|Function|Prototype|Description|
|---|---|---|
|`isalnum()`|`int isalnum(int c);`|Checks whether `c` is an alphanumeric character.|
|`isalpha()`|`int isalpha(int c);`|Checks whether `c` is an alphabetic character.|
|`isblank()`|`int isblank(int c);`|Checks whether `c` is a blank character such as space or tab.|
|`iscntrl()`|`int iscntrl(int c);`|Checks whether `c` is a control character.|
|`isdigit()`|`int isdigit(int c);`|Checks whether `c` is a decimal digit (`0`–`9`).|
|`isgraph()`|`int isgraph(int c);`|Checks whether `c` is a printable character other than space.|
|`islower()`|`int islower(int c);`|Checks whether `c` is a lowercase letter.|
|`isprint()`|`int isprint(int c);`|Checks whether `c` is a printable character, including space.|
|`ispunct()`|`int ispunct(int c);`|Checks whether `c` is a punctuation character.|
|`isspace()`|`int isspace(int c);`|Checks whether `c` is a whitespace character.|
|`isupper()`|`int isupper(int c);`|Checks whether `c` is an uppercase letter.|
|`isxdigit()`|`int isxdigit(int c);`|Checks whether `c` is a hexadecimal digit.|

> `isblank()` was added in **C99**. The other classification functions are from C89/C90.

---

## Character Conversion

|Function|Prototype|Description|
|---|---|---|
|`tolower()`|`int tolower(int c);`|Converts an uppercase letter to lowercase.|
|`toupper()`|`int toupper(int c);`|Converts a lowercase letter to uppercase.|

If the character does not have a corresponding conversion, the original value is returned.

Example:

```c
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    printf("%c\n", tolower('A'));
    printf("%c\n", toupper('b'));

    return 0;
}
```

Output:

```text
a
B
```

---

# Classification Functions

## `isalnum()`

```c
int isalnum(int c);
```

Checks whether `c` is an alphanumeric character:

```text
A-Z
a-z
0-9
```

The exact set of alphabetic characters can depend on the current locale.

---

## `isalpha()`

```c
int isalpha(int c);
```

Checks whether `c` is an alphabetic character.

```text
A-Z
a-z
```

The exact set of alphabetic characters can depend on the current locale.

---

## `isblank()`

```c
int isblank(int c);
```

Checks for a blank character.

In the default C locale, this includes:

```text
space
tab
```

This function was added in C99.

---

## `iscntrl()`

```c
int iscntrl(int c);
```

Checks whether `c` is a control character.

Examples include characters such as:

```text
'\n'
'\t'
'\r'
```

---

## `isdigit()`

```c
int isdigit(int c);
```

Checks whether `c` is one of:

```text
0 1 2 3 4 5 6 7 8 9
```

Unlike `isalpha()`, `isdigit()` specifically tests decimal digits.

---

## `isgraph()`

```c
int isgraph(int c);
```

Checks whether `c` is a printable character other than a space.

For example:

```text
A
7
!
@
```

are graphical characters, while a space is not.

---

## `islower()`

```c
int islower(int c);
```

Checks whether `c` is a lowercase letter.

```c
if (islower(c))
{
    printf("Lowercase\n");
}
```

---

## `isprint()`

```c
int isprint(int c);
```

Checks whether `c` is a printable character, including space.

The difference between `isprint()` and `isgraph()` is:

```text
isprint() → printable characters + space
isgraph() → printable characters excluding space
```

---

## `ispunct()`

```c
int ispunct(int c);
```

Checks whether `c` is a punctuation character.

Examples:

```text
!
.
,
?
;
:
(
)
[
]
```

---

## `isspace()`

```c
int isspace(int c);
```

Checks whether `c` is a whitespace character.

Common examples include:

```text
' '
'\t'
'\n'
'\v'
'\f'
'\r'
```

This is particularly useful when parsing text.

---

## `isupper()`

```c
int isupper(int c);
```

Checks whether `c` is an uppercase letter.

---

## `isxdigit()`

```c
int isxdigit(int c);
```

Checks whether `c` is a hexadecimal digit:

```text
0-9
a-f
A-F
```

This can be useful when parsing hexadecimal values from serial input.

---

# Return Values

The classification functions return:

```text
nonzero → condition is true
0       → condition is false
```

For example:

```c
if (isdigit(c))
{
    /* c is a digit */
}
```

Do **not** assume that a true result is specifically `1`.

This is the same general rule used by the C library's classification functions.

---

# Important Argument Rule

The argument to the `<ctype.h>` functions must be:

```text
EOF
```

or a value representable as:

```c
unsigned char
```

A common problem occurs when `char` is signed.

Avoid:

```c
char c = ...;

if (isdigit(c))
{
    /* ... */
}
```

when `c` may contain a negative value.

Instead:

```c
if (isdigit((unsigned char)c))
{
    /* ... */
}
```

This is particularly relevant when processing arbitrary bytes received from hardware interfaces.

---

# Example: Validate a Decimal String

```c
#include <ctype.h>
#include <stdio.h>

int is_decimal(const char *str)
{
    if (*str == '\0')
        return 0;

    while (*str != '\0')
    {
        if (!isdigit((unsigned char)*str))
            return 0;

        str++;
    }

    return 1;
}

int main(void)
{
    printf("%d\n", is_decimal("12345"));
    printf("%d\n", is_decimal("123a45"));

    return 0;
}
```

Output:

```text
1
0
```

---

# Embedded Use

`<ctype.h>` can be useful when processing textual data received through interfaces such as:

```text
UART
USB
Bluetooth
Wi-Fi
TCP/IP
```

For example, a command parser might receive:

```text
SET PWM 2500
```

and use:

```c
isspace()
isdigit()
isalpha()
toupper()
tolower()
```

to tokenize and validate the input.

For binary protocols, however, `<ctype.h>` is generally unnecessary because the data is not character-oriented.