#include <stdio.h>

int main()
{
    int num1 = 22;
    int num2 = 16;
    int *p = &num1; 
    int **ptp = &p;

    printf("num1: %d\n", num1);
    printf("num1 address: %p\n", &num1);
    printf("num2: %d\n", num2);
    printf("num2 address: %p\n", &num2);
    printf("p: %p\n", p);
    printf("ptp: %p\n", ptp);

    // You can modify num through ptp by dereferencing it twice.
    **ptp = 24;
    printf("new num1: %d\n", num1);

    // You can also modify p through ptp to make it point to another variable.
    *ptp = &num2;
    printf("new p: %p\n", p);

    // Pointers to other pointers come in handy when working with things like
    // dynamically allocated memory or linked lists.
}