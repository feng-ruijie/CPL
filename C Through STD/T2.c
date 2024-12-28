#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int ans[2002][2002],b[2002][2002],xx[2002][2002],yy[2002][2002],s[2002][2002],w;
int newx[2002][2002],newy[2002][2002];
int n,m,q;
int read(){
	int f = 1 , s = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}
int max(int x,int y){
    return x>y?x:y;
}
int min(int x,int y){
    return x<y?x:y;
}
void rotate(){
    w = max(n,m);
    int k = w+1; //确定一个“顶点
    xx[1][k] = 1, yy[1][k] = 1; 
    newx[1][1] = 1,newy[1][1] = k;
    //填充上半部分
    for(int i=2;i<=w;i++){
        int start = k-(i-1),x=1,y=i; //这一行要填i个数
        for(int j=start;j;j+=2){
            if(x <= n && y <= m && x >= 1 && y >= 1){
                xx[i][j] = x , yy[i][j] = y;
                newx[x][y] = i , newy[x][y] = j;
            }
            x++,y--;
            if(y <= 0) break;
        }
    }
    //填充下半部分
    for(int i=w-1;i>=1;i--){
        int start = k-(i-1),x=w+1-i,y=w; //这一行要填i个数
        for(int j=start;j;j+=2){
            if(x <= n && y <= m && x >= 1 && y >= 1){
                xx[2*w-i][j] = x , yy[2*w-i][j] = y;
                newx[x][y] = 2*w-i , newy[x][y] = j;
            }
            x++,y--;
            if(y <= 0) break;
        }
    }
}
signed main(){
    n = read() , m = read() , q = read();
    //拓充图
    rotate();//填写每个新图的坐标对应每个原图的坐标

    while(q--){
        int x,y,d;
        x = read() , y = read() , d = read();
        int newx1 = max(newx[x][y]-d,1),newy1=max(newy[x][y]-d,1);
        int newx2 = min(newx[x][y]+d,2*w+1),newy2 = min(newy[x][y]+d,2*w+1);
        b[newx1][newy1] ++;
        b[newx2+1][newy2+1] ++;
        b[newx1][newy2+1] --;
        b[newx2+1][newy1] --;
    }
    for(int i=1;i<=2*w+1;i++){
        for(int j=1;j<=2*w+1;j++){
            s[i][j] = b[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            ans[xx[i][j]][yy[i][j]] = s[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
