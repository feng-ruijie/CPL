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
}

int compare_strings(const void *a, const void *b)
{
    const char **s1 = (const char **)a;
    const char **s2 = (const char **)b;
    return strcmp(*s1, *s2);
}

int main(void)
{
    int ints[] = { -2, 99, 0, -743, 2, INT_MIN, 4 };
    int size = sizeof ints / sizeof *ints;

    qsort(ints, size, sizeof(int), compare_ints);

    printf("Sorted integers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n");

    // 使用 bsearch 查找整数
    int key_int = 2;
    int *result_int = (int *)bsearch(&key_int, ints, size, sizeof(int), compare_ints);

    if (result_int != NULL) {
        printf("Found %d at index %ld\n", key_int, result_int - ints);
    } else {
        printf("%d not found\n", key_int);
    }

    // 字符串排序测试
    const char *strings[] = {"banana", "apple", "orange", "mango"};
    size = sizeof(strings) / sizeof(*strings);

    qsort(strings, size, sizeof(const char *), compare_strings);

    printf("Sorted strings: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    // 使用 bsearch 查找字符串
    const char *key_str = "orange";
    const char **result_str = (const char **)bsearch(&key_str, strings, size, sizeof(const char *), compare_strings);

    if (result_str != NULL) {
        printf("Found %s at index %ld\n", key_str, result_str - strings);
    } else {
        printf("%s not found\n", key_str);
    }

    return 0;
}