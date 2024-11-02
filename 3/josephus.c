#include<stdio.h>
int nxt[1005];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n-1;i++) nxt[i] = i+1;
    nxt[n] = 1;
    int sum = n,j = 1,i = 1;
    if(k == 1){
        printf("%d",n);
        return 0;
    }
    while(1){
        if(j+1 == k){
            nxt[i] = nxt[nxt[i]] ; j = 0 ; sum --;
        } 
        if(sum == 1){
            printf("%d",nxt[i]);
            return 0;
        }
        i = nxt[i];
        j++;
      //  printf("%d ",nxt[i]);
    }
    
}