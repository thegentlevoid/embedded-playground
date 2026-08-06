#include <stdio.h>

int main()
{
    // ASSIGNMENT OPERATOR
    int i = 1;
    // Operator = assigns the value 1 to variable i
    // Assignment operators can be chained, like i = j = k = 1
    // Assignment operators are evaluated from the right.
    // so something like i = j = k = 1 would be equivalent to i = (j = (k = 1))

    // When assigning i = j, if j's type is different from i it will be converted.
    int j = 2.0f;
    float k = 2;
    printf("j is %d\n", j);
    printf("k is %f\n\n", k);

    // Becareful when chain assigning variables of different types
    k = j = 22.2f;
    printf("j is %d\n", j); // 22.2f would be converted to 22 before being assigned to j
    printf("k is %f\n\n", k); // and since j is now 22, it will be converted to 22.0f before being assigned to k


    // COMPOUND ASSINGMENT OPERATORS
    i = 45;
    i -= 2; // means i = i - 2
    i += 2; // means i = i + 2
    i *= 2; // means i = i * 2
    i /= 2; // means i = i / 2
    i %= 2; // means i = i % 2

    // INCREMENT AND DECREMENT OPERATORS
    i = 1;
    i++; // is equivalent to (i = i + 1) or (i += 1)
    i--; // is equivalent to (i = i - 1) or (i -= 1)

    // Prefixing or Postfixing increment and decrement operators can produce different results.
    i = 1;
    printf("i is %d\n", ++i);   /* prints "i is 2" */
    printf("i is %d\n", i);     /* prints "i is 2" */

    i = 1;
    printf("i is %d\n", i++);   /* prints "i is 1" */
    printf("i is %d\n", i);     /* prints "i is 2" */

    i = 1;
    printf("i is %d\n", --i);   /* prints "i is 0" */
    printf("i is %d\n", i);     /* prints "i is 0" */
    
    i = 1;
    printf("i is %d\n", i--);   /* prints "i is 1" */
    printf("i is %d\n", i);     /* prints "i is 0" */

    return 0;
}