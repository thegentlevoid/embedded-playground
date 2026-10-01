# C Standard Library

The C standard library provides standardized headers containing functions, macros, and types for common programming tasks.

This section covers the following standard headers:

| Header                        | General Purpose                                                              | Introduced |
| ----------------------------- | ---------------------------------------------------------------------------- | ---------- |
| [`<assert.h>`](assert.md)     | Runtime assertions for detecting programming errors                          |        C89 |
| `<complex.h>`                 | Complex number types and operations                                          |        C99 |
| [`<ctype.h>`](ctype.md)       | Character classification and case conversion                                 |        C89 |
| [`<errno.h>`](errno.md)       | Error reporting through `errno` and related macros                           |        C89 |
| `<fenv.h>`                    | Control and access to the floating-point environment                         |        C99 |
| [`<float.h>`](float.md)       | Properties and limits of floating-point types                                |        C89 |
| [`<inttypes.h>`](inttypes.md) | Integer formatting, conversion, and compatibility macros                     |        C99 |
| `<iso646.h>`                  | Alternative spellings for certain C operators                                |        C99 |
| [`<limits.h>`](limits.md)     | Limits of integer types                                                      |        C89 |
| `<locale.h>`                  | Localization and locale-dependent behavior                                   |        C89 |
| [`<math.h>`](math.md)         | Mathematical functions and constants                                         |        C89 |
| `<setjmp.h>`                  | Non-local jumps using `setjmp` and `longjmp`                                 |        C89 |
| `<signal.h>`                  | Signal handling                                                              |        C89 |
| [`<stdarg.h>`](stdarg.md)     | Support for variadic functions                                               |        C89 |
| [`<stdbool.h>`](stdbool.md)   | Boolean type and related macros                                              |        C99 |
| [`<stddef.h>`](stddef.md)     | Common types and macros such as `size_t`, `ptrdiff_t`, and `offsetof`        |        C89 |
| [`<stdint.h>`](stdint.md)     | Fixed-width and other integer types                                          |        C99 |
| [`<stdio.h>`](stdio.md)       | Input/output and file operations                                             |        C89 |
| [`<stdlib.h>`](stdlib.md)     | Memory allocation, conversions, random numbers, sorting, and other utilities |        C89 |
| [`<string.h>`](string.md)     | String and raw memory manipulation                                           |        C89 |
| `<tgmath.h>`                  | Type-generic mathematical functions                                          |        C99 |
| [`<time.h>`](time.md)         | Date, time, and calendar operations                                          |        C89 |
| `<wchar.h>`                   | Wide-character and wide-string operations                                    |        C99 |
| `<wctype.h>`                  | Classification and conversion of wide characters                             |        C99 |

## Organization

The headers can be grouped broadly by their purpose.

### Input and Output

* `<stdio.h>` — input/output and file handling

### Strings and Characters

* [[string\|<string.h>]] — strings and raw memory
* `<ctype.h>` — character classification and conversion
* `<wchar.h>` — wide characters and strings
* `<wctype.h>` — wide-character classification and conversion

### Memory and Integer Types

* `<stdlib.h>` — dynamic memory and general utilities
* `<stddef.h>` — common types and macros
* `<stdint.h>` — fixed-width integer types
* `<inttypes.h>` — integer formatting and conversion
* `<limits.h>` — integer limits
* `<float.h>` — floating-point limits and properties

### Mathematics

* `<math.h>` — mathematical operations
* `<complex.h>` — complex numbers
* `<tgmath.h>` — type-generic mathematical functions
* `<fenv.h>` — floating-point environment

### Program Control and Error Handling

* `<assert.h>` — assertions
* `<errno.h>` — error reporting
* `<setjmp.h>` — non-local jumps
* `<signal.h>` — signal handling

### Functions and Language Support

* `<stdarg.h>` — variadic functions
* [[stdbool\|<stdbool.h>]] — boolean support
* `<iso646.h>` — alternative operator spellings

### Localization and Time

* `<locale.h>` — locale and localization
* `<time.h>` — date and time