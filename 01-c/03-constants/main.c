#include <stdio.h>
#define DAYS_IN_A_MONTH 30
#define MONTHS_IN_A_YEAR 12
#define DAYS_IN_A_YEAR (DAYS_IN_A_MONTH * MONTHS_IN_A_YEAR)
// When using expressions that contain operators, you should enclose it
// with parantheses.
// Also the all upper case naming style is a convention and not a requirement.

int main()
{
    printf("there are %d days in a month.\n", DAYS_IN_A_MONTH);
    printf("there are %d months in a year.\n", MONTHS_IN_A_YEAR);
    printf("there are %d days in a year.\n", DAYS_IN_A_YEAR);
    return 0;
}