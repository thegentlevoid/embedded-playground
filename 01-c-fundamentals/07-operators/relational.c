#include <stdio.h>

int main()
{
    // These operators always return 0 (false) or 1 (true) as their result.
    int a = 1 < 2;  // less than
    int b = 1 > 2;  // greater than
    int c = 1 <= 2; // less than or equal to
    int d = 1 >= 2; // greater than or equal to
    int e = 1 == 2; // equal too
    int f = 1 != 2; // not equal too

    printf("1 < 2 = %d\n", a);
    printf("1 > 2 = %d\n", b);
    printf("1 <= 2 = %d\n", c);
    printf("1 >= 2 = %d\n", d);
    printf("1 == 2 = %d\n", e);
    printf("1 != 2 = %d\n", f);
    
    return 0;
}