#include <stdio.h>
#include <string.h>

struct Person
{
    char first_name[20];
    char last_name[20];
    int age;
};

typedef struct
{
    char name[50];
    int age;
    float gpa;
} Student;

// You must define array sizes inside structs.
// Also for string sizes you should do LENGTH+1 bacause you need to count the null terminator too.

int main()
{

    struct Person person1 = { "Erfan", "Baghdadi", 22 };
    struct Person person2 = { 0 };
    strcpy(person2.first_name, "Erfan"); // This is how you modify string values.
    strcpy(person2.last_name, "Baghdadi");
    person2.age = 22;

    Student student1 = { "Erfan Baghdadi", 22, 3.0 };
    
    // Like an array, a struct variable can be initialized at the time it's declared.
    // Also you can use designated initializers instead of assigning values in order.
    struct
    {
        char product[20];
        int price;
    } product = {
        .price = 1299,
        .product = "Iphone 17",
    };

    printf("First name: %s\nLast name: %s\nAge: %d\n", person1.first_name, person1.last_name, person1.age);
    
    return 0;
}