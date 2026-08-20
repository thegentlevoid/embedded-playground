#include <stdio.h>

// Unions are kind of like structs with the difference that the space unions took in memory
// equals to the biggest element in the union.
// Let's say we got two int keys each being 4 byte long and a string of size 20 bytes.
// If we have an struct containing those keys it would be 28 bytes long.
// But if we have those same keys inside a union it will be 20 bytes long.
// Due to the nature of unions, the members share the same space in memory,
// so altering one members affects and corrupts other members.
// One use case of unions is in conjuction with structs to save space.

typedef struct
{
    char name[16]; // 16 bytes
    int age; // 4 bytes
    enum
    {
        STUDENT,
        ATHLETE
    } occupation; // 4 bytes
    union
    {
        struct
        {
            char major[16]; // 16 bytes
            float gpa; // 4 bytes
        }; // 20 bytes
        struct
        {
            char sport[32]; // 32 bytes
            int weight; // 4 bytes
            int height; // 4 bytes
        }; // 40 bytes
    }; // instead of 40 + 20 bytes it takes only 40 bytes
} Person; // 64 bytes

// In the example above we saved 20 bytes of space with the use of unions.

int main()
{
    // Use designated initializers for members of unions to avoid unexpected behaviour.
    Person student = {
        "Erfan",
        22,
        STUDENT,
        .major = "EE",
        .gpa = 3.0f,
    };

    printf("%d\n", sizeof(student));
}