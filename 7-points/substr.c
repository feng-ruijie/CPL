#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main(){
    char *s , *t;
    s = malloc((sizeof(char)*100007));
    t = malloc((sizeof(char)*100007));
    scanf("%s\n%s",s,t);
    int len1 = strlen(s) , len2 = strlen(t);
    for(int i=0;i<len1;i++){
        int p = 0;
        for(int j=0;j<len2;j++){
            if(i+j >= len1 || *(s+i+j) != *(t+j)){
                p = 1;
                break;
            }
        }
        if(p == 0){
            printf("%d ",i);
        }
    }
    free(s);
    free(t);
}