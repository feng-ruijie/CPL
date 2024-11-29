#include <stdio.h>
void printArray(int (*arr)[3],int x,int y){
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("arr[%d][%d] = %d\n", i, j, *(*(arr+i)+j));
        }
    }
    /*通过指针访问二维数组:
    arr + i 表示指向第 i 行的指针。
    *(arr + i) 表示第 i 行的起始地址。
    *(arr + i) + j 表示第 i 行第 j 列的地址。
    *(*(arr + i) + j) 表示第 i 行第 j 列的值。 */
}
int main(int argc,char *argv[]) {
    // int *arr[]: 数组，每个元素是一个指向 int 的指针
    int *arr1[3];
    int a = 1, b = 2, c = 3;
    arr1[0] = &a;
    arr1[1] = &b;
    arr1[2] = &c;

    for (int i = 0; i < 3; i++) {
        printf("arr1[%d] = %d\n", i, *arr1[i]);
    }

    // int (*arr)[]: 指针，指向一个数组，数组的每个元素是 int 类型
    int data[3] = {1, 2, 3};
    int (*arr2)[3] = &data;

    for (int i = 0; i < 3; i++) {
        printf("(*arr2)[%d] = %d\n", i, (*arr2)[i]);
    }


    //下面是一个二维数组的例子，其中 data 是一个二维数组，arr 是一个指向二维数组的指针
    int dat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 定义一个指向每行有 3 个 int 元素的数组的指针
    int (*arr)[3] = dat;

    // 访问和打印二维数组的元素
    
    printArray(arr,3,3);
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

   return 0;
}