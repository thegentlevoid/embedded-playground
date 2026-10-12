# C Format Specifiers

Format specifiers are used with `...printf()` and `...scanf()` functions to tell C what type of value to print or read.

## `...printf()`

  <div style="display: flex; gap: 4px; font-size: 1.5em; align-items: center;">
    <span style="box-sizing: border-box; width: 50px; text-align: center; border: 2px solid #569CD6; padding: 6px 0; border-radius: 6px;">%</span>
    <span style="box-sizing: border-box; width: 50px; text-align: center; border: 2px solid #C586C0; padding: 6px 0; border-radius: 6px;">#0</span>
    <span style="box-sizing: border-box; width: 50px; text-align: center; border: 2px solid #D7BA7D; padding: 6px 0; border-radius: 6px;">12</span>
    <span style="box-sizing: border-box; width: 50px; text-align: center; border: 2px solid #4EC9B0; padding: 6px 0; border-radius: 6px;">.5</span>
    <span style="box-sizing: border-box; width: 50px; text-align: center; border: 2px solid #CE9178; padding: 6px 0; border-radius: 6px;">L</span>
    <span style="box-sizing: border-box; width: 50px; text-align: center; border: 2px solid #569CD6; padding: 6px 0; border-radius: 6px;">g</span>
  </div>
  
### 1. %:
Marks the beginning of format specifier strings.

---

### 2. Flags *(optional; more than one permitted)*:
the flags affect the way the outputs are displayed.

|   Flag    | Meaning                                                                                                                                                                                                              |
| :-------: | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|    `-`    | Left-justify within field. (The default is right justification.)                                                                                                                                                     |
|    `+`    | Numbers produced by signed conversions always begin with `+` or `-`. (Normally, only negative numbers are preceded by a sign.)                                                                                       |
| *`space`* | Nonnegative numbers produced by signed conversions are preceded by a space. (The `+` flag overrides the space flag.)                                                                                                 |
|    `#`    | Octal numbers begin with `0`, nonzero hexadecimal numbers with `0x` or `0X`. Floating-point numbers always have a decimal point. Trailing zeros aren’t removed from numbers printed with the `g` or `G` conversions. |
|    `0`    | Numbers are padded with leading zeros up to the field width. The 0 flag is ignored if the conversion is `d`, `i`, `o`, `u`, `x`, or `X` and a precision is specified. (The `-` flag overrides the `0` flag.)         |

---

### 3. Minimum field length *(optional)*:
An item that’s too small to occupy this number of characters will be padded. (By default, spaces are added to the left of the item, thus right-justifying it within the field.) An item that’s too large for the field width will still be displayed in its entirety. The field width is either an integer or the character \*. If \* is present, the field width is obtained from the next argument. If this argument is negative, it’s treated as a positive number preceded by a `-` flag.

---

### 4. Precision *(optional)*:
The meaning of the precision depends on the conversion:
`d`, `i`, `o`, `u`, `x`, `X`: minimum number of digits (leading zeros are added if the number has fewer digits).
`a`, `A`, `e`, `E`, `f`, `F`: number of digits after the decimal point.
`g`, `G`: number of significant digits.
`s`: maximum number of bytes.

The precision is a period (.) followed by an integer or the character \*. If \* is present, the precision is obtained from the next argument. (If this argument is negative, the effect is the same as not specifying a precision.) If only the period is present, the precision is zero.

---

### 5. Length modifier *(optional)*:
The presence of a length modifier indicates that the item to be displayed has a type that’s longer or shorter than is normal for a particular conversion specification.

| Length Modifier | Conversion Specifiers                  | Meaning                                   |
| --------------- | -------------------------------------- | ----------------------------------------- |
| `hh`            | `d`, `i`, `o`, `u`, `x`, `X`           | `signed char`, `unsigned char`            |
| `hh`            | `n`                                    | `signed char *`                           |
| `h`             | `d`, `i`, `o`, `u`, `x`, `X`           | `short int`, `unsigned short int`         |
| `h`             | `n`                                    | `short int *`                             |
| `l`             | `d`, `i`, `o`, `u`, `x`, `X`           | `long int`, `unsigned lont int`           |
| `l`             | `n`                                    | `long int *`                              |
| `l`             | `c`                                    | `wint_t`                                  |
| `l`             | `s`                                    | `wchar_t *`                               |
| `l`             | `a`, `A`, `e`, `E`, `f`, `F`, `g`, `G` | no effect                                 |
| `ll`            | `d`, `i`, `o`, `u`, `x`, `X`           | `long long int`, `unsigned long long int` |
| `ll`            | `n`                                    | `long long int *`                         |
| `j`             | `d`, `i`, `o`, `u`, `x`, `X`           | `intmax_t`, `uintmax_t`                   |
| `j`             | `n`                                    | `intmax_t *`                              |
| `z`             | `d`, `i`, `o`, `u`, `x`, `X`           | `size_t`                                  |
| `z`             | `n`                                    | `size_t *`                                |
| `t`             | `d`, `i`, `o`, `u`, `x`, `X`           | `ptrdiff_t`                               |
| `t`             | `n`                                    | `ptrdiff_t *`                             |
| `L`             | `a`, `A`, `e`, `E`, `f`, `F`, `g`, `G` | `long double`                             |

