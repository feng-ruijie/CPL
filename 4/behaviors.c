#include<stdio.h>

int main(){
    int a[]={0,0,0,3,0,0,0,0,8,0,0,0,0,0,14,15,16,0,18};
    int n,x;
    scanf("%d",&n);
    int a1=-1,a2=0,a3=0;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        a1 &= a[x];
        a2 |= a[x];
        a3 ^= a[x];
    }
    printf("%d %d %d",a1,a2,a3);
}