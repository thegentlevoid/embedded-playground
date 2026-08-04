#include <stdio.h>

int main()
{
    int age = 22;
    float height = 1.72f;

    printf("I'm %d years old.\n", age); // prints the variable normally.
    printf("I'm %4d years old.\n", age); // fixes width to 4 characters.
    printf("I'm %-4d years old.\n", age); // forces the blankspaces to be on the right side.
    printf("I'm %04d years old.\n", age); // replaces the blankspaces with zeroes.
    printf("I'm %.1f centimeters tall.", height); // sets the floating point precision to one digit after decimal.
    return 0;
}