//题目描述比较晦涩，这还是中文吗
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map[1025]={0},len[1025]={0},l=0;
char ans[1025][1025];
int main(){
    char *s = malloc(130);
    scanf("%s", s);
    while(*s!='\0'){
        int x = *s;
        if(*(s+1)==':'){
            map[x] = 2;
        }
        else map[x] = 1;
        s++;    
    }
    getchar();
    char s1[1025];
    scanf("%s",s1);
    printf("%s",s1);
    int p = 0 , fl = 0; // p = 0 读指令阶段 ，p = 1读参数阶段
    char lst = ' ';
    while(scanf("%s", s1)!=EOF){
        if(p == 0){
            if(s1[0] != '-') continue;
            lst = s1[1];
            if(map[(int)s1[1]] == 0){
                fl = 1; //错误：未出现的指令
                break;
            }
            if(map[(int)s1[1]] == 1){
                ans[++l][0] = s1[1];
                len[l] = 1;
            }
            if(map[(int)s1[1]] == 2){
                p = 1;
                ans[++l][0] = s1[1];
                len[l] = 1;
            }
        }
        else if(p == 1){
            int lne = strlen(s1);
            ans[l][++len[l]] = '=';
            for(int i=0;i<lne;i++) 
                ans[l][++len[l]] = s1[i];
            p = 0;
        }
    }
    if(fl == 1){
        printf(": invalid option -- '%c'",lst);
    }
    else if(p == 1){
        printf(": option requires an argument -- '%c'",lst);
    }
    else{
        for(int i=1;i<=l;i++){
            printf("\n%s",ans[i]);
        }
    }
}