#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Ternary operator is shorthand for if-else statements.
    // (condition) ? value_if_true : value_if_false;
    // Below are some examples
    int a = 4;
    int b = 10;
    int max = (a > b) ? a : b;
    printf("%d\n", max);

    bool is_online = true;
    printf("%s\n", is_online ? "User is online." : "User is offline.");

    int number = 22;
    printf("%d is %s.", (number % 2 == 0) ? "even" : "odd");

    return 0;
}