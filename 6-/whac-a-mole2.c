#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define int long long
int a[1202][1202],b[1202][1202],xx[1202][1202],yy[1202][1202],s[1202][1202],ans[801*801][2],w;
bool p[2001][2001];
int ansN=0,maxValue=-999999999,n,m,k;
int max(int x,int y){
    return x>y?x:y;
}
int min(int x,int y){
    return x<y?x:y;
}
void rotate(){
    w = max(n,m);
    int k = w+1; //确定一个“顶点“
    b[1][k] = a[1][1];
    xx[1][k] = 1, yy[1][k] = 1; 
    //填充上半部分
    for(int i=2;i<=w;i++){
        int start = k-(i-1),x=1,y=i; //这一行要填i个数
        for(int j=start;j;j+=2){
            b[i][j] = a[x][y];
            if(x <= n && y <= m && x >= 1 && y >= 1){
                xx[i][j] = x , yy[i][j] = y;
            }
            x++,y--;
            if(y <= 0) break;
        }
    }
    //填充下半部分
    for(int i=w-1;i>=1;i--){
        int start = k-(i-1),x=w+1-i,y=w; //这一行要填i个数
        for(int j=start;j;j+=2){
            b[2*w-i][j] = a[x][y];
            if(x <= n && y <= m && x >= 1 && y >= 1){
                xx[2*w-i][j] = x , yy[2*w-i][j] = y;
            }
            x++,y--;
            if(y <= 0) break;
        }
    }
}
signed main(){
    scanf("%lld %lld %lld",&n,&m,&k);
    //拓充图
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    rotate();
    for(int i=1;i<=2*w+1;i++){
        for(int j=1;j<=2*w+1;j++){
            s[i][j] = b[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    int sum = -999999999, tot = 0;
    for(int i=1;i<=2*w+1;i++){
        for(int j=1;j<=2*w+1;j++){
            if(!xx[i][j]) continue;
            int x1 = max(i-k,1),x2 = min(i+k,2*w+1),y1 = max(j-k,1),y2 = min(j+k,2*w+1);
            int tmp =s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1]; 
            if(sum < tmp){
                tot = 0;
                sum = tmp;
                ans[++tot][0] = xx[i][j];
                ans[tot][1] = yy[i][j];
            }
            else if(sum == tmp){
               ans[++tot][0] = xx[i][j];
                ans[tot][1] = yy[i][j]; 
            }  
        }
    }
    printf("%lld %lld\n",sum,tot);
    for(int i=1;i<=tot;i++){
        printf("%lld %lld\n",ans[i][0],ans[i][1]);
    }
}
