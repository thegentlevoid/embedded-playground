#include <stdio.h>

float average(float a, float b)
{
    return (a + b) / 2.0f;
}

int main()
{
    float num1 = 22.0f;
    float num2 = 43.0f;
    float avg = average(num1, num2);
    printf("The average of %.1f and %.1f is %.1f\n", num1, num2, avg);

    return 0;
}