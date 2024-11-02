#include<stdio.h>
#include<string.h>

int main(){
    char name[107];
    double pre,frac,factor;
    char unit;
    scanf("%s%lf%lf%lf%c",&*name,&pre,&frac,&factor,&unit);
    //printf("%s",*name);
    double sciexp = pre + frac , conv = (pre + frac) * factor;
    char newunit = unit - 32;
    int p = pre;
    printf("%.2s: %d (%.5lf) | %.5lE %.5lf %c",name,p,frac,sciexp,conv,newunit);
}