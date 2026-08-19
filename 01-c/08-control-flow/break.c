#include <stdio.h>

int main()
{
    int i;
    for(i = 1; i <= 10; i++)
    {
        // Transfers the control just past the end of the loop when/if I reaches 5.
        // So numbers 5-10 will not get printed.
        // Can be used to break out of infinite loops on some condition.
        if(i == 5)
            break;
        printf("%d\n", i);
    }

    return 0;
}