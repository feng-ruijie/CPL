#include<stdio.h>
#include<stdbool.h>
int a[505][505],n,m,p[125005][2][2];
bool checkup(int x,int y){
    if(x < 1) return true;
    if(a[x][y]) return false;
    return checkup(x-1,y);
}
bool checkdown(int x,int y){
 //   printf("%d %d\n",x,y);
    if(x > n) return true;
    if(a[x][y]) return false;
    return checkdown(x+1,y);
}
bool checkleft(int x,int y){
    if(y < 1) return true;
    if(a[x][y]) return false;
    return checkleft(x,y-1);
}
bool checkright(int x,int y){
    if(y > m) return true;
    if(a[x][y]) return false;
    return checkright(x,y+1);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(!p[a[i][j]][0][0]) p[a[i][j]][0][0] = i , p[a[i][j]][0][1] = j;
            else p[a[i][j]][1][0] = i , p[a[i][j]][1][1] = j;
        }
    }
    int tmp = 1;
    while(tmp <= n*m / 2){
        int x = p[tmp][0][0] , y = p[tmp][0][1];
        int xx = p[tmp][1][0] , yy = p[tmp][1][1];
        //up
       /* if(tmp == 9){
            printf("**%d %d %d %d\n",x,y,xx,yy);
        }*/
        if(checkup(x-1,y) && checkup(xx-1,yy)){
            printf("%d ",tmp);
        }
        else if(checkdown(x+1,y) && checkdown(xx+1,yy)){
            printf("%d ",tmp); 
        }
        else if(checkleft(x,y-1) && checkleft(xx,yy-1)){
            printf("%d ",tmp);
        } 
        else if(checkright(x,y+1) && checkright(xx,yy+1)){
            printf("%d ",tmp);
        }
        else{
            tmp ++;
            continue;
        }
        tmp ++;
        a[x][y] = a[xx][yy] = 0;
    }
}