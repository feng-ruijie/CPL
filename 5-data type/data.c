#include <stdio.h>
#include <limits.h>
#define __int128 long long
int main() {
    // 基本数据类型
    printf("Size of char: %lu byte(s)\n", sizeof(char));
    printf("Size of int: %lu byte(s)\n", sizeof(int));
    printf("Size of float: %lu byte(s)\n", sizeof(float));
    printf("Size of double: %lu byte(s)\n", sizeof(double));
    printf("Size of long: %lu byte(s)\n", sizeof(long));
    printf("Size of long long: %lu byte(s)\n", sizeof(long long));

    // 指针
    printf("Size of char*: %lu byte(s)\n", sizeof(char*));
    printf("Size of int*: %lu byte(s)\n", sizeof(int*));
    printf("Size of float*: %lu byte(s)\n", sizeof(float*));
    printf("Size of double*: %lu byte(s)\n", sizeof(double*));
    printf("Size of long*: %lu byte(s)\n", sizeof(long*));
    printf("Size of long long*: %lu byte(s)\n", sizeof(long long*));

    // 其他类型
    printf("Size of void*: %lu byte(s)\n", sizeof(void*));
    printf("Size of size_t: %lu byte(s)\n", sizeof(size_t));    

    printf("%lu\n",UINT_MAX);
    int array[8];
   // size_t array_size = sizeof(array) / sizeof(array[0]);
   // printf("%d ",array[7]);
    return 0;
}