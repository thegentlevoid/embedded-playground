#include <stdio.h>
#include <string.h>

int main()
{
    // there are some quirky stuff with scanf when trying to read char inputs.
    // I'll explain those in the types section or just reorder this to come after types later.
    int age = 0;
    char grade = '\0';
    char name[20] = "";

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your grade: ");
    // scanf("%c", &grade);

    // With the code above the user won't be given a chance to enter their grade
    // Because when user enters the age for the previous prompt they have to sumbit it
    // using the "Enter" key with also adds a new-line character at the end of the input buffer.
    // So when the scanf on line 11 catches the age our user entered there would still be an \n
    // left inside an input buffer which "scanf("%c", &grade);" instantly picks up so our grade would be \n.
    // To avoid this issue when using scanf use a whitespace at the start of your format string.
    scanf(" %c", &grade);

    getchar(); // This is also another way to clear \n from the input buffer.
    printf("Please enter your full name: ");
    // scanf("%s", &name);

    // With the code above the user won't be able to enter any whitespaces in their name.
    // So an input like "Erfan" would be fine but "Erfan Baghdadi" won't work.
    // That's because scanf will stop reading after encountering any spaces.
    // To work around this we will use a different function called "fgets".
    // fgets(buff, n, stream);
    fgets(name, sizeof(name), stdin); // variable name must have a defined size.
    // After doing this we still will have an \n at the end of the value written into variable name.
    // To get rid of that we can do the following:
    name[strlen(name) - 1] = '\0';
    // strlen is a function from string.h library so we must include that.

    printf("User's age is %d\n", age);
    printf("User's grade is %c\n", grade);
    printf("User's full name is %s\n", name);

    return 0;
}