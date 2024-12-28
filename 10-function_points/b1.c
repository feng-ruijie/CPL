#include<stdio.h>
#include<stdlib.h>
int a[1000007],n,q;
int compare(const void *a,const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;
    return x < y ? -1 : 1;
}
int main(){
    scanf("%d %d",&n,&q); 
    for(int i=0;i<n;i++) scanf("%d",&a[i]); 
    while(q--){
        int x;
        scanf("%d",&x);
        int *res = bsearch(&x,a,n,sizeof(int),compare);
        if(res == NULL) printf("-1\n");
        else printf("%d\n",res-a);
    }
}