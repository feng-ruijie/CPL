#include<stdio.h>
#include<string.h>

int main(){
    char s[1030];
    int lst = 0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(s[i] >= 'A' && s[i] <= 'Z' && i!=0){
            s[i] += 'a'-'A';
            for(int j=lst;j<i;j++){
                printf("%c",s[j]);
            }
            printf(" ");
            lst = i;
        }
    }
    for(int i=lst;i<strlen(s);i++){
        printf("%c",s[i]);
    }
}