---

### 6. Conversion specifier:
The conversion specifier must be one of the characters listed below.

| Conversion Specifier | Meaning                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| -------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `d`, `i`             | Converts an `int` value to decimal form.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| `o`, `u`, `x`, `X`   | Converts an `unsigned int` value to base 8 (`o`), base 10 (`u`), or base 16 (`x`, `X`). `x` displays the hexadecimal digits a–f in lower case; `X` displays them in upper case.                                                                                                                                                                                                                                                                                                                                                                                                  |
| `f,` `F`             | Converts a `double` value to decimal form, putting the decimal point in the correct position. If no precision is specified, displays six digits after the decimal point. `f` displays special values in lower-case (`inf`, `nan`) while `F` displays them as upper-case (`INF`, `NAN`).                                                                                                                                                                                                                                                                                          |
| `e`, `E`             | Converts a `double` value to scientific notation. If no precision is specified, displays six digits after the decimal point. If `e` is chosen, the exponent is preceded by the letter *e*; if `E` is chosen, the exponent is preceded by *E*.                                                                                                                                                                                                                                                                                                                                    |
| `g`, `G`             | `g` converts a `double` value to either `f` form or `e` form. `e` form is selected if the number’s exponent is less than *–4* or greater than or equal to the precision. Trailing zeros are not displayed (unless the `#` flag is used); a decimal point appears only when followed by a digit. `G` chooses between `F` and `E` forms.                                                                                                                                                                                                                                           |
| `a`, `A`             | Converts a `double` value to hexadecimal scientific notation using the form [-]0xh.hhhhp±d, where [-] is an optional minus sign, the h’s rep resent hex digits, ± is either a plus or minus sign, and d is the exponent. d is a decimal number that represents a power of 2. If no precision is speci fied, enough digits are displayed after the decimal point to represent the exact value of the number (if possible). a displays the hex digits a–f in lower case; A displays them in upper case. The choice of `a` or `A` also affects the case of the letters *x* and *p*. |
| `c`                  | Displays an `int` value as an unsigned character.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| `s`                  | Writes the characters pointed to by the argument. Stops writing when the number of bytes specified by the precision (if present) is reached or a null character is encountered.                                                                                                                                                                                                                                                                                                                                                                                                  |
| `p`                  | Converts a `void *` value to printable form.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| `n`                  | The corresponding argument must point to an object of type `int`. Stores in this object the number of characters written so far by this call of …printf; produces no output.                                                                                                                                                                                                                                                                                                                                                                                                     |
| `%`                  | Writes the character %.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |

> [!Note]+
> Notice that `f`, `F`, `e`, `E`, `g`, `G`, `a`, and `A` are all designed to write `double` values. However, they work fine with `float` values as well; thanks to the default argument promotions, `float` arguments are converted automatically to `double` when passed to a function with a variable number of arguments. Similarly, a character passed to …printf is converted automatically to `int`, so the c conversion works properly.

---

## `...scanf()`
Conversion specifications for `…scanf` functions are actually a little simpler than those for `…printf` functions. A `…scanf` conversion specification consists of the character `%` followed by the items listed below:

### 1. \* *(optional)*:
The presence of \* signifies assignment suppression; An input item is read but not assigned to an object. Items matched using * aren't included in the count that `…scanf` returns.

---

### 2. Maximum field width *(optional)*:
The maximum field width limits the number of characters in an input item; conversion of the item ends if this number is reached. White-space characters skipped at the beginning of a conversion don’t count.

---

