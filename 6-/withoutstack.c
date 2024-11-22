#include <stdio.h>
#include <string.h>

char str[100005];

int main(void) {
    int T = 0;
    scanf("%d", &T);

    start:
    if(T) {
        scanf("%s", str);
        int len = strlen(str);

        int top = 0;
        while (str[top] != '\0') {
            int temp = 0;
            for (int j = top + 1; j < len; j++) {
                if ((str[top] == '(' && str[j] == ')') ||
                    (str[top] == '[' && str[j] == ']') ||
                    (str[top] == '{' && str[j] == '}')) {
                    temp = j;
                    if ((temp - top) % 2 == 0) {
                        printf("False\n");
                        T--;
                        goto start;
                    }
                    goto next;
                    }
            }
            printf("False\n");
            T--;
            goto start;

            next:
            for (int k = 1; top + k < temp - k; k++) {
                if ((str[top + k] == '(' && str[temp - k] == ')') ||
                    (str[top + k] == '[' && str[temp - k] == ']') ||
                    (str[top + k] == '{' && str[temp - k] == '}')) {
                    } else {
                        printf("False\n");
                        T--;
                        goto start;
                    }
            }

            top = temp + 1;
        }

        printf("True\n");
        T--;
        goto start;
    }

    return 0;
}