#include<stdio.h>
#include<stdbool.h>
int hanming(int x){
    int sum = 0;
    while(x){
        if(x&1) sum ++;
        x >>= 1;
    }
    return sum;
}
int main(){
    int a,b;
    bool c = 1;
    printf("%d ",c);
    scanf("%d %d",&a,&b);
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",a&b,a|b,a^b,~a,a<<b,a>>b,(a>>b)&1,hanming(a));
}