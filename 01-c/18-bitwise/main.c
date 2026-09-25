#include <stdio.h>

int main()
{
    unsigned short i = 22; // 0000000000010110
    unsigned short j = 42; // 0000000000101010
    unsigned short k = 0;  // 0000000000000000

    // Bit-shift operators:
    printf("i: %hu\n", i);      // i      = 0000000000010110 = 22
    printf("i << 2: %hu\n", i << 2); // i << 2 = 0000000001011000 = 88
    printf("i >> 2: %hu\n", i >> 2); // i >> 2 = 0000000000000101 = 5

    // Bitwise complement `~`, and `&`, or `|`, xor `^` operators.
    printf("~i: %hu\n", ~i);    // ~i    = 1111111111101001 = 
    printf("i & j: %hu\n", i & j); // i & j = 0000000000000010 = 2
    printf("i | j: %hu\n", i | j); // i | j = 0000000000111110 = 62
    printf("i ^ j: %hu\n", i ^ j); // i ^ j = 0000000000111100 = 60

    // Bitwise operators can be used to access and modify bits which is specially
    // useful when doing low-level programming.
    // 1. Setting a bit:
    //    To set a specific with we can simply `|` it with a constant that has that
    //    specific bit set to one. Such constants are referred to as masks.
    //    * Example: set the 4th bit in `i`.
    k = i | 0x0008; // 0x0008 = 0000000000001000
    printf("1. k: %hu\n", k); // k = 0000000000011110 = 30

    // 2. Clearing a bit:
    //    To clear a specific bit we can `&` it with a constant that has all bits
    //    except that specific bit set to one.
    //    * Example: clear the 3rd bit in `i`.
    k = i & ~0x0004; // 0x0004 = 0000000000000100
    printf("2. k: %hu\n", k); // k = 0000000000010010 = 18

    // 3. Testing a bit:
    //    To test if a specific bit is set we `&` it with a constant that has that
    //    specific bit set to one.
    //    * Example: test the 3rd bit in `i`.
    if(i & 0x0004)
        printf("3. third bit of `i` is set.\n");
    

    // There's also some useful idioms for setting, clearing and testing bits
    k = i | (1 << 3); // 1 << j creates a mask with on the j-bit set.
    printf("IDIOM 1. k: %hu\n", k);
    // The example above sets the fourth bit.
    // Note that to clear the 4th bit we are shifting 1 by 3.
    // The reason for that is the bit positions start from 0 going up.
    // So the right-most bit is called the 0-bit.
    // This priciple can be applied to clearing and testing bits too.

    k = i & ~(1 << 2);
    printf("IDIOM 2. k: %hu\n", k);
    // The example above clears the third bit.

    if(i & (i << 2))
        printf("IDIOM 3. third bit of `i` is set.\n");
    // The example above tests the third bit.

    // Bitwise operators can also be used to access bit-fields too instead of single bits.
    // 1. Modifying a bit-field:
    //    Modifying a bit-field requires a bitwise and `&` to clear the bit-field followed by
    //    a bitwise or `|` to set the bit-field.
    //    * Example: store bits `101` inside bits 4-6 of `i`
    k = i & ~0x0070 | 0x0050;
    // 0x0070 = 0000000001110000
    // 0x0050 = 0000000001010000
    printf("4. k: %hu\n", k); // k = 0000000001010110 = 86

    // 2. Retrieving a bit-field:
    //    To Retrieve a bit-field we first have to shift it to the end then extract the bits using
    //    an appropriate mask.
    //    * Example retrieve bits 4-6 from `i`
    k = (i >> 4) & 0x0007;
    printf("5. k: %hu\n", k);
    

    return 0;
}