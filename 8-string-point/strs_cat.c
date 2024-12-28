#include<stdio.h>
#include<string.h>
#include<malloc.h>
int min(int a,int b){
    return a>=b?b:a;
}
char *mstrcat(char *s1,char *s2){
    char *s = malloc(sizeof(char)*2001);
    char *ans = s;
    int l1 = strlen(s1) , l2 = strlen(s2);
    int point = min(l1,l2)-1;
    while(1){
        int p = 0;
        for(int i=0;i<=point;i++){
            if(*(s1+l1-1-(point-i)) != *(s2+i)){
                p = 1;
                break;
            }
        }
        if(p == 0) break; 
        point --;
    }
    for(int i=0;i<l1;i++){
        *s = *(s1+i);
        s++;
    }
    for(int i=point+1;i<l2;i++){
        *s = *(s2+i);
        s++;
    }
    *s = '\0';
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char *s1,*s2;
        s1 = malloc(sizeof(char)*1007);
        s2 = malloc(sizeof(char)*1007);
        scanf("%s %s",s1,s2);
        printf("%s\n",mstrcat(s1,s2));
        free(s1),free(s2);  
    }
}