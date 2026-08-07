#include <stdio.h>

int main()
{
    int a = !1;     // logical negation
    int b = 1 && 2; // logical and
    int c = 1 || 2; // logical or

    printf("!1 = %d\n", a);
    printf("1 && 2 = %d\n", b);
    printf("1 || 2 = %d\n", c);
    
    return 0;
}