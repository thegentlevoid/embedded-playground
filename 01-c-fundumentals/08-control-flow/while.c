#include <stdio.h>

int main()
{
    // Loops through the body for as long as the statement is 1 (true).
    printf("While Loop:\n");
    int i = 1;
    while(i <= 10)
    {
        printf("%d\n", i++);
    }

    // With the do statement the loop body is executed once, then the control
    // expression is checked, if it's nonzero then the loop body will be executed again.
    // So in a Do-While loop the loop body is always executed at least once even if the
    // control statement is zero right from the start.
    printf("\nDo-While Loop:\n");
    i = 1;
    do
    {
        printf("%d\n", i++);
    } while (i <= 10);

    return 0;
}