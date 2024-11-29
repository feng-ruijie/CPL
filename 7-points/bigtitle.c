#include<stdio.h>
#include<malloc.h>
#include<string.h>
char BIG(char c){
    if(c>='a'&&c<='z'){
        return c-32;
    }
    return c;
}
char SMALL(char c){
    if(c>='A'&&c<='Z'){
        return c+32;
    }
    return c;
}
int main(){
    char *s = malloc(4100*sizeof(char));
    fgets(s,4100,stdin);
    int n = strlen(s);
    printf("%d",n);
    int first = 0;
    for(int i=0;i<n;i++){
        if(*(s+i) == ' ' || i == n-1){
            *(s+first) = BIG(*(s+first));
            first = i+1;
        }
        else{
            *(s+i) = SMALL(*(s+i));
        }
    }
    printf("%s",s);
}