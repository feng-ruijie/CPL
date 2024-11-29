#include<stdio.h>

int main(){
    unsigned int x;
    scanf("%x",&x);
    int a;
    unsigned int b;
    float c;
    a = x; 
    printf("%d\n",a);
    b = x;
    printf("%u\n",b);
    c = *(float*)&x;
    printf("%.6f\n%.3e\n",c,c);
}