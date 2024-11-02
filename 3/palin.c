#include<stdio.h>
#include<string.h>
int main(){
    char str[2007];
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0;i<n;i++){
        if(str[i] == '?') str[i] = str[n-i-1];
        if(str[n-i-1] == '?') str[n-i-1] = str[i];
    }    
    printf("%s\n",str);
}