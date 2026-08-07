#include <stdio.h>

int main()
{
    // Below is an example of defining an array and accessing it's values
    int nums[] = { 1, 2, 3, 4, 5 };
    printf("%d\n", nums[0]);

    // To find out how many values are stored in an array we can use sizeof function.
    // The sizeof function return the size of it's provided arguement in bytes.
    // So to get the number of elements we have to divide the size of the whole array by
    // the size of one of it's elements.
    int array_length = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", array_length);

    // When declaring an array without initializing it, you must provide a size for it
    // This is useful for when you want to store user input values inside arrays
    char grades[5];

    // When accessing elements of an array that isn't initialized and no values are assigned to it
    // you get undefined behaviour
    // To avoid that, when declaring a fixed sized array we can set all it's elements to 0 (the 0 value of it's specified type)
    char qwerty[5] = { '\0' }; // \0 is called the null terminator

    // An array of arrays it called a 2d array
    // One thing to take note of is that multi-dimensional arrays must have bound for
    // all dimensions except the first one.
    char numpad[][3] = {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
        { '*', '0', '#' },
    };

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("%c ", numpad[i][j]);
        printf("\n");
    }

    // An array of strings is simply a multi-dimensional array like below
    char names[][16] = {
        "Noa",
        "thegentlevoid",
        "missingcodec"
    };

    for(int i = 0; i < 3; i++)
        printf("%s\n", names[i]);

    return 0;
}