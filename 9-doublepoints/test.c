#include<stdio.h>
#include<string.h>

int main(){
    char *src = "123456" , *dest = "abcdef";
    strncpy(dest,src,3);
    printf("%d",dest); 
}