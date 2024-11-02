#include<stdio.h>
#include<string.h>
char s[107][107];
int vectors[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
int n;
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%c",&s[i][j]);
        }
        getchar();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j] == '*') continue;
            int sum = 0; 
            for(int k=0;k<8;k++){
                int x = i+vectors[k][0];
                int y = j+vectors[k][1];
                if(x<1 || x>n || y<1 || y>n) continue;
                if(s[x][y] == '*') sum ++;
            }
            s[i][j] = sum + '0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
}