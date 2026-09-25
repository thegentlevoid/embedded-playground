#include <stdio.h>
#include <string.h> // Provides some useful functions for strings.

int main()
{
    // A string literal is a sequence of characters enclosed within double quotes.
    // If we find that a string literal is too long to fit conveniently on a single line, C
    // allows us to continue it on the next line provided that we end the first line with a
    // backslash character (\). No other characters may follow \ on the same line, other
    // than the (invisible) new-line character at the end.
    printf("When you come to a fork in the road, take it --Yogi Berra\n");
    printf("When you come to a fork in the road, take it \
--Yogi Berra\n");
    // The drawback of this technique is that the string must continue at the beginning of nextline
    // thus ruining our code's indentation.
    // Another method is two split our string literal into multiple parts.
    // When two or more string literals are placed adjacent, seperated only by whitespce, the compiler
    // will join them into a single string.
    printf(
        "When you come to a fork in the road, take it "
        "--Yogi Berra\n"
    );

    // A string literal with n characters is stored as an array of characters with the length n+1,
    // with the last place occupied by the null terminator character '\0'.
    // The null terminator character is a byte whose bits are all zero.
    char str1[] = "abc";
    char str2[] = { 'a', 'b', 'c', '\0' };
    // `str2` is how `str1` is actually stored in memory.

    // Since a string literal is stored as an array the compiler treats it as a pointer of type
    // `char *`. both printf and scanf for example expect an input of type `char *` as their
    // first arguement.
    printf("abc\n"); // What printf recieves is a pointer to the location character `a` is stored at.

    char *str3 = "abc"; // String variables can also be defined like this.
    // Since string literals are treated as arrays str3 would point to it's first character.

    char c = "abc"[1]; // You're also allowed to subscript string literals.

    // Attempting to modify string literals causes undefined bahaviour.
    // *str3 = 'd'; /* UNDEFINED BEHAVIOUR */

    // When defining an string variable make sure to always account for the null terminator
    // character in the array length.

    // When the initializer is too short to fill the string variable the rest of the space is
    // filled with \0
    // This behavior is consistent with C’s treatment of array initializers in general. When
    // an array initializer is shorter than the array itself, the remaining elements are
    // initialized to zero.
    char str4[7] = "Hello";
    char str5[7] = { 'H', 'e', 'l', 'l', 'o', '\0', '\0' };
    // `str5` is a representation of how `str4` will be saved in memory.

    // Although strings can be defined both as arrays and pointers we must not make the mistake
    // of assuming they are interchangeable.
    char str6[] = "abc";
    str6[1] = 'd';
    // In the array version the characters can be modified, like the elements of any array.
    // But in the pointer version our variable points to a string literal and as we saw,
    // we can't modify string literals, but the pointer itself can be modified to point
    // somewhere else.
    char *str7 = "abc";
    str7 = "def";

    // When wanting to define an array of strings we got two options.
    // 1. To define it as a two dimensional array of characters.
    // 2. To define it as an array of pointers, pointing to string literals.
    char planets1[][8] = {
        "Mercury", "Venus", "Earth",
        "Mars", "Jupiter", "Saturn",
        "Uranus", "Neptune", "Pluto"
    };

    char *planets2[] = {
        "Mercury", "Venus", "Earth",
        "Mars", "Jupiter", "Saturn",
        "Uranus", "Neptune", "Pluto"
    };

    // In the first option since we have to define a length for second dimension,
    // strings that are shorter will get filled with \0 character. So something like
    // `Mars` would be saved as `M a r s \0 \0 \0 \0`. That results in a lot of wasted
    // memory space.
    // In the second method each element of `planets2` points to a null terminated string.
    // There are no longer any wasted characters in strings.
}