### 3. Length modifier *(optional)*:
The presence of a length modifier indicates that the object in which the input item will be stored has a type that’s longer or shorter than is normal for a particular conversion specification.

| Length Modifier | Conversion Specifiers                  | Meaning                                       |
| --------------- | -------------------------------------- | --------------------------------------------- |
| `hh`            | `d`, `i`, `o`, `u`, `x`, `X`, `n`      | `signed char *`, `unsigned char *`            |
| `h`             | `d`, `i`, `o`, `u`, `x`, `X`, `n`      | `short int *`, `unsigned short int *`         |
| `l`             | `d`, `i`, `o`, `u`, `x`, `X`, `n`      | `long int *`, `unsigned lont int *`           |
| `l`             | `a`, `A`, `e`, `E`, `f`, `F`, `g`, `G` | `double *`,                                   |
| `l`             | `c`, `s`, `[`                          | `wchar_t *`                                   |
| `ll`            | `d`, `i`, `o`, `u`, `x`, `X`, `n`      | `long long int *`, `unsigned long long int *` |
| `j`             | `d`, `i`, `o`, `u`, `x`, `X`, `n`      | `intmax_t *`, `uintmax_t *`                   |
| `z`             | `d`, `i`, `o`, `u`, `x`, `X`, `n`      | `size_t *`                                    |
| `t`             | `d`, `i`, `o`, `u`, `x`, `X`, `n`      | `ptrdiff_t *`                                 |
| `L`             | `a`, `A`, `e`, `E`, `f`, `F`, `g`, `G` | `long double *`                               |

---

### 4. Conversion specifier:
The conversion specifier must be one of the characters listed below.

| Conversion Specifier                   | Meaning                                                                                                                                                                                                                                                                                     |
| -------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `d`                                    | Matches a decimal integer; the corresponding argument is assumed to have type `int *`.                                                                                                                                                                                                      |
| `i`                                    | Matches an integer; the corresponding argument is assumed to have type `int *`. The integer is assumed to be in base 10 unless it begins with `0` (indicating octal) or with `0x` or `0X` (hexadecimal).                                                                                    |
| `o`                                    | Matches an octal integer; the corresponding argument is assumed to have type `unsigned int *`.                                                                                                                                                                                              |
| `u`                                    | Matches a decimal integer; the corresponding argument is assumed to have type `unsigned int *`.                                                                                                                                                                                             |
| `x`, `X`                               | Matches a hexadecimal integer; the corresponding argument is assumed to have type `unsigned int *`.                                                                                                                                                                                         |
| `a`, `A`, `e`, `E`, `f`, `F`, `g`, `G` | Matches a floating-point number; the corresponding argument is assumed to have type `float *`. In C99, the number can be *infinity* or *NaN*.                                                                                                                                               |
| `c`                                    | Matches *n* characters, where *n* is the maximum field width, or one character if no field width is specified. The corresponding argument is assumed to be a pointer to a character array (or a character object, if no field width is specified). Doesn’t add a null character at the end. |
| `s`                                    | Matches a sequence of non-white-space characters, then adds a null character at the end. The corresponding argument is assumed to be a pointer to a character array.                                                                                                                        |
| `[`                                    | Matches a nonempty sequence of characters from a scanset, then adds a null character at the end. The corresponding argument is assumed to be a pointer to a character array.                                                                                                                |
| `p`                                    | Matches a pointer value in the form that `…printf` would have written it. The corresponding argument is assumed to be a pointer to a `void *` object.                                                                                                                                       |
| `n`                                    | The corresponding argument must point to an object of type `int`. Stores in this object the number of characters read so far by this call of `…scanf`. No input is consumed and the return value of `…scanf` isn’t affected.                                                                |
| `%`                                    | Matches the character `%.`                                                                                                                                                                                                                                                                  |

> [!note]+
> The `[` specifier is a more complicated and flexible version of the `s` specifier where you can actually specify which character you want it to match with.
> It's complete form would be `%[set]` or `%[^set]`, where *set* can be any set of characters.
> For example `%[abc]` would read consecutive characters that are `a`, `b`, or `c`, stopping at the first character that isn't in the set.
> `%[^set]` is called a negated set; it would read consecutive characters that are NOT in the set.
> If `]` is one of the characters you want to match it should appear right after the opening `[` or after the `^` in negated sets.
> You can also define ranges in sets like `%[0-9]`, `%[a-z]` and `%[A-Z]`, ranges can also be combined like `%[a-zA-z]`.
