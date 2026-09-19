#include <stdio.h>
#define DAYS_IN_A_MONTH 30
#define MONTHS_IN_A_YEAR 12
#define DAYS_IN_A_YEAR (DAYS_IN_A_MONTH * MONTHS_IN_A_YEAR)
// When using expressions that contain operators, you should enclose it
// with parantheses.
// Also the all upper case naming style is a convention and not a requirement.
// More info about #define directive will be provided later in preprocessor section.

int main()
{
    printf("there are %d days in a month.\n", DAYS_IN_A_MONTH);
    printf("there are %d months in a year.\n", MONTHS_IN_A_YEAR);
    printf("there are %d days in a year.\n\n", DAYS_IN_A_YEAR);

    // You can also define constants using the const keyword
    const float pi = 3.14f;
    int radius = 2;
    float area = radius * radius * pi;
    printf("area of a circle with 2cm radius would be %.2fcm^2\n", area);
    return 0;
}