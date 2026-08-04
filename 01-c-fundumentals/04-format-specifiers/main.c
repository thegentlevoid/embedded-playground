#include <stdio.h>

int main()
{
    int age = 22;
    float height = 1.72f;

    // displays age in decimal form
    printf("I'm %d years old.\n", age);

    // displays age in decimal form, using a minimum of 4 characters.
    // since variable age only required 2 character the rest will be replaced by whitespace.
    printf("I'm %4d years old.\n", age);

    // displays age in decimal form, using a minimum of 4 characters.
    // since variable age only required 2 character the rest will be replaced by whitespace.
    // the spaces will be added afterwards (in the right side)
    printf("I'm %-4d years old.\n", age);

    // displays age in decimal form, using a minimum of 4 characters.
    // this specifier uses 0 instead of whitespace to fill the remaining characters.
    printf("I'm %04d years old.\n", age);

    // displays age in decimal form, using a minimum of 4 characters overall and a minimum of 3 digits.
    // in this example since age is only two digits a zero will be added before it to guarantee 3 digits.
    // the rest of the remaining space will be filled with whitespaces.
    printf("I'm %4.3d years old.\n", age);

    // displays height in decimal form, using a minimum of 10 characters overall, with 4 digits after decimal point.
    printf("I'm %10.4f centimeters tall.\n", height);

    // displays height in exponential form, using a minimum 10 characters overall, with 4 digits after the decimal point.
    printf("I'm %10.4e centimeters tall.\n", height);

    // displays age in decimal or exponential form, using a minimum of 10 characters overall.
    // the compiler itself decides between decimal form or exponential form.
    // if the decimal form is reasonably small that will be shown otherwise the exponential from will be shown.
    printf("I'm %10g centimeters tall.\n", height);

    // when you format less numbers after decimal points than what your variable has, the result will be rounded.
    // in this case since height is 1.72 and we only want one digit after decimal point it will be rounded down to 1.7.
    printf("I'm %.1f centimeters tall.\n", height);

    return 0;
}