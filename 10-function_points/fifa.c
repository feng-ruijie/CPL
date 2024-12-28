#include<stdio.h>
#include<stdlib.h>

typedef struct Player{
    char name[30];
    int score[3];
}team;
team a[1005];
int cmp1(const void *a , const void *b){
    team *x = (team *)a; 
    team *y = (team *)b;

    if(x->score[0] > y->score[0]) return -1;
    if(x->score[0] < y->score[0]) return 1;
    return 0;
}
int cmp2(const void *a,const void *b){
    team x = *(team *)a;
    team y = *(team *)b; 
    if(x.score[1] > y.score[1]) return -1;
    if(x.score[1] < y.score[1]) return 1;
    return 0;
}
int cmp3(const void *a,const void *b){
    team x = *(team *)a;
    team y = *(team *)b; 
    if(x.score[2] > y.score[2]) return -1;
    if(x.score[2] < y.score[2]) return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%s\n",a[i].name);
        for(int j=0;j<11;j++){
            char s[30];
            scanf("%s",&s);
            for(int k=0;k<3;k++){
                int x;
                scanf("%d",&x);
                a[i].score[k]+=x;
            }
            getchar();
        }
        //printf("%s %d %d %d\n",a[i].name,a[i].score[0],a[i].score[1],a[i].score[2]);
    }
    qsort(a,n,sizeof(team),cmp1);
    for(int i=0;i<n;i++){
        printf("%s ",a[i].name);
    }
    printf("\n");
    qsort(a,n,sizeof(team),cmp2);
    for(int i=0;i<n;i++){
        printf("%s ",a[i].name);
    }
    printf("\n");
    qsort(a,n,sizeof(team),cmp3);
    for(int i=0;i<n;i++){
        printf("%s ",a[i].name);
    }
}