#include <stdio.h>

int main()
{
    int grade = 3;

    switch(grade)
    {
        case 4:
            printf("Excellent\n");
            break;
        case 3:
            printf("Good\n");
            break;
        case 2:
            printf("Average\n");
            break;
        case 1:
            printf("Poor\n");
            break;
        case 0:
            printf("Failing\n");
            break;
        default:
            printf("Invalid grade\n");
            break;
    }

    // The default case isn't required and if it's not present and grade doesn't match
    // any of the values 0-4 the switch statement simply does nothing.
    // The default isn't required to come last and can be placed anywhere.
    // Duplicate cases aren't allowed.
    // The same set of statements can belong to several cases as it is shown below:
    switch(grade)
    {
        case 4:
        case 3:
        case 2:
        case 1:
            printf("Passing\n");
            break;
        case 0:
            printf("Failing\n");
            break;
        default:
            printf("Invalid grade\n");
            break;
    }

    // The break statement is there to prevent fallthrough.
    // If we don't use break statements, when the first case matches and it's statements
    // are evaluated the control simply falls through to next case and it's label is ignored.
    // You can see it's example below:
    switch(grade)
    {
        case 4: printf("Excellent\n");
        case 3: printf("Good\n");
        case 2: printf("Average\n");
        case 1: printf("Poor\n");
        case 0: printf("Failing\n");
        default: printf("Invalid grade\n");
    }

    /*
    * Output would be:
    * Good
    * Average
    * Poor
    * Failing
    * Invalid grade
    */

    return 0;
}