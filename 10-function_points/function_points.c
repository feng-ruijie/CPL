#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
    

    // return arg1 > arg2 ? 1 : 0; 可行的简写
}

int compare_strings(const void *a , const void *b){
    const char *s1 = (const char *)a;
    const char *s2 = (const char *)b;
    return strcmp(s1,s2);
}
int main(void)
{
    int ints[] = { -2, 99, 0, -743, 2, INT_MIN, 4 };
    int size = sizeof ints / sizeof *ints;
 
    qsort(ints, size, sizeof(int), compare_ints);
 
    for (int i = 0; i < size; i++) {
        printf("%d ", ints[i]);
    }
 
    printf("\n");
}