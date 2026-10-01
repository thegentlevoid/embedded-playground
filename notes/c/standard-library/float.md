# `<float.h>`

## Overview

The `<float.h>` header defines macros describing the characteristics and limits of the implementation's floating-point types.

It provides information about:
- precision
- range
- rounding behavior
- representation
- floating-point arithmetic

The values are **implementation-defined** and may differ between systems.

---

## Floating-Point Types

`<float.h>` describes three standard floating-point types:

|Type|Description|
|---|---|
|`float`|Single-precision floating-point type|
|`double`|Double-precision floating-point type|
|`long double`|Extended-precision floating-point type|

The header does **not** define these types. They are built into the C language.

---

# Precision

## `FLT_DIG`

```c
FLT_DIG
```

Number of decimal digits that can be represented without change and then converted back to `float`.

Typical value:

```text
6
```

---

## `DBL_DIG`

```c
DBL_DIG
```

Number of decimal digits reliably represented by `double`.

Typical value:

```text
15
```

---

## `LDBL_DIG`

```c
LDBL_DIG
```

Number of decimal digits reliably represented by `long double`.

Its value is implementation-defined.

---

## `FLT_MANT_DIG`

```c
FLT_MANT_DIG
```

Number of base-`FLT_RADIX` digits in the mantissa/significand of a `float`.

For IEEE 754 binary32:

```text
FLT_MANT_DIG = 24
```

---

## `DBL_MANT_DIG`

```c
DBL_MANT_DIG
```

Number of base-`FLT_RADIX` digits in the mantissa/significand of a `double`.

For IEEE 754 binary64:

```text
DBL_MANT_DIG = 53
```

---

## `LDBL_MANT_DIG`

```c
LDBL_MANT_DIG
```

Number of base-`FLT_RADIX` digits in the mantissa/significand of a `long double`.

Its value depends on the implementation.

---

# Floating-Point Radix

## `FLT_RADIX`

```c
FLT_RADIX
```

The radix, or base, used for floating-point representation.

Typical systems use binary:

```text
FLT_RADIX = 2
```

---

# Exponent Range

These macros describe the range of exponents supported by each floating-point type.

|Macro|Meaning|
|---|---|
|`FLT_MIN_EXP`|Minimum negative exponent for `float`|
|`DBL_MIN_EXP`|Minimum negative exponent for `double`|
|`LDBL_MIN_EXP`|Minimum negative exponent for `long double`|
|`FLT_MAX_EXP`|Maximum positive exponent for `float`|
|`DBL_MAX_EXP`|Maximum positive exponent for `double`|
|`LDBL_MAX_EXP`|Maximum positive exponent for `long double`|

There are also base-10 versions:

|Macro|Meaning|
|---|---|
|`FLT_MIN_10_EXP`|Minimum base-10 exponent for `float`|
|`DBL_MIN_10_EXP`|Minimum base-10 exponent for `double`|
|`LDBL_MIN_10_EXP`|Minimum base-10 exponent for `long double`|
|`FLT_MAX_10_EXP`|Maximum base-10 exponent for `float`|
|`DBL_MAX_10_EXP`|Maximum base-10 exponent for `double`|
|`LDBL_MAX_10_EXP`|Maximum base-10 exponent for `long double`|

For a typical IEEE 754 `float`:

```text
FLT_MIN_10_EXP = -37
FLT_MAX_10_EXP =  38
```

This means its normal range is approximately:

```text
10^-37 ... 10^38
```

---

# Minimum and Maximum Values

## `FLT_MIN`

```c
FLT_MIN
```

Smallest positive **normalized** value representable by `float`.

Typical IEEE 754 value:

```text
1.17549435e-38
```

---

## `DBL_MIN`

```c
DBL_MIN
```

Smallest positive normalized value representable by `double`.

Typical IEEE 754 value:

```text
2.2250738585072014e-308
```

---

## `LDBL_MIN`

```c
LDBL_MIN
```

Smallest positive normalized value representable by `long double`.

---

## `FLT_MAX`

```c
FLT_MAX
```

Largest finite value representable by `float`.

