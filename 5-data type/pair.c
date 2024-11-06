//最小化 t-b[j]-a[i] && >= 0
// 寻找小于等于t-b[j]最大的a[i]

#include<stdio.h>

#define N 1000007
int a[N],b[N],n,m,ans = 0x7fffffff,t;
int max(int a,int b){
    return a>b?a:b;
}
int binary_search(int x){
    int sum = -1,l=1,r=n;
    while(l<=r){
        int mid = (l+r) >> 1;
        if(a[mid] <= x){
            sum = max(sum,a[mid]);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return sum;
}
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i=1;i<=m;i++){
        int x = binary_search(t-b[i]);
        if(x == -1) continue; //不更新
        ans = min(ans,t-b[i]-x);//更新答案
    }
    if(ans == 0x7fffffff){
        printf("-1\n"); return 0;
    }
    printf("%d\n",ans);
}