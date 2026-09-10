# C Format Specifiers

Format specifiers are used with functions such as `printf()` and `scanf()` to tell C what type of value to print or read.

## `printf()`

|Specifier|Type|
|---|---|
|`%d` / `%i`|`int`|
|`%u`|`unsigned int`|
|`%hd`|`short`|
|`%hu`|`unsigned short`|
|`%ld`|`long`|
|`%lu`|`unsigned long`|
|`%lld`|`long long`|
|`%llu`|`unsigned long long`|
|`%f`|`float` / `double`|
|`%lf`|`double`|
|`%Lf`|`long double`|
|`%e`|scientific notation|
|`%g`|shorter form of `%f` or `%e`|
|`%c`|`char`|
|`%s`|string (`char *`)|
|`%p`|pointer|
|`%%`|`%` character|

> **Note:** In `printf()`, `float` is automatically promoted to `double`. `%f` is the conventional specifier for floating-point values. `%lf` is also accepted for `double`.

### Other numeric formats

```c
printf("%e\n", 1234.5678);   // 1.234568e+03
printf("%g\n", 1234.5678);   // 1234.57
printf("%x\n", 255);         // ff
printf("%X\n", 255);         // FF
printf("%o\n", 255);         // 377
```

- `%e` — scientific notation
- `%g` — automatically chooses a shorter `%f` or `%e` representation
- `%x` — hexadecimal, lowercase
- `%X` — hexadecimal, uppercase
- `%o` — octal

---

## `scanf()`

|Specifier|Type|
|---|---|
|`%d`|`int *`|
|`%u`|`unsigned int *`|
|`%hd`|`short *`|
|`%hu`|`unsigned short *`|
|`%ld`|`long *`|
|`%lu`|`unsigned long *`|
|`%lld`|`long long *`|
|`%llu`|`unsigned long long *`|
|`%f`|`float *`|
|`%lf`|`double *`|
|`%Lf`|`long double *`|
|`%c`|`char *`|
|`%s`|`char *`|

---

## Length Modifiers

|Modifier|Meaning|
|---|---|
|`hh`|`char`-sized integer|
|`h`|`short`|
|`l`|`long`|
|`ll`|`long long`|
|`L`|`long double`|

---

## Width & Precision

### Field width

```c
printf("%5d\n", 42);        //    42
printf("%-5d\n", 42);       // 42
printf("%05d\n", 42);       // 00042
```

### Floating-point precision

```c
printf("%.2f\n", 3.14159);   // 3.14
printf("%.4f\n", 3.14159);   // 3.1416
printf("%.0f\n", 3.14159);   // 3
```

### Width + precision

```c
printf("%8.2f\n", 3.14159);  //     3.14
printf("%-8.2f\n", 3.14159); // 3.14
printf("%08.2f\n", 3.14159); // 00003.14
```