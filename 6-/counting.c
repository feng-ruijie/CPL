#include <stdio.h>
#include <stdbool.h>
char c[105][105],n,m;

bool checkleft(int x,int y,int len){
    int sum = 0;
    x++;
    while(c[x][y] == '\\'){
        sum ++;
        x++ , y++;
        if(sum == len) return true;
    }
    return false;
}
bool checkright(int x,int y,int len){
    int sum = 0;
    x++;
    while(c[x][y] == '/'){
        sum ++;
        x++ , y--;
        if(sum == len) return true;
    }
    return false;
}
int main(){
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%c",&c[i][j]);
        }
        getchar();
    }
    int ans = 0; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
          //  printf("%c",c[i][j]);
            if(c[i][j] == '/' && c[i][j+1] == '\\'){
                int x1 = i , y1 = j , x2 = i , y2 = j+1 , len = 1;
                while(c[x1][y1] == '/' && c[x2][y2] == '\\'){
                    if(checkleft(x1,y1,len) && checkright(x2,y2,len)){
                        ans ++;
                       // printf("%d %d %d %d %d\n",x1,y1,x2,y2,len);
                    }
                    len ++;
                    x1 ++ , y1 -- , x2++ , y2 ++;
                }
            }
        }
      //  printf("\n");
    }
    printf("%d",ans);
}