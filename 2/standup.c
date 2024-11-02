#include <stdio.h>
int a[100007],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans = 0,lim = 0;
    for(int i=0;i<=n;i++){
        if(lim < i) ans ++ , lim ++; //到达不了这个数
        lim = lim + a[i];
    }
    printf("%d\n",ans);
}