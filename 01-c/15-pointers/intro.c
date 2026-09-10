#include <stdio.h>

void calc_bmi(int age, int height, int *bmi);

int main()
{
    // Pointers are variables that point to a location in memory.
    // For example the variable below points to a location which stores an integer.
    int *age;

    // The Address Operator:
    int i = 22;
    age = &i;
    // The code above assigns the address of i (& the address operator) to age variable.
    // This makes it so that age points to i.
    // you can initialize a pointer variable at declaration via the address operator.

    // The Indirection/Dereference Operator:
    // This operator helps us access the value inside an specific address.
    // For example in the code above we made age point to i which stores the integer '22'.
    // This is how we access said value:
    printf("%d\n", *age); // this prints 22.

    // To print the address itself we use %p format specifier.
    printf("%p\n", age);

    int *p, *q;
    p = q;
    *p = 1;
    *q = 2;
    // In the example above we made both p and q point to the same location.
    // Changing the value with either *p or *q affects both variables,
    // as they are essentially the same location in memory.
    // Any number of pointer variables may point to the same thing.

    *q = *p;
    // In the example above me copy the value that p points to into the memory that q points to.

    // What are the pointers used for?
    // Pointers have a variety of uses.
    // One of them would be using pointer as function arguements.
    // C passes arguements by value, which means that what you pass into a function is copied to
    // to another location in memory to be used by the function specifically.
    // This would pose a problem if you want to modify a variable from inside a function.
    // Pointers make this possible for us.
    // Or let's say we want to pass a struct into a function.
    // If the struct is large that would waste precious memory to just pass it into the function as is.
    // Instead of passing the structs value to the function we can simply pass an address to it.
    int bmi;
    calc_bmi(22, 170, &bmi);

    // When we call a function and pass it a pointer to a variable, we assume it the function
    // would modify the value of that variable, otherwise why would it require a pointer, right?
    // But as I said the reason for passing a pointer might be saving time and storage.
    // In these cases we can use the word const in the arguements to document that the function
    // is only reading the value and is not modifying it.
    // for example: void f(const int *p);

    // We can not only pass pointers to functions but also write functions that return pointers.
    // Just keep in mind that you should never return a pointer to an automatic local variable
    // inside the function.
    // int *f(void)
    // {
    //     int i;
    //     …
    //     return &i; /* WRONG */
    // }

    return 0;
}

void calc_bmi(int age, int height, int *bmi)
{
    *bmi = age / (height * height);
}