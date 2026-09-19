#include <stdio.h>

#define VERSION 2

#if VERSION == 1
    // Cause the compilation to fail and throws an error.
    #error "This program requires VERSION 2"
#elif VERSION == 2
    // Issues an warning but won't stop the program from compiling.
    // #warning is widely supported by GCC and Clang, but it is not
    // part of older versions of the ISO C standard.
    #warning "Version 2 of this program is deprecated."
#endif

int main()
{
    printf("Hello world!");
    return 0;
}