// C and C++ are a bit unique among major progamming language. that's because
// they rely on something called the preprocessor.
// The preprocessor is a piece of software that edits the program before
// actual compilation.
// So the compilation process is something like below:
// C Program -> Preprocessor -> Modified C Program -> Compiler -> Object Code
// The behaviour of the preprocessor is controlled by preprocessing directives.
// We've seen a couple of these directives so far like `#include` and `#define`.
// Directives start with # operator.

#include <stdio.h>
// `#include <stdio.h>` instructs the preprocessor to open the file `stdio.h`
// and bring its contents into the program.

#define PI 3.14f
// `#define PI 3.14f;` defines a macro named PI with the value of 3.14f.

// We'll explore all directives each in dedicated .c files in this section.

int main()
{
    printf("PI: %.2f", PI);
    return 0;
}