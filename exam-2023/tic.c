#include<stdio.h>
#include<stdbool.h>
int n,x,a[15][15],T,b[5];

bool check(int i,int j){
    //right
    int sum = 1;
    for(int k=j+1;k<=n;k++){
        if(a[i][k] == a[i][j]) sum ++;
        else break;
    }
    if(sum >= x) return true;
    sum = 1; 
    //down
    for(int k=i+1;k<=n;k++){
        if(a[k][j] == a[i][j]) sum ++;
        else break;
    }
    if(sum >= x) return true;
    sum = 1; 
    //right down  
    for(int k=1;i+k<=n && j+k<=n;k++){
        if(a[i+k][j+k] == a[i][j]) sum ++;
        else break;
    }
    if(sum >= x) return true;
    sum = 1;
    //left down
    for(int k=1;i+k<=n && j-k>=1;k++){
        if(a[i+k][j-k] == a[i][j]) sum ++;
        else break;
    }
    if(sum >= x) return true;
    return false;
}
int main(){
    scanf("%d %d",&T,&x);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=4;i++) b[i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(check(i,j)){
                    b[a[i][j]] = 1; 
                }
            }
        }
        int ans = 0 , sum = 0; 
        for(int i=1;i<=4;i++){
            if(b[i] == 1){
                sum ++; 
                ans = i;
            }
        }
        if(sum == 0 || sum > 1){
            printf("draw\n");
        }
        else{
            printf("%d\n",ans); 
        }
    }
}