#include <stdio.h>
#define MAX_P 10005
#define MAX_LEN 10000
void print_term(int coeff, char var[], int pow, int flag);
void add(int coeff1[], int coeff2[], char var[], int p1, int p2);
void substract(int coeff1[], int coeff2[], char var[], int p1, int p2);
void multiple(int coeff1[], int coeff2[], char var[], int p1, int p2);

int main(void){
 //   freopen("b1.in","r",stdin);
 //   freopen("b1.out","w",stdout);
    int p1 = 0, p2 = 0;
    char var[MAX_LEN];
    int coeff1[MAX_P] = {0}, coeff2[MAX_P] = {0};
    scanf("%d%d%s", &p1, &p2, var);
    for (int i = 0; i <= p1; i++){
        scanf("%d", &coeff1[i]);
    }
    for (int i = 0; i <= p2; i++){
        scanf("%d", &coeff2[i]);
    }
    add(coeff1, coeff2, var, p1, p2);
    substract(coeff1, coeff2, var, p1, p2);
    multiple(coeff1, coeff2, var, p1, p2);
    return 0;
}

void print_term(int coeff, char var[], int pow, int flag){
    if (!flag){
        if (coeff == 0){
            return;
        }else if (coeff > 0){
            printf("+");
        }
    }
    if (coeff == 1 && pow != 0){
        printf("%s", var);
    }else if (coeff == -1 && pow != 0){
        printf("-%s", var);
    }else if (pow == 0){
        printf("%d", coeff);
    }else if (pow == 1){
        printf("%d%s", coeff, var);
    }else{
        printf("%d%s^%d", coeff, var, pow);
    }
    
}
void add(int coeff1[], int coeff2[], char var[], int p1, int p2){
    int result[MAX_LEN] = {0};
    int max_p = (p1 > p2) ? p1 : p2;
    for (int i = 0; i <= max_p; i++){
        int c1 = (i <= p1) ? coeff1[p1 - i] : 0;
        int c2 = (i <= p2) ? coeff2[p2 - i] : 0;
        result[i] = c1 + c2;
    }
    print_term(result[max_p], var, max_p, 1);
    for (int i = max_p - 1; i >= 0; i--){
        print_term(result[i], var, i, 0);
    }
    printf("\n");
}
void substract(int coeff1[], int coeff2[], char var[], int p1, int p2){
    int result[MAX_LEN] = {0};
    int max_p = (p1 > p2) ? p1 : p2;
    for (int i = 0; i <= max_p; i++){
        int c1 = (i <= p1) ? coeff1[p1 - i] : 0;
        int c2 = (i <= p2) ? coeff2[p2 - i] : 0;
        result[i] = c1 - c2;
    }
    print_term(result[max_p], var, max_p, 1);
    for (int i = max_p - 1; i >= 0; i--){
        print_term(result[i], var, i, 0);
    }
    printf("\n");
}
void multiple(int coeff1[], int coeff2[], char var[], int p1, int p2){
    int result[MAX_LEN * 2] = {0};
    int max_p = p1 + p2;
    for (int i = 0; i <= p1; i++) {
        for (int j = 0; j <= p2; j++) {
            result[i + j] += coeff1[p1 - i] * coeff2[p2 - j];
        }
    }
    print_term(result[max_p], var, max_p, 1);
    for (int i = max_p - 1; i >= 0; i--){
        print_term(result[i], var, i, 0);
    }
    printf("\n");
}