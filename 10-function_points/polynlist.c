#include<stdio.h>
#include<string.h>
int n,m;
char s[15];
int a[10005],b[10005];
int ans1[20005] , ans2[20005] , ans3[20005]; 
void calculate1(){
    for(int i=n;i>=0;i--){
        ans1[i]=a[i];
    }
    for(int i=m;i>=0;i--){
        ans1[i]+=b[i];
    }
}
void calculate2(){
    for(int i=n;i>=0;i--){
        ans2[i]=a[i];
    }
    for(int i=m;i>=0;i--){
        ans2[i]-=b[i];
    }
}
void calculate3(){
    for(int i=n;i>=0;i--){
        for(int j=n;j>=0;j--){
            ans3[i+j] += a[i] * b[j]; 
        }
    }
}
void print(int b[]){
    int isf = 0;
    for(int i=n+m;i>=0;i--){
        if(b[i] == 0) continue;
        if(b[i] > 0 && isf != 0) printf("+");
        if(b[i] < 0){
            printf("-");
            b[i] = -b[i];
        }
        if(i==0||(b[i]!=1)) printf("%d",b[i]);
        isf = 1;
        if(i >= 2){
            printf("%s^%d",s,i);
        }
        if(i == 1){
            printf("%s",s);
        }
    }
    printf("\n");
}
int main(){
    freopen("b1.in","r",stdin);
    freopen("b1.out","w",stdout);
    memset(ans1,0,sizeof(ans1));
    memset(ans2,0,sizeof(ans2));
    memset(ans3,0,sizeof(ans3));
    scanf("%d %d\n",&n,&m);
    scanf("%s\n",s);
    for(int i=n;i>=0;i--){
        scanf("%d",&a[i]);
    }
    for(int i=m;i>=0;i--){
        scanf("%d",&b[i]);
    }
    calculate1();
    calculate2();
    calculate3();
    print(ans1);
    print(ans2);
    print(ans3); 
    return 0; 
}