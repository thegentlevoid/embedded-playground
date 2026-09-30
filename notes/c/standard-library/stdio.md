# `<stdio.h>`

## Overview

The `<stdio.h>` header provides functions and types for:

- Character and string input/output
- File input/output
- Formatted input/output
- File positioning
- Temporary files
- Error handling
- Stream management

---

## Functions

| Function                    | Prototype                                                                                            | Description                                                              |
| --------------------------- | ---------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| [`fopen()`](#fopen)         | `FILE *fopen(const char * restrict filename, const char * restrict mode);`                           | Opens a file and associates it with a stream.                            |
| [`freopen()`](#freopen)     | `FILE *freopen(const char * restrict filename, const char * restrict mode, FILE * restrict stream);` | Opens a file and associates it with an existing stream.                  |
| [`fclose()`](#fclose)       | `int fclose(FILE *stream);`                                                                          | Closes a stream.                                                         |
| [`tmpfile()`](#tmpfile)     | `FILE *tmpfile(void);`                                                                               | Creates a temporary file that is automatically removed when closed.      |
| [`tmpnam()`](#tmpnam)       | `char *tmpnam(char *s);`                                                                             | Generates a temporary filename.                                          |
| [`fflush()`](#fflush)       | `int fflush(FILE *stream);`                                                                          | Flushes buffered output for a stream.                                    |
| [`setbuf()`](#setbuf)       | `void setbuf(FILE * restrict stream, char * restrict buf);`                                          | Controls buffering for a stream.                                         |
| [`setvbuf()`](#setvbuf)     | `int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);`                   | Controls buffering mode and buffer size for a stream.                    |
| [`remove()`](#remove)       | `int remove(const char *filename);`                                                                  | Removes a file.                                                          |
| [`rename()`](#rename)       | `int rename(const char *old, const char *new);`                                                      | Renames a file.                                                          |
| [`putchar()`](#putchar)     | `int putchar(int c);`                                                                                | Writes one character to `stdout`.                                        |
| [`putc()`](#putc)           | `int putc(int c, FILE *stream);`                                                                     | Writes one character to a stream.                                        |
| [`fputc()`](#fputc)         | `int fputc(int c, FILE *stream);`                                                                    | Writes one character to a stream.                                        |
| [`getchar()`](#getchar)     | `int getchar(void);`                                                                                 | Reads one character from `stdin`.                                        |
| [`getc()`](#getc)           | `int getc(FILE *stream);`                                                                            | Reads one character from a stream.                                       |
| [`fgetc()`](#fgetc)         | `int fgetc(FILE *stream);`                                                                           | Reads one character from a stream.                                       |
| [`ungetc()`](#ungetc)       | `int ungetc(int c, FILE *stream);`                                                                   | Pushes a character back onto a stream.                                   |
| [`gets()`](#gets)           | `char *gets(char *s);`                                                                               | Reads a line from `stdin`. **Removed in C11; unsafe.**                   |
| [`fgets()`](#fgets)         | `char *fgets(char * restrict s, int n, FILE * restrict stream);`                                     | Reads a line or up to `n - 1` characters from a stream.                  |
| [`puts()`](#puts)           | `int puts(const char *s);`                                                                           | Writes a string to `stdout` followed by a newline.                       |
| [`fputs()`](#fputs)         | `int fputs(const char * restrict s, FILE * restrict stream);`                                        | Writes a string to a stream.                                             |
| [`printf()`](#printf)       | `int printf(const char * restrict format, ...);`                                                     | Writes formatted output to `stdout`.                                     |
| [`fprintf()`](#fprintf)     | `int fprintf(FILE * restrict stream, const char * restrict format, ...);`                            | Writes formatted output to a stream.                                     |
| [`sprintf()`](#sprintf)     | `int sprintf(char * restrict s, const char * restrict format, ...);`                                 | Writes formatted output to a string.                                     |
| [`snprintf()`](#snprintf)   | `int snprintf(char * restrict s, size_t n, const char * restrict format, ...);`                      | Writes formatted output to a string with a size limit.                   |
| [`scanf()`](#scanf)         | `int scanf(const char * restrict format, ...);`                                                      | Reads formatted input from `stdin`.                                      |
| [`fscanf()`](#fscanf)       | `int fscanf(FILE * restrict stream, const char * restrict format, ...);`                             | Reads formatted input from a stream.                                     |
| [`sscanf()`](#sscanf)       | `int sscanf(const char * restrict s, const char * restrict format, ...);`                            | Reads formatted input from a string.                                     |
| [`vprintf()`](#vprintf)     | `int vprintf(const char * restrict format, va_list arg);`                                            | Writes formatted output to `stdout` using a `va_list`.                   |
| [`vfprintf()`](#vfprintf)   | `int vfprintf(FILE * restrict stream, const char * restrict format, va_list arg);`                   | Writes formatted output to a stream using a `va_list`.                   |
| [`vsprintf()`](#vsprintf)   | `int vsprintf(char * restrict s, const char * restrict format, va_list arg);`                        | Writes formatted output to a string using a `va_list`.                   |
| [`vsnprintf()`](#vsnprintf) | `int vsnprintf(char * restrict s, size_t n, const char * restrict format, va_list arg);`             | Writes formatted output to a string with a size limit using a `va_list`. |
| [`fread()`](#fread)         | `size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);`              | Reads an array of objects from a stream.                                 |
| [`fwrite()`](#fwrite)       | `size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);`       | Writes an array of objects to a stream.                                  |
| [`fseek()`](#fseek)         | `int fseek(FILE *stream, long int offset, int whence);`                                              | Changes the file position.                                               |
| [`ftell()`](#ftell)         | `long int ftell(FILE *stream);`                                                                      | Returns the current file position.                                       |
| [`rewind()`](#rewind)       | `void rewind(FILE *stream);`                                                                         | Moves the file position to the beginning.                                |
| [`fgetpos()`](#fgetpos)     | `int fgetpos(FILE * restrict stream, fpos_t * restrict pos);`                                        | Stores the current file position.                                        |
| [`fsetpos()`](#fsetpos)     | `int fsetpos(FILE *stream, const fpos_t *pos);`                                                      | Restores a previously stored file position.                              |
| [`feof()`](#feof)           | `int feof(FILE *stream);`                                                                            | Tests whether the end-of-file indicator is set.                          |
| [`ferror()`](#ferror)       | `int ferror(FILE *stream);`                                                                          | Tests whether the error indicator is set.                                |
| [`clearerr()`](#clearerr)   | `void clearerr(FILE *stream);`                                                                       | Clears the end-of-file and error indicators.                             |
| [`perror()`](#perror)       | `void perror(const char *s);`                                                                        | Writes a description of the current error to `stderr`.                   |

---

## Streams

C performs I/O through **streams**.

The three standard streams are:

|Stream|Purpose|
|---|---|
|`stdin`|Standard input|
|`stdout`|Standard output|
|`stderr`|Standard error output|

For example:

```c
printf("Hello\n");
```

writes to `stdout`.

```c
fprintf(stderr, "Something went wrong\n");
```

writes to `stderr`.

---

## Types

### `FILE`

`FILE` is an object type that represents a stream.

```c
FILE *file;
```

A `FILE *` is used with most file I/O functions.

For example:

```c
FILE *file = fopen("data.txt", "r");
```

### `fpos_t`

`fpos_t` is a type capable of representing a position within a file.

It is used by functions such as:

```c
fgetpos()
fsetpos()
```

---

# 1. File Operations

## `fopen()`

```c
FILE *fopen(const char * restrict filename, const char * restrict mode);
```

`fopen()` opens a file and associates it with a stream.

```c
FILE *file = fopen("data.txt", "r");

if (file == NULL)
{
    perror("data.txt");
    return 1;
}
```

It returns a pointer to the newly opened stream on success.

If the file cannot be opened, it returns `NULL`.

Always check the return value before using the stream.

---

## File Modes

The second argument to `fopen()` specifies how the file should be opened.

| Mode               | Meaning                                                        |
| ------------------ | -------------------------------------------------------------- |
| `"r"`              | Open for reading                                               |
| `"w"`              | Open for writing; creates or truncates the file                |
| `"a"`              | Open for appending; creates if necessary                       |
| `"r+"`             | Open for reading and writing                                   |
| `"w+"`             | Open for reading and writing; creates or truncates             |
| `"a+"`             | Open for reading and appending                                 |
| `"rb"`             | Open binary file for reading                                   |
| `"wb"`             | Open binary file for writing                                   |
| `"ab"`             | Open binary file for appending                                 |
| `"rb+"` or `"r+b"` | Open binary file for reading and writing                       |
| `"wb+"` or `"w+b"` | Open binary file for reading and writing; creates or truncates |
| `"ab+"` or `"a+b"` | Open binary file for reading and appending                     |

---

### `"r"`

The file must already exist.

```c
FILE *file = fopen("data.txt", "r");
```

---

### `"w"`

Creates a new file or truncates an existing file.

```c
FILE *file = fopen("data.txt", "w");
```

Be careful: opening an existing file with `"w"` destroys its previous contents.

---

### `"a"`

Opens the file for appending.

```c
FILE *file = fopen("log.txt", "a");
```

If the file does not exist, it is created.

---

### `"r+"`

Opens an existing file for both reading and writing.

```c
FILE *file = fopen("data.txt", "r+");
```

The file must already exist.

---

### `"w+"`

Opens a file for both reading and writing.

```c
FILE *file = fopen("data.txt", "w+");
```

The file is created if necessary and truncated if it already exists.

---

### `"a+"`

Opens a file for reading and appending.

```c
FILE *file = fopen("log.txt", "a+");
```

The file is created if it does not exist.

---

## `freopen()`

```c
FILE *freopen(const char * restrict filename, const char * restrict mode, FILE * restrict stream);
```

`freopen()` opens a file and associates it with an existing stream.

```c
FILE *result = freopen(
    "output.txt",
    "w",
    stdout
);
```

After this, output written to `stdout` is redirected to `output.txt`.

For example:

```c
freopen("output.txt", "w", stdout);

printf("This goes into the file\n");
```

It returns the supplied `stream` on success.

If the operation fails, it returns `NULL`.

The original stream is closed before the new file is associated with it.

---

## `fclose()`

```c
int fclose(FILE *stream);
```

`fclose()` closes a stream.

```c
FILE *file = fopen("data.txt", "r");

if (file != NULL)
{
    /* use file */

    fclose(file);
}
```

It also flushes buffered output associated with the stream.

It returns:

* `0` on success
* `EOF` if an error occurs

After `fclose()`, the `FILE *` must not be used with further I/O operations.

---

# 2. Temporary Files

## `tmpfile()`

```c
FILE *tmpfile(void);
```

`tmpfile()` creates a temporary binary file and returns a stream associated with it.

```c
FILE *file = tmpfile();

if (file == NULL)
{
    perror("tmpfile");
    return 1;
}

fprintf(file, "Temporary data\n");

fclose(file);
```

The temporary file is automatically removed when it is closed.

It returns:

* A `FILE *` on success
* `NULL` if the temporary file could not be created

---

## `tmpnam()`

```c
char *tmpnam(char *s);
```

`tmpnam()` generates a temporary filename.

```c
char name[L_tmpnam];

if (tmpnam(name) != NULL)
{
    printf("%s\n", name);
}
```

If `s` is not `NULL`, the generated filename is written into the supplied buffer.

If `s` is `NULL`, the implementation may return a pointer to an internal buffer.

It returns:

* A pointer to the generated filename on success
* `NULL` if a suitable filename cannot be generated

`tmpnam()` has security and portability limitations and should generally be avoided when safer platform-specific temporary-file mechanisms are available.

---

# 3. Stream Buffering

C streams may buffer output instead of immediately sending it to the underlying device.

Buffering can improve performance by reducing the number of interactions with the underlying file or device.

## `fflush()`

```c
int fflush(FILE *stream);
```

`fflush()` flushes buffered output for a stream.

```c
printf("Hello");

fflush(stdout);
```

This can be useful when output must appear immediately.

For an output stream, `fflush()` causes buffered data to be written.

It returns:

* `0` on success
* `EOF` if a write error occurs

`fflush()` should not be used as a general-purpose way to clear input.

---

## `setbuf()`

```c
void setbuf(FILE * restrict stream, char * restrict buf);
```

`setbuf()` controls whether a stream is buffered.

```c
char buffer[BUFSIZ];

setbuf(stdout, buffer);
```

Passing `NULL` disables buffering:

```c
setbuf(stdout, NULL);
```

`setbuf()` does not return a value.

The buffer supplied to `setbuf()` must remain available for the lifetime of the stream's use of that buffer.

>The `setbuf()` function is considered obsolete; it’s not recommended for use in new programs.

---

## `setvbuf()`

```c
int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);
```

`setvbuf()` provides more control over buffering.

```c
char buffer[BUFSIZ];

int result = setvbuf(
    stdout,
    buffer,
    _IOFBF,
    sizeof(buffer)
);
```

The buffering modes are:

| Mode     | Meaning        |
| -------- | -------------- |
| `_IOFBF` | Fully buffered |
| `_IOLBF` | Line buffered  |
| `_IONBF` | Unbuffered     |

It returns:

* `0` on success
* Nonzero if the requested buffering could not be established

`setvbuf()` must be called after the stream has been associated with a file but before other operations have been performed on the stream.

---
# 4. Miscellaneous File Operations
## `remove()`

```c
int remove(const char *filename);
```

`remove()` removes a file.

```c
if (remove("data.txt") != 0)
{
    perror("remove");
}
```

It returns:

* `0` on success
* Nonzero on failure

---

## `rename()`

```c
int rename(const char *old, const char *new);
```

`rename()` changes the name of a file.

```c
if (rename("old.txt", "new.txt") != 0)
{
    perror("rename");
}
```

It returns:

* `0` on success
* Nonzero on failure

---

# 5. Formatted I/O

## `printf()`

```c
int printf(const char * restrict format, ...);
```

`printf()` writes formatted output to `stdout`.

```c
int age = 25;

printf("Age: %d\n", age);
```

`printf()` returns the number of characters transmitted on success.

If an output or encoding error occurs, it returns a negative value.

> For more information about format strings see [[format-specifiers]]

---

## `fprintf()`

```c
int fprintf(FILE * restrict stream, const char * restrict format, ...);
```

`fprintf()` writes formatted output to a specified stream.

```c
fprintf(stdout, "Value: %d\n", 42);
```

It can write to `stderr`:

```c
fprintf(stderr, "Something went wrong\n");
```

Or to a file:

```c
FILE *file = fopen("output.txt", "w");

if (file != NULL)
{
    fprintf(file, "Value: %d\n", 42);
    fclose(file);
}
```

It returns the number of characters transmitted on success.

If an output or encoding error occurs, it returns a negative value.

---

## `sprintf()`

```c
int sprintf(char * restrict s, const char * restrict format, ...);
```

`sprintf()` writes formatted output into a character array.

```c
char buffer[100];

sprintf(buffer, "Value: %d", 42);

printf("%s\n", buffer);
```

The problem is that `sprintf()` does not know the size of `buffer`.

For example:

```c
char buffer[10];

sprintf(buffer, "This string is too long");
```

can overflow the buffer.

Prefer `snprintf()` when available.

`sprintf()` returns the number of characters that would have been written, excluding the terminating `'\0'`, on success.

If an encoding or other output error occurs, it returns a negative value.

---

## `snprintf()`

```c
int snprintf(char * restrict s, size_t n, const char * restrict format, ...);
```

`snprintf()` writes formatted output into a character array with a specified size limit.

```c
char buffer[20];

snprintf(
    buffer,
    sizeof(buffer),
    "Value: %d",
    42
);
```

The size argument includes space for the terminating `'\0'`.

For example:

```c
char buffer[10];

int n = snprintf(
    buffer,
    sizeof(buffer),
    "Hello, world!"
);
```

The resulting buffer contains a truncated string that still fits in the buffer.

The return value is the number of characters that **would have been written**, excluding the terminating `'\0'`.

This makes it possible to detect truncation:

```c
if (n >= sizeof(buffer))
{
    printf("Output was truncated\n");
}
```

If `n` is negative, an encoding or output error occurred.

---

## `scanf()`

```c
int scanf(const char * restrict format, ...);
```

`scanf()` reads formatted input from `stdin`.

```c
int age;

scanf("%d", &age);
```

Notice that `scanf()` receives the address of the variable:

```c
&age
```

because it must modify the variable.

### Return value

`scanf()` returns the number of input items successfully assigned.

For example:

```c
int age;
double height;

int result = scanf("%d %lf", &age, &height);
```

If both conversions succeed:

```text
result == 2
```

If only the first succeeds:

```text
result == 1
```

If no conversion succeeds:

```text
result == 0
```

If the input ends before any conversion can be performed:

```text
result == EOF
```

Always check the return value when input validity matters.

---

## `fscanf()`

```c
int fscanf(FILE * restrict stream, const char * restrict format, ...);
```

`fscanf()` reads formatted input from a stream.

```c
FILE *file = fopen("data.txt", "r");

if (file != NULL)
{
    int value;

    if (fscanf(file, "%d", &value) == 1)
    {
        printf("Value: %d\n", value);
    }

    fclose(file);
}
```

Its return value follows the same rules as `scanf()`:

* Number of successfully assigned input items
* `0` if no conversion was performed
* `EOF` if input ended before the first conversion could be performed

---

## `sscanf()`

```c
int sscanf(const char * restrict s, const char * restrict format, ...);
```

`sscanf()` reads formatted input from a string.

```c
int value;

if (sscanf("123", "%d", &value) == 1)
{
    printf("%d\n", value);
}
```

This is useful when input has already been read into a buffer.

For example:

```c
char input[100];

if (fgets(input, sizeof(input), stdin) != NULL)
{
    int value;

    if (sscanf(input, "%d", &value) == 1)
    {
        printf("Value: %d\n", value);
    }
}
```

It returns the number of input items successfully assigned.

It returns `0` if no conversion is performed.

It returns `EOF` if the input string ends before the first conversion can be performed.

---

# 6. Variadic Formatted I/O

The `v` versions of the formatted I/O functions accept a `va_list`.

They are mainly useful when implementing your own variadic functions.

```c
#include <stdio.h>
#include <stdarg.h>

void log_message(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}
```

The functions are:

```text
vprintf()
vfprintf()
vsprintf()
vsnprintf()
```

See [[stdarg]] for information about `va_list`, `va_start()`, and `va_end()`.

## `vprintf()`

```c
int vprintf(const char * restrict format, va_list arg);
```

Writes formatted output to `stdout` using a `va_list`.

It returns the number of characters transmitted on success, or a negative value if an output or encoding error occurs.

## `vfprintf()`

```c
int vfprintf(FILE * restrict stream, const char * restrict format, va_list arg);
```

Writes formatted output to a specified stream using a `va_list`.

It returns the number of characters transmitted on success, or a negative value if an output or encoding error occurs.

## `vsprintf()`

```c
int vsprintf(char * restrict s, const char * restrict format, va_list arg);
```

Writes formatted output to a character array using a `va_list`.

It has the same buffer-overflow concerns as `sprintf()`.

It returns the number of characters that would have been written, excluding the terminating `'\0'`, or a negative value on error.

## `vsnprintf()`

```c
int vsnprintf(char * restrict s, size_t n, const char * restrict format, va_list arg);
```

Writes formatted output to a character array with a size limit using a `va_list`.

It returns the number of characters that would have been written, excluding the terminating `'\0'`, or a negative value on error.

---

# 7. Character I/O

## `fgetc()`

```c
int fgetc(FILE *stream);
```

`fgetc()` reads one character from a stream.

```c
int c = fgetc(stdin);

if (c != EOF)
{
    printf("Character: %c\n", c);
}
```

The result is stored in an `int`, not a `char`.

This is necessary because `fgetc()` must be able to represent every possible character value as well as `EOF`.

It returns:

* The character converted to `unsigned char` and then to `int` on success
* `EOF` if an error occurs or the end-of-file indicator is encountered

Example:

```c
int c;

while ((c = fgetc(stdin)) != EOF)
{
    putchar(c);
}
```

---

## `getc()`

```c
int getc(FILE *stream);
```

`getc()` reads one character from a stream.

```c
int c = getc(stdin);
```

It is equivalent to `fgetc()` for normal use, but it may be implemented as a macro.

It returns the character as an `int`, or `EOF` on end-of-file or error.

Because it may be a macro, avoid passing arguments with side effects:

```c
/* Avoid */
getc(streams[index++]);
```

---

## `getchar()`

```c
int getchar(void);
```

`getchar()` reads one character from `stdin`.

```c
int c = getchar();

if (c != EOF)
{
    printf("%c\n", c);
}
```

It is effectively:

```c
getc(stdin);
```

It returns the character as an `int`, or `EOF` on end-of-file or error.

---
### `ungetc()`

```c
int ungetc(int c, FILE *stream);
```

Pushes the character `c` back onto the input stream. The next input operation on `stream` will read that character again.

This is useful when a parser reads one character too far and needs to return it to the stream.

```c
#include <stdio.h>

int main(void)
{
    int c = fgetc(stdin);

    if (c == 'x')
        ungetc(c, stdin);

    c = fgetc(stdin);
    printf("Read: %c\n", c);

    return 0;
}
```

If the first character is `x`, `ungetc()` pushes it back, so the second `fgetc()` reads `x` again.

#### Return Value

- Returns the pushed-back character converted to `unsigned char` and then to `int` on success.
- Returns `EOF` if the operation fails.
- `EOF` itself cannot be pushed back.
- The C standard guarantees that at least **one character** of pushback is supported.

A successful `ungetc()` also clears the stream's EOF indicator.

#### Example: Look Ahead

`ungetc()` is useful when processing input one character at a time and discovering that the current character belongs to the next token.

```c
int c;

while ((c = fgetc(stdin)) != EOF)
{
    if (c >= '0' && c <= '9')
    {
        ungetc(c, stdin);
        break;
    }
}
```

Here, the loop stops when it encounters a digit, but puts that digit back so that the next part of the parser can read it normally.

> The number of characters that can be pushed back by consecutive calls of `ungetc()`—with no intervening read operations—depends on the implementation and the type of stream involved; only the first call is guaranteed to succeed.

>Calling a file-positioning function (`fseek()`, `fsetpos()`, or `rewind()`) causes the pushed back characters to be lost.

> `ungetc()` returns the character it was asked to push back. However, it returns EOF if an attempt is made to push back EOF or to push back more characters than the implementation allows.

---

## `fputc()`

```c
int fputc(int c, FILE *stream);
```

`fputc()` writes one character to a stream.

```c
fputc('A', stdout);
```

It returns:

* The character written, converted to `unsigned char` and then to `int`, on success
* `EOF` if an error occurs

---

## `putc()`

```c
int putc(int c, FILE *stream);
```

`putc()` writes one character to a stream.

```c
putc('A', stdout);
```

It is equivalent to `fputc()` for normal use and may be implemented as a macro.

It returns the character written on success, or `EOF` on error.

Because it may be a macro, avoid arguments with side effects.

---

## `putchar()`

```c
int putchar(int c);
```

`putchar()` writes one character to `stdout`.

```c
putchar('A');
```

It is effectively:

```c
putc('A', stdout);
```

It returns the character written on success, or `EOF` on error.

---

# 8. Line I/O

## `fgets()`

```c
char *fgets(char * restrict s, int n, FILE * restrict stream);
```

`fgets()` reads characters from a stream into a character array.

```c
char buffer[100];

if (fgets(buffer, sizeof(buffer), stdin) != NULL)
{
    printf("Input: %s", buffer);
}
```

It reads at most `n - 1` characters and always adds a terminating `'\0'` when at least one character is read.

If a newline is encountered before the buffer fills, the newline is stored in the buffer.

For input:

```text
Hello
```

the buffer contains approximately:

```text
'H' 'e' 'l' 'l' 'o' '\n' '\0'
```

It returns:

* `s` on success
* `NULL` if no characters were read because of an error or end-of-file

---

## `gets()`

```c
char *gets(char *s);
```

`gets()` reads a line from `stdin`.

```c
char buffer[100];

gets(buffer);
```

However, `gets()` provides no way to specify the size of the destination buffer.

Input longer than the destination array can therefore overflow it.

**Do not use `gets()`.**

Use:

```c
fgets(buffer, sizeof(buffer), stdin);
```

instead.

`gets()` was removed from the C standard in C11, but it is important to recognize it when reading older C code.

---

## `fputs()`

```c
int fputs(const char * restrict s, FILE * restrict stream);
```

`fputs()` writes a null-terminated string to a stream.

```c
fputs("Hello\n", stdout);
```

Unlike `puts()`, it does **not** automatically append a newline.

```c
fputs("Hello", stdout);
```

It returns:

* A nonnegative value on success
* `EOF` if a write error occurs

---

## `puts()`

```c
int puts(const char *s);
```

`puts()` writes a null-terminated string to `stdout` and automatically adds a newline.

```c
puts("Hello");
```

It is roughly equivalent to:

```c
fputs("Hello", stdout);
putchar('\n');
```

It returns:

* A nonnegative value on success
* `EOF` if a write error occurs

---

# 9. Block I/O

## `fwrite()`

```c
size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);
```

`fwrite()` writes an array of objects to a stream.

```c
int numbers[] = {1, 2, 3, 4, 5};

size_t count = fwrite(
    numbers,
    sizeof(numbers[0]),
    5,
    file
);
```

The arguments are:

```text
ptr    → source
size   → size of each object
nmemb  → number of objects
stream → output stream
```

The return value is the number of objects successfully written.

It may be less than `nmemb` if an output error occurs.

For example:

```c
if (count != 5)
{
    printf("Write error\n");
}
```

Again, the return value is the number of **objects**, not bytes.

---

## `fread()`

```c
size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);
```

`fread()` reads an array of objects from a stream.

```c
int numbers[5];

size_t count = fread(
    numbers,
    sizeof(numbers[0]),
    5,
    file
);
```

The arguments are:

```text
ptr    → destination
size   → size of each object
nmemb  → number of objects
stream → input stream
```

The return value is the number of objects successfully read.

It may be less than `nmemb` if the end of the file is reached or an error occurs.

For example:

```c
if (count != 5)
{
    if (feof(file))
        printf("Reached end of file\n");

    if (ferror(file))
        printf("Read error\n");
}
```

The return value is a count of **objects**, not bytes.

---

# 10. File Positioning

A stream maintains a current file position.

File-positioning functions allow you to move to another position or save and restore a position.

## `fseek()`

```c
int fseek(FILE *stream, long int offset, int whence);
```

`fseek()` changes the current file position.

```c
fseek(file, 0, SEEK_SET);
```

The `whence` argument determines how the offset is interpreted.

| Value      | Meaning           |
| ---------- | ----------------- |
| `SEEK_SET` | Beginning of file |
| `SEEK_CUR` | Current position  |
| `SEEK_END` | End of file       |

For example:

```c
fseek(file, 10, SEEK_SET);
```

moves to position 10 from the beginning.

```c
fseek(file, 5, SEEK_CUR);
```

moves 5 positions forward from the current position.

```c
fseek(file, -10, SEEK_END);
```

moves 10 positions backward from the end.

It returns:

* `0` on success
* Nonzero on failure

---

## `ftell()`

```c
long int ftell(FILE *stream);
```

`ftell()` returns the current file position.

```c
long position = ftell(file);

if (position == -1L)
{
    perror("ftell");
}
```

It returns the current position on success.

If an error occurs, it returns `-1L`.

---

## `rewind()`

```c
void rewind(FILE *stream);
```

`rewind()` moves the file position to the beginning.

```c
rewind(file);
```

It is effectively a convenient way to return to the beginning of a stream.

It also clears the stream's error indicator.

`rewind()` does not return a value.

---

## `fgetpos()`

```c
int fgetpos(FILE * restrict stream, fpos_t * restrict pos);
```

`fgetpos()` stores the current file position in an `fpos_t` object.

```c
fpos_t position;

if (fgetpos(file, &position) != 0)
{
    /* error */
}
```

It returns:

* `0` on success
* Nonzero on failure

---

## `fsetpos()`

```c
int fsetpos(FILE *stream, const fpos_t *pos);
```

`fsetpos()` restores a previously saved file position.

```c
fpos_t position;

fgetpos(file, &position);

/* move somewhere else */

fsetpos(file, &position);
```

It returns:

* `0` on success
* Nonzero on failure

---

# 11. Error Handling

## `feof()`

```c
int feof(FILE *stream);
```

`feof()` checks whether the end-of-file indicator is set.

A common mistake is:

```c
while (!feof(file))
{
    c = fgetc(file);
}
```

This is incorrect because `feof()` becomes true **after** an operation attempts to read past the end of the file.

Instead, test the read operation:

```c
int c;

while ((c = fgetc(file)) != EOF)
{
    putchar(c);
}

if (feof(file))
{
    printf("Reached EOF\n");
}
```

`feof()` returns:

* Nonzero if the end-of-file indicator is set
* `0` otherwise

---

## `ferror()`

```c
int ferror(FILE *stream);
```

`ferror()` checks whether the stream's error indicator is set.

```c
if (ferror(file))
{
    fprintf(stderr, "File read error\n");
}
```

It returns:

* Nonzero if the error indicator is set
* `0` otherwise

A read loop can therefore distinguish EOF from an actual error:

```c
int c;

while ((c = fgetc(file)) != EOF)
{
    putchar(c);
}

if (ferror(file))
{
    fprintf(stderr, "Read error\n");
}
else if (feof(file))
{
    printf("Reached EOF\n");
}
```

---

## `clearerr()`

```c
void clearerr(FILE *stream);
```

`clearerr()` clears both the end-of-file and error indicators.

```c
clearerr(file);
```

After this call:

```c
feof(file)
```

and:

```c
ferror(file)
```

will return `0` until another operation sets the corresponding indicator.

`clearerr()` does not return a value.

---

## `perror()`

```c
void perror(const char *s);
```

`perror()` writes a description of the current error to `stderr`.

```c
FILE *file = fopen("missing.txt", "r");

if (file == NULL)
{
    perror("fopen");
    return 1;
}
```

A typical result might look like:

```text
fopen: No such file or directory
```

The exact message depends on the host environment.

`perror()` uses the current value of `errno`.

See [[errno]] for more information.

`perror()` does not return a value.

---

# Important Macros

## `EOF`

`EOF` is a negative integer constant used to indicate end-of-file or an input error.

```c
int c;

while ((c = getchar()) != EOF)
{
    putchar(c);
}
```

Because `EOF` must be distinguishable from every possible character value, character-input functions return `int` rather than `char`.

---

## `SEEK_SET`

Positions relative to the beginning of a file.

```c
fseek(file, 0, SEEK_SET);
```

---

## `SEEK_CUR`

Positions relative to the current file position.

```c
fseek(file, 10, SEEK_CUR);
```

---

## `SEEK_END`

Positions relative to the end of a file.

```c
fseek(file, 0, SEEK_END);
```

---

## `BUFSIZ`

Specifies the size of a buffer suitable for use with `setbuf()`.

```c
char buffer[BUFSIZ];

setbuf(stdout, buffer);
```

---

## `FILENAME_MAX`

Specifies the maximum size of a filename supported by the implementation.

```c
char filename[FILENAME_MAX];
```

---

## `FOPEN_MAX`

Specifies the minimum number of files that the implementation guarantees can be open simultaneously.

---

# Common Patterns

## Reading a line safely

```c
char buffer[100];

if (fgets(buffer, sizeof(buffer), stdin) != NULL)
{
    printf("You entered: %s", buffer);
}
```

## Reading a file character by character

```c
FILE *file = fopen("data.txt", "r");

if (file == NULL)
    return 1;

int c;

while ((c = fgetc(file)) != EOF)
{
    putchar(c);
}

if (ferror(file))
{
    fprintf(stderr, "Error reading file\n");
}

fclose(file);
```

## Writing a file

```c
FILE *file = fopen("data.txt", "w");

if (file == NULL)
    return 1;

fprintf(file, "Hello\n");
fprintf(file, "Value: %d\n", 42);

fclose(file);
```

## Copying a file

```c
FILE *src = fopen("input.txt", "rb");
FILE *dst = fopen("output.txt", "wb");

if (src == NULL || dst == NULL)
    return 1;

char buffer[4096];

size_t n;

while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0)
{
    if (fwrite(buffer, 1, n, dst) != n)
    {
        fprintf(stderr, "Write error\n");
        break;
    }
}

fclose(src);
fclose(dst);
```

---

# `<stdio.h>` and Embedded Systems

Much of `<stdio.h>` is designed around a hosted environment with files and standard streams.

On a microcontroller, functions such as:

```c
fopen()
fread()
fwrite()
```

may not have meaningful filesystem support unless a filesystem and C library integration are provided.

However, formatted output is still commonly useful for debugging:

```c
printf("Temperature: %d\n", temperature);
```

On embedded systems, `printf()` is often redirected to:

* UART
* USB CDC
* SWO
* debugger console
* another device interface

The underlying implementation can therefore be very different from a desktop system.