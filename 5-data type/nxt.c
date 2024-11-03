#include<stdio.h>
int a[2007],n,m=1;
void swap(int *x,int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
int min(int a,int b){
    return a>b?b:a;
}
int main(){
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n-1;i>=1;i--){
        if(a[i] > a[i+1]){
            m ++; 
        }
        else break;
    }
    int minn = 0 , pk = a[n-m] , pos;
    for(int i=n-m+1;i<=n;i++){
        if(pk < a[i]){
            minn = min(minn,pk);
            pos = i;
        }
    }
    swap(&a[n-m],&a[pos]);
    for(int i=1;i<=n-m;i++) printf("%d ",a[i]);
    for(int i=n;i>=n-m+1;i--) printf("%d ",a[i]);
}