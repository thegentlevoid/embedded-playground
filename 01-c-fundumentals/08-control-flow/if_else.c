#include <stdio.h>

int main()
{
    int i = 2;
    
    if(1 < i && i < 3)
        printf("i is within range 1-3\n\n");

    if(i == 1)
        printf("i is 1\n\n");
    else
        printf("i is not 1\n\n");

    if(i == 1)
        printf("i is 1\n\n");
    else if(i == 2)
        printf("i is 2\n\n");
    else
        printf("i is neither 1 nor 2.\n\n");
    
    // If we wanted our if statement to control more than one statement we have to group them together in {}.
    if(i == 2)
    {
        printf("i is not 1.\n");
        printf("i is 2.\n\n");
    }

    return 0;
}