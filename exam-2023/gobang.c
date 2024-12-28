#include<stdio.h>
int w1 = 0, w0 = 0 , n , b1 = 0 , b0 = 0;
int f[4][2] = {{1,0},{0,1},{1,-1},{1,1}};
char c[25][25];
char check(int i,int j){
    int max = 1;
    int ni = i,nj = j;

    for(int k=0;k<4;k++){
        int dx = f[k][0],dy = f[k][1],sum=0;
        //printf("%d",k);
        while(ni >= 0 && nj >= 0 && ni < 20 && nj < 20){
            if(c[ni][nj] == c[i][j]){
                sum ++;
                ni += dx; 
                nj += dy;
            }
            else break;
        }
        ni = i , nj = j;
        while(ni >= 0 && nj >= 0 && ni < 20 && nj < 20){
            if(c[ni][nj] == c[i][j]){
                sum ++;
                ni -= dx; 
                nj -= dy;
            }
            else break;
        }
        if(sum-1 > max) max = sum-1;
    }
    if(i == 4 && j == 1) printf("%d ",max);
    if(max >= 5) return 1;
    return 0; 
}
int main(){
    scanf("%d",&n);
    getchar();
    while(n--){
        for(int i = 0;i < 20;i++){
            for(int j = 0;j < 20;j++){
                scanf("%c",&c[i][j]);
            }
            getchar();
        }
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){ //在这个位置下白棋
                if(c[i][j] != '_') continue;
                c[i][j] = '*';
                if(check(i,j)){
                 //   printf("%d %d",i,j);
                    printf("Lose\n");
                    goto end;
                }
                c[i][j] = '_';
            }
        }
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                int p = 0;
                if(c[i][j] != '_') continue;
                c[i][j] = '*';
                for(int ii=0;ii<20;ii++){
                    for(int jj=0;jj<20;jj++){
                        if(c[ii][jj] != '_') continue;
                        c[ii][jj] = '#';
                        if(check(ii,jj)){
                            p = 1;
                            break;
                        }
                        c[ii][jj] = '_';
                    }
                }
                //如果p为0，说明存在白棋下一个位置，黑棋怎么下都赢不了
                if(p == 0){
                    printf("Not Sure\n");
                    goto end;
                }
                c[i][j] = '_';
            }
        }
        printf("Win\n");
        end :
    }
}