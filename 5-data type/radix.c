#include<stdio.h>

int change(int x,int a){ //把x从a进制转成进制
    int sum = 0,s=1;
    while(x){
        int c = x % 10;
        if(c >= a) return -1; //
        sum += c * s;
        s *= a; 
        x /= 10;
    }
    return sum;
}
int main (){
    int p,q,r;
    scanf("%d %d %d",&p,&q,&r);
    
    for(int i=2;i<=40;i++){
        int x = change(p,i),y = change(q,i),z = change(r,i);
        if(x < 0 || y < 0 || z < 0) continue;
        if(x * y == z){
            printf("%d",i);
            return 0;
        }
    }
}