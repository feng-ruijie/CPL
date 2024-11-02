#include<stdio.h>

void swap(int *a,int *b){ //对于真正的值的改变，需要用指针实现
    int temp = *a;
    *a = *b;
    *b = temp; 
}
int main(){
    int n,ans=0,n1;
    scanf("%d",&n);
    n1 = n;
    while(n1!=495){
        int maxx,minn,a,b,c;
        a = n1/100 , b = n1/10%10 , c = n1%10;
        if(a<b) swap(&a,&b);
        if(a<c) swap(&a,&c);
        if(b<c) swap(&b,&c);
        maxx = a*100 + b*10 + c;
        minn = c*100 + b*10 + a;
        n1 = maxx - minn;
        if(n - n1 > 0) ans += n-n1;
        printf("%d %d %d\n",maxx,minn,n1);
    }
    printf("%d",ans);
}