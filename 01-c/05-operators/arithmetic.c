#include <stdio.h>

int main()
{
    int a = +1;     // unary plus
    int b = -1;     // unary minus
    int c = 1 + 2;  // addition
    int d = 1 - 2;  // subtraction
    int e = 1 * 2;  // multiplication
    int f = 1 / 2;  // division
    int g = 1 % 2;  // remainder

    // The unary + operator does nothing and it’s used primarily to emphasize that a numeric constant is positive.

    // Arithmetic operation allow for type mixing and when it happens the result will be of the broader operand's type.
    // For example when adding an int and float together the result will be of type float.
    printf("Type Mixing:\n");
    printf("1 + 2.0f = %f\n\n", 1 + 2.0f);

    // When doing division on two ints, the / operator “truncates” the result by dropping the fractional part.
    // So 5 / 4 would be 1 not 1.25.
    // The result of an integer division is always truncated towards zero.
    printf("Integer Division:\n");
    printf("5 / 4 = %d\n", 5 / 4);
    printf("-9 / 5 = %d\n\n", -9 / 5);
    
    // The opertaor % requires integer operands otherwise the program won't compile.

    // Using zero as the right operand of either / or % causes undefined behavior.


    // The value of x % y has the same sign as x.
    printf("Remainder Operator's Result Sign:\n");
    printf("5 %% 4 = %d\n", 5 % 4);
    printf("-5 %% 4 = %d\n", -5 % 4);
    printf("5 %% -4 = %d\n\n", 5 % -4);

    // The unary operators are of the highest priority followed by *, / and % operators and lastly the binary operators.
    return 0;
}