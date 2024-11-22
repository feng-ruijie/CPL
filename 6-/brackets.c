#include<stdio.h>
#include<string.h>
char s[100005];
int a[100005],T,tot=0;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        tot = 0;
        int n = strlen(s),p=1;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i] == '[' || s[i] == '{'){
                if(s[i] == '(') a[++tot] = 1;
                if(s[i] == '[') a[++tot] = 2;
                if(s[i] == '{') a[++tot] = 3;
            }
            else{
                if(tot == 0 || (a[tot] == 1 && s[i] != ')') || (a[tot] == 2 && s[i] != ']') || (a[tot] == 3 && s[i] != '}') ){
                    printf("False\n");
                    p = 0;
                    break;
                }
                tot--;
            }
        } 
        if(tot > 0 && p == 1){
            printf("False\n");
            continue;
        }
        if(p == 1) printf("True\n");
    }
}