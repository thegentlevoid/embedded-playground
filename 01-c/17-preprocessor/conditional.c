// In this file we'll explore #if, #elif, #else, #ifdef, #ifndef and #endif directives.

#include <stdio.h>

#define VERSION 2
#define DEBUG

int main()
{
    // #if, #elif and #else directives function like if, elseif and else with we learned about
    // in the control flow section.
    // These conditional directives in the preprocessor don't support floating point constants and
    // only work with integers.
    // So `if VERSION == 2.0` is wrong.
    // All conditional directives need to end with #endif directive.
    #if VERSION == 1
    printf("Version 1.0\n", VERSION);
    #elif VERSION == 2
    printf("Version 2.0\n", VERSION);
    #else
    printf("Unkown Version!\n");
    #endif

    // The defined operator checks to see if a macro is defined or not.
    #if defined(DEBUG)
    printf("Program is in debug mode.\n");
    #endif

    // #ifdef directive also checks to see if a macro is defined.
    // `#ifdef DEBUG` is the same as `#if defined(DEBUG)`
    #ifdef DEBUG
    printf("Program is indeed in debug mode.\n");
    #endif

    // Here we just undefined debug to see the next directive in action.
    #undef DEBUG

    // #ifndef directive checks to see if a macro is NOT defined.
    // `#ifndef DEBUG` is the same as `#if !defined(DEBUG)`
    #ifndef DEBUG
    printf("Program is not in debug mode.\n");
    #endif
    return 0;

    // These conditional directives can be useful in quite a lot of places.
    // One example which we saw was the DEBUG mode.
    // We can just wrap the printing of some variables into conditional directives.
    // We can also use these directives in header files to include specific file based on the OS
    // or anything else.
    // One of the most common uses for them is as header guards which we'll learn more about in
    // future notes.
}