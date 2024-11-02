#include<stdio.h>
int T,n,a[50007];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int maxx = -0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            maxx = (maxx>a[i]) ? maxx : a[i];
        }
        if(maxx != a[n]){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
}