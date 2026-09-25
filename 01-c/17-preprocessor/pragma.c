#include <stdio.h>

// The #pragma directive gives compiler specific instructions.
// Not surprisingly, the set of commands that can appear in #pragma directives
// is different for each compiler; you’ll have to consult the documentation for your
// compiler to see which commands it allows and what those commands do.

// One example is `#pragma once` which is placed at the top of header files,
// and tells the compiler to process that header file only once per compilation
// just like the traditional #ifndef header guards.

// Or for example `#pragma message "msg"` which produces a message like below:
// `pragma.c:13:9: note: '#pragma message: msg'`
#pragma message "Compiling pragma.c!"

// Here's the gcc pragma documentation: https://gcc.gnu.org/onlinedocs/gcc/Pragmas.html

int main()
{
    printf("Hello world!");
    return 0;
}