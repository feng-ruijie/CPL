#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l[105];
char s[105][105];
char a[10005];
int cmp(const void *a,const void *b){
    char *s1 = (const char *)a;
    char *s2 = (const char *)b;
    return strcmp(s1,s2);
}
int main(){
    scanf("%s\n",a);
    char c;
    scanf("%c",&c);
    int len = strlen(a),tot = 0;
    for(int i=0;i<len;i++){
        if(a[i] != c){
            s[tot][l[tot]++] = a[i];
        }
        else{
            s[tot][l[tot]] = '\0';
            tot ++; 
        } 
    }
    s[tot][l[tot]] = '\0';
    qsort(s,tot+1,sizeof(s[0]),cmp); 
    for(int i=0;i<=tot;i++){
        printf("%s\n",s[i]);
    }
    
}