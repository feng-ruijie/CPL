#include<stdio.h>

int main(){
    int a[40] = {0};
    int n,tot = 0;
    scanf("%d",&n);
    while(n){
        a[++tot] = n%2;
        n/=2;
    }
    for(int i=32;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}