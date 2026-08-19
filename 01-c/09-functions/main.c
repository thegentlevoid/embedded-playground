#include <stdio.h>

float average(float a, float b)
{
    return (a + b) / 2.0f;
}

// This is called a function prototype
// If you want to define a function after the "main" function you must define it's prototype first.
float average2(float a, float b);

int main()
{
    float num1 = 22.0f;
    float num2 = 43.0f;
    float avg = average(num1, num2);
    float avg2 = average2(num1, num2);
    printf("The average of %.1f and %.1f is %.1f\n", num1, num2, avg);
    printf("The average2 of %.1f and %.1f is %.1f\n", num1, num2, avg);

    return 0;
}

float average2(float a, float b)
{
    return (a + b) / 2.0f;
}