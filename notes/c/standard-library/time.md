# `<time.h>`

## Overview

The `<time.h>` header provides types and functions for working with **calendar time**, **processor time**, and **time conversions**.

| Function                    | Prototype                                                                                                               | Description                                        |
| --------------------------- | ----------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------- |
| [`time()`](#time)           | `time_t time(time_t *timer);`                                                                                           | Gets the current calendar time.                    |
| [`localtime()`](#localtime) | `struct tm *localtime(const time_t *timer);`                                                                            | Converts `time_t` to local broken-down time.       |
| [`gmtime()`](#gmtime)       | `struct tm *gmtime(const time_t *timer);`                                                                               | Converts `time_t` to UTC broken-down time.         |
| [`mktime()`](#mktime)       | `time_t mktime(struct tm *timeptr);`                                                                                    | Converts local broken-down time to `time_t`.       |
| [`asctime()`](#asctime)     | `char *asctime(const struct tm *timeptr);`                                                                              | Converts `struct tm` to fixed-format text.         |
| [`ctime()`](#ctime)         | `char *ctime(const time_t *timer);`                                                                                     | Converts `time_t` to fixed-format local time text. |
| [`strftime()`](#strftime)   | `size_t strftime(char * restrict s, size_t maxsize, const char * restrict format, const struct tm * restrict timeptr);` | Formats broken-down time into a string.            |
| [`clock()`](#clock)         | `clock_t clock(void);`                                                                                                  | Returns processor time used by the program.        |

---

## Types

### `time_t`

`time_t` is an arithmetic type used to represent calendar time.

The exact representation is implementation-defined.

```c
time_t current = time(NULL);
```

The value returned by `time()` can be converted into a human-readable `struct tm` using functions such as `localtime()` and `gmtime()`.

---

### `clock_t`

`clock_t` is an arithmetic type used to represent processor time.

It is returned by `clock()` and can be converted to seconds using `CLOCKS_PER_SEC`.

```c
clock_t start = clock();

/* code to measure */

clock_t end = clock();

double seconds =
    (double)(end - start) / CLOCKS_PER_SEC;
```

---

### `struct tm`

`struct tm` represents a broken-down calendar time.

```c
struct tm
{
    int tm_sec;   /* seconds after the minute: 0–60 */
    int tm_min;   /* minutes after the hour: 0–59 */
    int tm_hour;  /* hours since midnight: 0–23 */
    int tm_mday;  /* day of the month: 1–31 */
    int tm_mon;   /* months since January: 0–11 */
    int tm_year;  /* years since 1900 */
    int tm_wday;  /* days since Sunday: 0–6 */
    int tm_yday;  /* days since January 1: 0–365 */
    int tm_isdst; /* daylight-saving-time flag */
};
```

For example:

```c
struct tm *local = localtime(&current);

printf("%d/%d/%d\n",
       local->tm_mday,
       local->tm_mon + 1,
       local->tm_year + 1900);
```

---

## Functions
### `time()`

```c
time_t time(time_t *timer);
```

Returns the current calendar time.

If `timer` is not `NULL`, the result is also stored through the pointer.

```c
time_t current = time(NULL);
```

Returns `(time_t)-1` if the calendar time is unavailable.

---

### `localtime()`

```c
struct tm *localtime(const time_t *timer);
```

Converts calendar time to local broken-down time.

```c
time_t current = time(NULL);
struct tm *local = localtime(&current);
```

Returns a pointer to a `struct tm`, or `NULL` if the conversion cannot be performed.

---

### `gmtime()`

```c
struct tm *gmtime(const time_t *timer);
```

Converts calendar time to UTC broken-down time.

```c
time_t current = time(NULL);
struct tm *utc = gmtime(&current);
```

Returns a pointer to a `struct tm`, or `NULL` if the conversion cannot be performed.

---

### `mktime()`

```c
time_t mktime(struct tm *timeptr);
```

Converts a broken-down **local time** in `struct tm` into `time_t`.

```c
struct tm date = {0};

date.tm_year = 2026 - 1900;
date.tm_mon  = 9;
date.tm_mday = 1;

time_t timestamp = mktime(&date);
```

The function may also normalize the fields of the `struct tm`.

Returns `(time_t)-1` if the conversion cannot be represented.

---

### `asctime()`

```c
char *asctime(const struct tm *timeptr);
```

Converts a `struct tm` into a fixed-format text representation.

```c
time_t current = time(NULL);
struct tm *local = localtime(&current);

printf("%s", asctime(local));
```

The returned string has the form:

```text
Www Mmm dd hh:mm:ss yyyy\n
```

`asctime()` provides limited formatting flexibility. Use `strftime()` when a specific format is required.

---

### `ctime()`

```c
char *ctime(const time_t *timer);
```

Converts a `time_t` value into the same fixed-format representation produced by `asctime(localtime(...))`.

```c
time_t current = time(NULL);

printf("%s", ctime(&current));
```

---

### `strftime()`

```c
size_t strftime(
    char * restrict s,
    size_t maxsize,
    const char * restrict format,
    const struct tm * restrict timeptr
);
```

Formats a `struct tm` into a string according to a format string.

```c
#include <stdio.h>
#include <time.h>

int main(void)
{
    char buffer[64];
    time_t current = time(NULL);
    struct tm *local = localtime(&current);

    strftime(buffer, sizeof(buffer),
             "%Y-%m-%d %H:%M:%S",
             local);

    printf("%s\n", buffer);

    return 0;
}
```

Returns the number of characters written, excluding the terminating `'\0'`, or `0` if the resulting string does not fit in the buffer.

| Specifier | Meaning                               | Example                    |
| --------- | ------------------------------------- | -------------------------- |
| `%a`      | Abbreviated weekday name              | `Sun`                      |
| `%A`      | Full weekday name                     | `Sunday`                   |
| `%b`      | Abbreviated month name                | `Jan`                      |
| `%B`      | Full month name                       | `January`                  |
| `%c`      | Locale's date and time representation | `Sun Jan 12 15:30:45 2026` |
| `%d`      | Day of month, zero-padded             | `01`–`31`                  |
| `%H`      | Hour, 24-hour clock                   | `00`–`23`                  |
| `%I`      | Hour, 12-hour clock                   | `01`–`12`                  |
| `%j`      | Day of year, zero-padded              | `001`–`366`                |
| `%m`      | Month number                          | `01`–`12`                  |
| `%M`      | Minute                                | `00`–`59`                  |
| `%p`      | Locale's AM/PM designation            | `AM` / `PM`                |
| `%S`      | Seconds                               | `00`–`60`                  |
| `%U`      | Week number, Sunday as first day      | `00`–`53`                  |
| `%W`      | Week number, Monday as first day      | `00`–`53`                  |
| `%x`      | Locale's date representation          | `01/12/26`                 |
| `%X`      | Locale's time representation          | `15:30:45`                 |
| `%y`      | Year without century                  | `26`                       |
| `%Y`      | Year with century                     | `2026`                     |
| `%Z`      | Time-zone name or abbreviation        | `UTC`                      |

---

### `clock()`

```c
clock_t clock(void);
```

Returns the amount of processor time used by the program.

```c
clock_t start = clock();

/* code to measure */

clock_t end = clock();

double elapsed =
    (double)(end - start) / CLOCKS_PER_SEC;
```

Returns `(clock_t)-1` if the processor time is unavailable.

`clock()` measures **processor time**, not necessarily wall-clock elapsed time.
