#include<stdio.h>

int nxt[1505],n,k,a[1505],b,l;
int main(){
    scanf("%d %d %d %d",&n,&k,&b,&l);
    for(int i=1;i<=n;i++) a[i] = l;
    for(int i=1;i<n;i++) nxt[i] = i+1;
    nxt[n] = 1;
    int sum = 0 , jump = 0 , kk = 0 , nw = 1 , pre = n; //kill 0 
    while(sum < n-1){
   //     printf("%d ",nw);
        jump ++;
        if(jump == k){
     //       printf("\n");
            if(kk == b){ 
            kk = 0;
            jump = 0;
            pre = nw;
            nw = nxt[nw];
            continue;
            }
            kk ++;
            jump = 0;
            a[nw] --;
            if(!a[nw]){ //si le
        //        printf("*");
                sum ++;
                nxt[pre] = nxt[nw];
                nw = nxt[nw]; // nw geng xin , pre bu bian
                continue;
            } 
        }
        pre = nw;
        nw = nxt[nw];
    }
    printf("%d ",nxt[nw]);
    return 0;
}