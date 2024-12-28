#include<stdio.h>
#include<windows.h>
#include "ll/ll.h"

#define num 12
void SitAroundCircle(Linkerlist *ll,int n){
    for(int i=1;i<=n;i++){
        Append(ll,i); //追加一个节点 
    }
}
int main(void){
    Linkerlist list;
    init(&list); 
    SitAroundCircle(&list,num);
    Print(&list);
    KillUntilOne(&list);
    int s = GetSurvivor(&list
    );
    printf("The last one is %d\n",s+1); 
    Free(&list); 
}
//gcc -g -std=c17 -O2 -Iinclude ll/ll.c josephus.c -o josephus