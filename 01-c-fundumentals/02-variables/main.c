#include <stdio.h>

int main()
{
    /*
    * Types:
    *   The first part of variable declaration defines it's type.
    *   There are different types available in c programming language
    *   which we will explore later.
    *   For now we will keep to using int and float.
    *
    * Declaration:
    *   Variables must be declared before being used.
    *   We have to let the compiler now there exists a variable of type
    *   *TYPE* and of name *NAME*.
    *
    * Assignment:
    *   After declaring a variable we can and should assign a value of
    *   the specific type to it.
    *   Assignment can both be done in the same statement as declaration
    *   or be done later.
    *   Failing to assign a value to a variable results in undefined behavior.
    */

    // example of seperate declaration and assignment
    int age, year_of_birth;
    age = 22;
    year_of_birth = 2004;

    // declaring and assigning in a single statement
    float height = 1.72f;

    printf("I'm %d years old and I was born in %d.\n", age, year_of_birth);
    printf("I'm %.2f centimeters tall.\n", height);
    return 0;
}