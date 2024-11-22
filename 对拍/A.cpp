#include <stdio.h>
#include <limits.h>

int arr[720][720] = {0};
int position[10000][3] = {0};

int First(int i, int d) {
    int sum = 0;
    for (int l = 1; l <= 1 + d; l++) {
        for (int k = 1; k <= d + 1 - l; k++) {
            sum += arr[i - k][d + l] + arr[i + k][d + l];
        }
        sum += arr[i][d + l];
    }

    return sum;
}

int Move(int i, int j, int d, int move) {
    for (int k = 1; k <= d; k++) {
        move += arr[i + d + 1 - k][j + k] + arr[i - d - 1 + k][j + k];
        move -= arr[i + d + 1 - k][j - k + 1] + arr[i - d - 1 + k][j - k + 1];
    }
    move += arr[i][j + d + 1];
    move -= arr[i][j - d];

    return move;
}

int main(void) {
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);

    for (int i = d + 1; i <= d + n; i++) {
        for (int j = d + 1; j <= d + m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int maxValue = INT_MIN;
    int count = 0;
    for (int i = d + 1; i <= d + m; i++) {
        int first = First(i, d);
        if (first > maxValue) {
            maxValue = first;
            count = 1;
            position[count][0] = i - d;
            position[count][1] = 1;
        } else if (first == maxValue) {
            count++;
            position[count][0] = i - d;
            position[count][1] = 1;
        }

        int move = first;
        for (int j = d + 1; j <= d + m - 1; j++) {
            move = Move(i, j, d, move);
            if (move > maxValue) {
                maxValue = move;
                count = 1;
                position[count][0] = i - d;
                position[count][1] = j - d + 1;
            } else if (move == maxValue) {
                count++;
                position[count][0] = i - d;
                position[count][1] = j - d + 1;
            }
        }
    }

    printf("%d %d\n", maxValue, count);
    for (int i = 1; i <= count; i++) {
        printf("%d %d\n", position[i][0], position[i][1]);
    }
}
