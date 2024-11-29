#include <stdio.h>
#include <stdbool.h>
#define MAX_N 35
bool find_node(int string[][2], int m, int id, int len);
int break_node(int string[][2], int m, int len);

int main(void) {
    int n = 0, q = 0;
    scanf("%d%d", &n, &q);

    int string[MAX_N][2] = {0};  
    string[0][0] = n;  
    int len = 1;

    while (q--) {
        char order;
        getchar();
        scanf("%c", &order);

        if (order == 'Q') {
            printf("%d\n", len);
            for (int i = len - 1; i >= 0; i--) {
                printf("%d ", string[i][1]);
            }
            printf("\n");
        } else if (order == 'A') {
            int id = 0, m = 0;
            scanf("%d%d", &id, &m);
            while (!find_node(string, m, id, len)) {
                int newlen = break_node(string, m, len);
                if (newlen == len) {
                    break;
                }else{
                    len = newlen;
                }
            }
        }
    }
    return 0;
}

bool find_node(int string[][2], int m, int id, int len) {
    for (int i = len - 1; i >= 0; i--) {
        if (string[i][1] == 0 && string[i][0] == m) {
            string[i][1] = id;
            return true;
        }
    }
    return false;
}

int break_node(int string[][2], int m, int len) {
    for (int i = len - 1; i >= 0; i--) {
        if (string[i][1] == 0 && string[i][0] > m) {
            string[i][0]--;
            for (int j = len; j > i + 1; j--) {
                string[j][0] = string[j - 1][0];
                string[j][1] = string[j - 1][1];
            }
            string[i + 1][0] = string[i][0];
            string[i + 1][1] = 0;
            len++;
            break;
        }
    }
    return len;
}