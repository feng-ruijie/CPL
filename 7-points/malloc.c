#include <stdlib.h>
#include <stdio.h>

int main() {
    // 假设s最初分配了10个字符的空间
    char *s = (char *)malloc(10 * sizeof(char));
    if (s == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    // 使用s...

    // 现在需要更多的空间，假设需要20个字符的空间
    char *new_s = (char *)realloc(s, 20 * sizeof(char));
    if (new_s == NULL) {
        fprintf(stderr, "内存重新分配失败\n");
        free(s); // 释放原来的内存
        return 1;
    }
    s = new_s; // 更新指针

    // 使用新的s...

    free(s); // 最后记得释放内存
    return 0;
}