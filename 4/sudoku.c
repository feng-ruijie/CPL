#include<stdio.h>
#include<stdbool.h>
int a[12][12],n=9;
bool p[12];
int main(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!p[a[i][j]])
            p[a[i][j]] = 1;
            else{
                printf("NO");
                return 0;
            }
        }
        for(int j=1;j<=n;j++){
            p[j] = 0;
        }
    }
    for(int i=1;i<=n;i++){ //列
        for(int j=1;j<=n;j++){ //行
            if(!p[a[j][i]])
            p[a[j][i]] = 1;
            else{
                printf("NO");
                return 0;
            }
        }
        for(int j=1;j<=n;j++){
            p[j] = 0;
        }
    }
    for(int i=1;i<=n;i+=3){
        for(int j=1;j<=n;j+=3){
            for(int k=i;k<3+i;k++){
                for(int w=j;w<3+j;w++){
                    if(!p[a[k][w]])
                    p[a[k][w]] = 1;
                    else{
                        printf("NO");
                        return 0;
                    }
                }
            }
            for(int k=1;k<=n;k++){
                p[k] = 0;
            }
        }
    }
    printf("YES");
    return 0; 
}