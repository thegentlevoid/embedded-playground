#include <stdio.h>
#include <stdlib.h>

int main()
{
    // In C data structures are normally fixed in size at compile time. For example
    // when we do `int nums[10]` our array size would be fixed to `10 * sizeof(int)`.
    // But sometimes we need to determine the size of our data structure at runtime,
    // like asking user how many numbers they want to store and then make an array of
    // that specific size.
    // That's where dynamic memory allocation comes into play.
    // There are 4 useful functions for dynamic memory allocation:
    // 1. `void *malloc(size_t size);`
    // 2. `void *calloc(size_t nmemb, size_t size);`
    // 3. `void *realloc(void *ptr, size_t size);`
    // 4. `void free(void *ptr);`
    // All of the functions above are included with `stdlib.h`.

    // 1. MALOC: with maloc you can explicitly request memory from the heap.
    int n = 5;
    int *nums1 = malloc(n * sizeof(*nums1)); // Allocates enough space for an array of n integers.

    // All dynamic memory allocations return a pointer to nothing aka `NULL` in case of failure.
    // So we have to handle the error ourselves inside our program.
    if(nums1 == NULL)
        return 1;

    printf("1. MALOC:\n");

    for(int i = 0; i < n; i++)
    {
        nums1[i] = i + 1;
        printf("%d\n", nums1[i]);
    }

    // It's important to note that malloc doesn't initialize the memory it allocates.
    // You can easily see this by commenting line 30.
    // So the memory contains indetermined values and it's wrong to assume it contains 0s.
    // If you need initial zero values, that's where calloc comes in.

    // 2. CALLOC: allocates space and initializes all the allocated bytes to zeros.
    int *nums2 = calloc(n, sizeof(*nums2));
    if(nums2 == NULL)
        return 1;

    printf("2. CALLOC:\n");

    for(int *i = nums2; i < nums2 + n; i++)
        printf("%d\n", *i);

    //3. REALLOC: with realloc you can resize an existing allocation.
    // When using realloc the pointer you provide as an arguement must point to
    // a memory block obtain by a previous use of malloc, calloc or realloc, otherwise
    // you'd get undefined behaviour.
    // When reducing the size of a memory block realloc should shrink the block in place,
    // by the same account when attempting to expand a memory block realloc would try to
    // do it without moving it.
    // If realloc is unable to enlarge a block because the following bytes are already in
    // use for some other purpose, realloc will allocate a new block elsewhere and then copy
    // the contents of the old block into the new one.

    // `nums2 = realloc(nums2, 10);`
    // Using realloc like above is unsafe bacause if the allocation fails nums2 would become
    // NULL and we would lose the original pointer while the previous allocation is still in
    // place. THAT'S A MEMORY LEAK.
    // The safe way would be to store it in a temporary variable first the assign it to nums2
    // if the result wasn't NULL.
    // Also keep in mind that when expanding realloc doesn't initialize the newly added bytes.
    int *temp = realloc(nums2, 10 * sizeof(*nums2));
    if(temp == NULL)
        return 1;
    else
        nums2 = temp;

    printf("3. REALLOC:\n");

    for(int *i = nums2; i < nums2 + 10; i++)
        printf("%d\n", *i);
    
    // * When using realloc with a null pointer as the first arguement, it behaves like malloc:
    // `realloc(NULL, n * sizeof(int))` == `malloc(n * sizeof(int))`

    // * When using realloc with 0 as it's second arguement, it behaves like free:
    // `realloc(nums2, 0)` == `free(nums2)`

    // 4. FREE: with free we can deallocate a previously allocated memory block.
    // Every successful dynamic allocation should eventually have a corresponding free().
    free(nums1);
    free(nums2);
    // Although free function allows us to reclaim memory that is no longer needed, it leads to
    // a new problem. "dangling pointers".
    // In lines 88 and 89 we deallocated memory blocks that nums1 and nums2 point to, but the
    // pointers `nums1` and `num2` still remain.
    // If we forget the fact that we have deallocated those memory blocks and attempt to modify
    // the memory that they points to, we'll have some serious issues because our program no longer
    // has control of that memory.
    // So it's best to clear the pointers to after each call of free().
    nums1 = NULL;
    nums2 = NULL;
    temp = NULL;

    return 0;
}