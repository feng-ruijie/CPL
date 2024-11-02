#include<stdio.h>

const int mod = 10007;
int main(){
    int jie = 1 , sum = 0 , n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        jie = jie * i % mod;
        sum = (sum + jie) % mod;
    }
    printf("%d",sum);
}