#include <stdio.h>

// A simple function to calculate a to the power of b
int pwr(int a, int b)
{
    int res = 1;
    for(int i = 0; i < b; i++)
    {
        res *= a;
    }

    return res;
}

// Here we made a function to do some mathematical procedures on two integers, a and b.
// Since the mathematical operation is up to the user to decide we have to take a pointer
// to the function that does the operation.
// Below you can see `int (*math_stuff)(int, int)`
// This means math_stuff is a pointer to a function that returns an int and takes two
// arguements of type int.
// Using `int math_stuff(int, int)` is also allowed.
// Inside the function body you can call the function math_stuff points by:
// 1. do `(*math_stuff)(a, b)`
// 2. do `math_stuff(a, b)`

int do_some_math_stuff(int (*math_stuff)(int, int), int a, int b)
// int do_some_math_stuff(int math_stuff(int, int), int a, int b)
{
    return (*math_stuff)(a, b);
    // return math_stuff(a, b);
}

int main()
{
    int a = 2;
    int b = 6;

    printf("pwr: %d\n", pwr(a, b));
    printf("do_some_math_stuff: %d\n", do_some_math_stuff(pwr, a, b));

    // Similar to arrays where if a is the name of an array, then a[i] represents one
    // element of the array, while a by itself serves as a pointer to the array, here also
    // if f is the name of a function C treats f(x) as a call of the function but f by itself
    // as a pointer to the function.
    // Thats why we can simply pass `pwr` where `do_some_math_stuff` requires a pointer instead of
    // passing `&pwr`.
    return 0;
}