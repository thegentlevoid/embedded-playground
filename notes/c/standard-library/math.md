# `<math.h>`

## Overview

The `<math.h>` header provides mathematical functions for floating-point calculations.

The functions primarily operate on `double`. C99 also provides `float` and `long double` variants with `f` and `l` suffixes.

For example:

```c
sqrt(x)     // double
sqrtf(x)    // float
sqrtl(x)    // long double
```

---

## Trigonometric Functions

| Function  | Prototype                           | Description                                                                                            |
| --------- | ----------------------------------- | ------------------------------------------------------------------------------------------------------ |
| `sin()`   | `double sin(double x);`             | Returns the sine of `x` radians.                                                                       |
| `cos()`   | `double cos(double x);`             | Returns the cosine of `x` radians.                                                                     |
| `tan()`   | `double tan(double x);`             | Returns the tangent of `x` radians.                                                                    |
| `asin()`  | `double asin(double x);`            | Returns the arc sine of `x` in radians.                                                                |
| `acos()`  | `double acos(double x);`            | Returns the arc cosine of `x` in radians.                                                              |
| `atan()`  | `double atan(double x);`            | Returns the arc tangent of `x` in radians.                                                             |
| `atan2()` | `double atan2(double y, double x);` | Returns the arc tangent of `y/x`, using the signs of both arguments to determine the correct quadrant. |

---

## Hyperbolic Functions

| Function  | Prototype                 | Description                                    |
| --------- | ------------------------- | ---------------------------------------------- |
| `sinh()`  | `double sinh(double x);`  | Returns the hyperbolic sine of `x`.            |
| `cosh()`  | `double cosh(double x);`  | Returns the hyperbolic cosine of `x`.          |
| `tanh()`  | `double tanh(double x);`  | Returns the hyperbolic tangent of `x`.         |
| `asinh()` | `double asinh(double x);` | Returns the inverse hyperbolic sine of `x`.    |
| `acosh()` | `double acosh(double x);` | Returns the inverse hyperbolic cosine of `x`.  |
| `atanh()` | `double atanh(double x);` | Returns the inverse hyperbolic tangent of `x`. |

---

## Exponential and Logarithmic Functions

| Function  | Prototype                 | Description                                                                   |
| --------- | ------------------------- | ----------------------------------------------------------------------------- |
| `exp()`   | `double exp(double x);`   | Returns `e` raised to the power `x`.                                          |
| `exp2()`  | `double exp2(double x);`  | Returns `2` raised to the power `x`.                                          |
| `expm1()` | `double expm1(double x);` | Returns `eˣ - 1`, with improved accuracy for values of `x` close to zero.     |
| `log()`   | `double log(double x);`   | Returns the natural logarithm of `x`.                                         |
| `log10()` | `double log10(double x);` | Returns the base-10 logarithm of `x`.                                         |
| `log2()`  | `double log2(double x);`  | Returns the base-2 logarithm of `x`.                                          |
| `log1p()` | `double log1p(double x);` | Returns `log(1 + x)`, with improved accuracy for values of `x` close to zero. |

---

## Power and Root Functions

| Function  | Prototype                           | Description                                               |
| --------- | ----------------------------------- | --------------------------------------------------------- |
| `pow()`   | `double pow(double x, double y);`   | Returns `x` raised to the power `y`.                      |
| `sqrt()`  | `double sqrt(double x);`            | Returns the square root of `x`.                           |
| `cbrt()`  | `double cbrt(double x);`            | Returns the cube root of `x`.                             |
| `hypot()` | `double hypot(double x, double y);` | Returns `√(x² + y²)` without undue overflow or underflow. |

---

## Rounding Functions

| Function    | Prototype                          | Description                                                                           |
| ----------- | ---------------------------------- | ------------------------------------------------------------------------------------- |
| `ceil()`    | `double ceil(double x);`           | Rounds `x` toward positive infinity.                                                  |
| `floor()`   | `double floor(double x);`          | Rounds `x` toward negative infinity.                                                  |
| `fabs()`    | `double fabs(double x);`           | Returns the absolute value of `x`.                                                    |
| `fmod()`    | `double fmod(double x, double y);` | Returns the floating-point remainder of `x / y`.                                      |
| `trunc()`   | `double trunc(double x);`          | Rounds `x` toward zero.                                                               |
| `round()`   | `double round(double x);`          | Rounds `x` to the nearest integer, with halfway cases away from zero.                 |
| `lround()`  | `long int lround(double x);`       | Rounds `x` to the nearest `long int`, with halfway cases away from zero.              |
| `llround()` | `long long int llround(double x);` | Rounds `x` to the nearest `long long int`, with halfway cases away from zero.         |
| `rint()`    | `double rint(double x);`           | Rounds `x` according to the current rounding direction.                               |
| `lrint()`   | `long int lrint(double x);`        | Rounds `x` according to the current rounding direction and returns a `long int`.      |
| `llrint()`  | `long long int llrint(double x);`  | Rounds `x` according to the current rounding direction and returns a `long long int`. |

---

## Floating-Point Manipulation

| Function    | Prototype                               | Description                                                        |
| ----------- | --------------------------------------- | ------------------------------------------------------------------ |
| `frexp()`   | `double frexp(double x, int *exp);`     | Decomposes `x` into a normalized fraction and an integer exponent. |
| `ldexp()`   | `double ldexp(double x, int exp);`      | Returns `x × 2ᵉˣᵖ`.                                                |
| `modf()`    | `double modf(double x, double *iptr);`  | Separates `x` into integer and fractional parts.                   |
| `scalbn()`  | `double scalbn(double x, int n);`       | Returns `x × FLT_RADIXⁿ`.                                          |
| `scalbln()` | `double scalbln(double x, long int n);` | Returns `x × FLT_RADIXⁿ`, using a `long int` exponent.             |

---

## Floating-Point Classification

| Function     | Prototype                        | Description                                         |
| ------------ | -------------------------------- | --------------------------------------------------- |
| `isfinite()` | `int isfinite(real-floating x);` | Tests whether `x` is finite.                        |
| `isinf()`    | `int isinf(real-floating x);`    | Tests whether `x` is positive or negative infinity. |
| `isnan()`    | `int isnan(real-floating x);`    | Tests whether `x` is NaN.                           |
| `isnormal()` | `int isnormal(real-floating x);` | Tests whether `x` is a normal floating-point value. |
| `signbit()`  | `int signbit(real-floating x);`  | Tests whether `x` has a negative sign.              |

---

## Floating-Point Comparison

| Function | Prototype                          | Description                                                              |
| -------- | ---------------------------------- | ------------------------------------------------------------------------ |
| `fmax()` | `double fmax(double x, double y);` | Returns the larger of `x` and `y`.                                       |
| `fmin()` | `double fmin(double x, double y);` | Returns the smaller of `x` and `y`.                                      |
| `fdim()` | `double fdim(double x, double y);` | Returns the positive difference between `x` and `y`, or `0` if `x <= y`. |

---

## Error Handling

Many `<math.h>` functions can encounter domain or range errors.

For example:

```c
double result = sqrt(-1.0);
```

The result may be a NaN and the implementation may indicate a domain error through `errno` or floating-point exceptions.

See [[errno|<errno.h>]] and [[fenv|<fenv.h>]] for error and floating-point environment handling.