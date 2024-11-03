#include<stdio.h>
int getsum(int i,int t){
    int sum = 0;
    while(i--){
        sum += t;
        t *= 10;
    }
    return sum;
}
int main(){
    int n,t,ans=0;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++){
        ans += getsum(i,t);
    }
    printf("%d",ans);
}