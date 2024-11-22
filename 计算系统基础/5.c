#include<stdio.h>

int main(){
    int s0,i,n,t,o;
    scanf("%d%d%d%d%d",&s0,&i,&n,&t,&o);
    int q;
    if(o == i) q = 1;
    else if(o == n) q = 2;
    else if(o == t) q = 3;
    else q = 4;
    if(s0 == 0){
        if(q == 1){
            printf("1");
        }
        else printf("0");
    }
    if(s0 == 1){
        if(q == 2){
            printf("2");
        }
       else if(q == 1){
        printf("1");
       }
        else printf("0");
    }
    if(s0 == 2){
        if(q == 3){
            printf("3");
        }
       else if(q == 1){
        printf("1");
       }
        else printf("0");
    }
    if(s0 == 3){
        if(q == 1){
            printf("1");
        }
        else printf("0");
    }
    return 0;
}