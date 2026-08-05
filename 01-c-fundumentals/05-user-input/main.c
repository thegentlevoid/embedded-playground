#include <stdio.h>

int main()
{
    // there are some quirky stuff with scanf when trying to read char inputs.
    // I'll explain those in the types section or just reorder this to come after types later.
    int age = 0;
    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("User's age is %d", age);
    return 0;
}