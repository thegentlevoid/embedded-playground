#include <stdio.h>

// The #define directive is used to create preprocessor macros.
// The simplest form is a symbolic constant.
#define MAX_USERS 100
// `int max_users = MAX_USERS;` would be modified into `int max_users = 100;`
// by the preprocessor before being compiled.

// The #undef directive is used to remove a previously define macro.
// While this may seem counter-intuitive at first, it has its uses
// when combined with conditional directives.
#undef MAX_USERS

// Directives always end after the first new-line character, unless
// explicitly continued.
// To explicitly continue a directive to the next line, we must end
// the current line with \ character.
#define LENGTH 4
#define WIDTH 4
#define HEIGHT 2
#define VOLUME (LENGTH * \
                WIDTH *  \
                HEIGHT)

// A more advancded use of macros is in parameterized macros.
#define MAX(x, y) ((x) > (y) ? (x) : (y))
// `int i = MAX(j, k);` would be modified into `int i = ((j) > (k) ? (j) : (k));`
// The number of parentheses might seem excessive, but there's a reason for that.
// Let's explain the reason with an example.
#define SQUARE(x) x * x
// In the example above `SQUARE(2 + 3)` would become `2 + 3 * 2 + 3` which due to
// operator precedence would become `2 + 6 + 3` resulting in 11 instead of 25.
#undef SQUARE

// In general there is two rules we follow when deciding where to put parentheses.
// 1. If the macro replacement list contains an operator always encase the
//    replacement list in parentheses.
#define PI_TIMES_TWO (2 * 3.14)
// 2. If the macro has parameters, put parentheses around each parameter everytime
//    they are used.
#define SQUARE(x) ((x) * (x))

// Macro definitions may contain two special operators.
// 1. # (stringification operator)
#define PRINT_INT(n) printf(#n " is equal to %d\n", n)
// 2. ## (token concatenation operator)
#define JOIN(a, b) a##b

// When creating a macro with a compound statement there is an issue we might encounter.
// Consider the example below:

// #define BILL_GATES_SAYS(s) {      \
//     printf("Bill Gates says:\n"); \
//     printf(s);                    \
// }

// Suppose we are using the macro above in some if statement:

// if (echo_flag)
//     BILL_GATES_SAYS("something");
// else
//     printf("Bill Gates says nothing.");

// The code above becomes:

// if (echo_flag)
// {
//     printf("Bill Gates says:\n");
//     printf("something");
// };
// else
//     printf("Bill Gates says nothing.");

// The compilers treated the ; after } as a null statement, therefore consider the if (echo_flag) { ... }; a complete
// statement and will throw an error because there is an `else` statement afterwards which relates to no `if` statement.

// One solution would be to simply remember not to put the semicolon after BILL_GATES_SAYS but that would look odd.
// A trick that is commonly used in situations like this is to wrap our statements in a do loop whose condition is false
// so that it runs exactly once.
// `do { ... } while(0)`

#define BILL_GATES_SAYS(s) do {   \
    printf("Bill Gates says:\n"); \
    printf(s);                    \
} while(0)

// Notice that the do statement isn't complete and requires a semicolon at the end.


int main()
{
    PRINT_INT(2 * 3); // will print `2 * 3 is equal to 6`
    int JOIN(number, 1) = 22; // `int number1 = 22;`
    printf("number1 is equal to %d\n", number1);
    
    int echo_flag = 1;
    if (echo_flag)
        BILL_GATES_SAYS("Abstraction layers are like condoms. You should wear at least three, otherwise you're a terrorist.");
    else
        printf("Bill Gates says nothing.");
        
    return 0;
}