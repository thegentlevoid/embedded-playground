#include <stdio.h>

// enum name { data };
enum Day
{
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
};

// typedef enum { data } name;
typedef enum
{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
} Month;

// Enum values start from 0 and increment by one by default.
// But you can also manually assign values to your enum keys.
typedef enum
{
    SUCCESS = 1,
    FAILURE = 2
} Status;

int main()
{
    enum Day today = WEDNESDAY; // If you defined your enum with the first syntax this is how you use it.
    Month this_month = AUGUST; // If you defined you enum with typedef this is how you use it.
    Status status = SUCCESS;

    printf("Day of the week: %d\n", today);
    printf("Month: %d\n", this_month);
    printf("Status: %d\n", status);

    return 0;
}