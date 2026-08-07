#include <stdio.h>

int main()
{
    int i;
    for(i = 1; i <= 10; i++)
    {
        // Transfers the control past the statements in loop body just for that single iteration.
        // So in this example number 5 would be skipped and won't be printed.
        if(i == 5)
            continue;
        printf("%d\n", i);
        // *** TRANFERS HERE***
    }

    return 0;
}