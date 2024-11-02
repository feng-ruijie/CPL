#include<stdio.h>
char s[100005],n;
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z') s[i] -= 32;
        else if(s[i]>='A'&&s[i]<='Z') s[i] += 32;
    }
    for(int i=n-1;i>=0;i--){
        printf("%c",s[i]);
    }
}