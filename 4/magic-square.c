#include<stdio.h>
int n,cnt=0,x,y,a[1007][1007];
int main(){
    scanf("%d",&n);
    x = 2 , y = n/2 ,cnt = 0;
    while(cnt < n*n){
        int nx = x-1 , ny = y+1;
        if(nx < 1) nx += n;
        if(ny > n) ny -= n;
        if(!a[nx][ny]) a[nx][ny] = ++cnt , x = nx , y = ny;
        else{
            nx = x+1 , ny = y;
            if(nx < 1) nx += n;
            if(ny > n) ny -= n;
            a[nx][ny] = ++cnt;
            x = nx , y = ny;
        }
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}