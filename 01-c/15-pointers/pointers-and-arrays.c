#include <stdio.h>

int main()
{
    // First we make an array and make some pointers, point to it's elements.
    int a[10] = { 11, 58, 36, 42, 73, 17, 29, 99, 88, 13 };
    int *p1 = &a[0];
    int *p2 = &a[4];
    int i = 0;

    // We can now access a[0] through p1
    *p1 = 5; // a[0] is now 5

    // We can perform pointer arithmetics on a pointer that points to an element of an array.
    // C supports three and only three types of pointer arithmetics:
    // 1. Adding an integer to a pointer.
    p1 += 4; // p1 now points to a[4]

    // 2. Subtracting an integer from a pointer.
    p1 -= 3; // p1 now points to a[1]

    // 3. Subtracting one pointer from another.
    i = p2 - p1; // i = 3
    i = p1 - p2; // i = -3

    // When adding and subtracting integers from pointers to array elements, we might move
    // out of the array boundaries like a[-1] or a[10]
    // Dereferencing those pointers will result in undefined behaviour.
    // Also subtracting one pointer from another won't produce another pointer, but the result is
    // the distance of elements from each other.
    // Performing pointer arithmetic on a pointer that doesn't point to an array element causes
    // undefined behaviour.
    // The effect of subtracting one pointer from another is undefined unless both point to
    // elements of the same array.
    // You can also use relational and equality operators on two pointers pointing to an element
    // within the same array.

    int sum = 0;
    for(int *p = &a[0]; p < &a[10]; p++)
    {
        sum += *p;
    }

    // While the array elements extent from a[0] to a[9] using &a[10] here is safe because
    // the loop doesn't attempt to examine it's value.

    // You can also combine * and ++/-- operators;
    *p1++ = 10; // Now a[1] stores 10 and p1 moves forward by one, pointing to a[2]

    // The array name itself can be used as a pointer to it's first element.
    *a = 7; // a[0] = 7;
    *(a+1) = 11; // a[1] = 11;

    // The loop from before can be rewritten as below:
    sum = 0;
    for(int *p = a; p < a + 10; p++)
    {
        sum += *p;
    }

    // You can also use a pointer as an array name
    int *p3 = a;
    sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum += p3[i]; // This gets treated as *(p3+i)
    }

    // All of the stuff above can be used with multidimensional arrays as well.

    return 0;
}