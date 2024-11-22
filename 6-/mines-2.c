//600*600*600的int数组占408MB,char占102MB
#include<stdio.h>
char s[602][602][602];
int n,x,y,z;
int v[][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int main(){
    scanf("%d",&n);
    getchar();
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                scanf("%c",&s[i][j][k]);
                if(s[i][j][k] == '?'){
                    x = i , y = j , z = k;
                }
            }
        }
    }
    int p = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(s[i][j][k] == '?' || (s[i][j][k] >= '0' && s[i][j][k] <= '9')){
                    int count = 0;
                    for(int w=0;w<6;w++){
                        int dx = i + v[w][0] , dy = j + v[w][1] , dz = k + v[w][2];
                        if(s[dx][dy][dz] == '*'){
                            count++;
                        }
                    }
                 //   printf("%d %d %d %d\n",i,j,k,count);
                    if(s[i][j][k] == '?'){
                        s[i][j][k] = count + '0';
                    }
                    else{
                        if(count != s[i][j][k] - '0'){
                            p = 1;
                            goto end;
                        }
                    }
                }
            }
        }
    }
    end:
    if(p == 0){
        printf("valid\n");
        printf("%c",s[x][y][z]);
        return 0;
    }
    s[x][y][z] = '*';
    int flag = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(s[i][j][k] >= '0' && s[i][j][k] <= '9'){
                    int count = 0;
                    for(int w=0;w<6;w++){
                        int dx = i + v[w][0] , dy = j + v[w][1] , dz = k + v[w][2];
                        if(s[dx][dy][dz] == '*'){
                            count++;
                        }
                    }
                    if(count != s[i][j][k] - '0'){
                        if(!flag){
                            printf("invalid\n");
                            flag = 1;
                        }
                        printf("%d %d %d\n",i,j,k);
                    }
                }
            }
        }
    }
}