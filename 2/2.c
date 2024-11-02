#include<stdio.h>

int main(){
    int n;
    scanf("%d",n);
    int ans = 0;
    for(int i=1;i<=2*n-1;i++){
        int x;
        scanf("%d",x);
        ans = ans ^ x;
    }
    printf("%d",ans);
}