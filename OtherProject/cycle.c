#include <stdio.h>
#include <string.h>

char s[100005][21];
int nxt[100005] , p[100005];
int n;
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%s %d",s[i],&nxt[i]);
        getchar();
    }
    for(int i=1;i<=n;i=nxt[i]){
        if(p[i]){
            printf("%s\n",s[i]);
            return 0;
        }
        p[i] = 1; 
        if(nxt[i] > n||nxt[i] < 1) break;
    }
    printf("-1");
}

