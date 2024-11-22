#include<stdio.h>
#include<math.h>
int a[801][801],s[801][801],ans[801*801][2];
int ansN=0,maxValue=-999999999,n,m,k;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    //拓充图，1~k部分存0，k+1~k+n存值,拓充到n+2k为止
    for(int i=1+k;i<=n+k;i++){
        for(int j=1+k;j<=m+k;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n+2*k+1;i++){
        s[i][0] = 0;
        for(int j=1;j<=m+2*k+1;j++){
            s[i][j] = a[i][j] + s[i][j-1];
        }
    }
    for(int i=k+1;i<=n+k;i++){
        for(int j=k+1;j<=m+k;j++){
            int sum = 0;
            for(int w=i-k;w<=i+k;w++){
                int len = k - abs(w-i); //距离i的偏移量
                int l = j - len , r = j + len;
                sum += s[w][r] - s[w][l-1];
            }
            if(sum > maxValue){
                maxValue = sum;
                ansN = 1; 
                ans[1][0] = i , ans[1][1] = j;
            }
            else if(sum == maxValue){
                ansN++;
                ans[ansN][0] = i , ans[ansN][1] = j;
            }
        }
    }
    printf("%d %d\n",maxValue,ansN);
    for(int i=1;i<=ansN;i++){
        printf("%d %d\n",ans[i][0]-k,ans[i][1]-k);
    }
}
