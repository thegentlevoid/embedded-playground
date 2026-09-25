// There is not much to discuss about the #include directive other than it's two forms.
// The include directive is mainly used in the two forms below:
// 1. `#include <>`
// 2. `#include ""`

// The first form is used for header files that belong to C's own library
// while the second form is used for all the other headers including our own.

// The difference is in how the compiler located the header files.
// The first form searches the directory in which the system header files reside.
// The second form searches the current directory, then searches where the system
// header files reside.

// While it is possible to specify drive and path information inside include directives,
// it is not recommended because such information makes it difficult to compile a program
// when it is transfered to a different machine.

// #include "d:utils.h"                 /* NOT RECOMMENDED */
// #include "\cprogs\include\utils.h"   /* NOT RECOMMENDED */
// #include "d:\cprogs\include\utils.h" /* NOT RECOMMENDED */

// MORE ON HEADER FILES ON A LATER SECTION OR NOTE!

#include <stdio.h>

int main()
{
    printf("stdio.h included!");
    return 0;
}