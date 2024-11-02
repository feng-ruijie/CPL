#include<stdio.h>
#include<string.h>
int strick[]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888}; // 21
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int sum = 0;
        while(n>=21){
            sum ++;
            n-=7;
        }
        printf("%d",strick[n]);
        for(int i=0;i<sum;i++)
        printf("8");
        printf("\n");
        
    }
}