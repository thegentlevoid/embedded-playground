#include <stdio.h>

int main()
{
    // Goto is used to transfer control to a specific label
    printf("Hello from the 6th line.\n");
    goto label1;

    printf("This won't get printed.\n");

    // This is how you label some part of your program
    label1:
    printf("Hello from the 13th line\n");

    // Goto can even be used to create loops like bellow
    int i = 1;
    loop1:
    printf("%d\n", i++);
    if(i <= 10)
        goto loop1;

    // Even tho goto can be used to do all this, nowadays it is rarely used.
    return 0;
}