Typical IEEE 754 value:

```text
3.40282347e+38
```

---

## `DBL_MAX`

```c
DBL_MAX
```

Largest finite value representable by `double`.

Typical IEEE 754 value:

```text
1.7976931348623157e+308
```

---

## `LDBL_MAX`

```c
LDBL_MAX
```

Largest finite value representable by `long double`.

---

# Rounding and Precision

## `FLT_EPSILON`

```c
FLT_EPSILON
```

The difference between `1.0` and the smallest representable value greater than `1.0` for `float`.

Typical IEEE 754 value:

```text
1.19209290e-7
```

Example:

```c
#include <stdio.h>
#include <float.h>

int main(void)
{
    printf("FLT_EPSILON = %e\n", FLT_EPSILON);

    return 0;
}
```

---

## `DBL_EPSILON`

```c
DBL_EPSILON
```

The equivalent value for `double`.

Typical IEEE 754 value:

```text
2.2204460492503131e-16
```

---

## `LDBL_EPSILON`

```c
LDBL_EPSILON
```

The equivalent value for `long double`.

---

# Evaluation Method

## `FLT_EVAL_METHOD`

```c
FLT_EVAL_METHOD
```

Specifies the range and precision used when evaluating floating-point expressions.

Possible standard values include:

|Value|Meaning|
|--:|---|
|`-1`|Indeterminable|
|`0`|Evaluate operations and constants to the range and precision of their type|
|`1`|Evaluate `float` and `double` expressions as `double`|
|`2`|Evaluate `float` and `double` expressions as `long double`|

This can matter when intermediate calculations have greater precision than the type of the variables involved.

---

# Rounding Direction

## `FLT_ROUNDS`

```c
FLT_ROUNDS
```

Describes the implementation's floating-point rounding mode.

|Value|Meaning|
|--:|---|
|`-1`|Indeterminable|
|`0`|Toward zero|
|`1`|To nearest|
|`2`|Toward positive infinity|
|`3`|Toward negative infinity|

The value may depend on the implementation and current floating-point environment.

---

# Decimal Precision

The `*_DIG` macros are useful when determining how many decimal digits can safely be represented.

For example:

```c
#include <stdio.h>
#include <float.h>

int main(void)
{
    printf("float:       %d digits\n", FLT_DIG);
    printf("double:      %d digits\n", DBL_DIG);
    printf("long double: %d digits\n", LDBL_DIG);

    return 0;
}
```

A typical implementation might produce:

```text
float:       6 digits
double:      15 digits
long double: 18 digits
```

The exact values depend on the implementation.

---

# Common IEEE 754 Values

A common embedded configuration is IEEE 754 binary32 for `float` and binary64 for `double`.

|Property|`float`|`double`|
|---|--:|--:|
|`*_DIG`|`6`|`15`|
|`*_MANT_DIG`|`24`|`53`|
|`*_MIN`|`1.17549435e-38`|`2.2250738585072014e-308`|
|`*_MAX`|`3.40282347e+38`|`1.7976931348623157e+308`|
|`*_EPSILON`|`1.19209290e-7`|`2.2204460492503131e-16`|
|`*_MIN_10_EXP`|`-37`|`-307`|
|`*_MAX_10_EXP`|`38`|`308`|

These are **typical IEEE 754 values**, not values guaranteed by the C standard.

---

# Embedded Considerations

Floating-point characteristics can vary significantly between embedded targets.

For example, an MCU may use:

```text
float       → 32-bit IEEE 754
double      → 64-bit IEEE 754
```

while some embedded toolchains may configure `double` differently.

Always check the implementation rather than assuming the representation:

```c
#include <float.h>
#include <stdio.h>

int main(void)
{
    printf("float size: %zu\n", sizeof(float));
    printf("double size: %zu\n", sizeof(double));

    printf("FLT_MAX: %e\n", FLT_MAX);
    printf("DBL_MAX: %e\n", DBL_MAX);

    return 0;
}
```

For embedded work, these macros are useful when determining whether a numeric algorithm will fit within the precision and range available on a particular MCU.