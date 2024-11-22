#include<stdio.h>
#define N 10005
int a[N],b[N],c[N],n,L;
int main(){
    scanf("%d %d",&n,&L);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int j=1;j<=n;j++) scanf("%d",&b[j]);
    int ans = 0;
    while(L){
        int maxx = -999999999,id=0 ;
        for(int i=1;i<=n;i++){
            if(a[i]>maxx){
                maxx = a[i] , id = i; 
            }
        }
        if(L>=b[id]){
            ans += a[id] * b[id];
            L -= b[id];
        }
        else{
            ans += a[id] * L;
            L = 0;
        }
        a[id] = -999999999;
    }
    printf("%d",ans); 
}