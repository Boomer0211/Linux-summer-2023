#include <stdint.h>
#include <stdio.h>
static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) {  /* power of two? */
        return (sz + mask) & ~mask;       
    }
    return (((sz + mask) / alignment) * alignment);
}

int main()
{
    printf("%d\n", (int)align_up(120, 4));
    printf("%d\n", (int)align_up(121, 4));
    printf("%d\n", (int)align_up(122, 4));
    printf("%d\n", (int)align_up(123, 4));
    return 0;
}