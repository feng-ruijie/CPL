#include<stdio.h>
#include<string.h>
int T;

int main(){
    scanf("%d",&T);
    while(T--){
        char s[17];
        scanf("%s",s);
        int n = strlen(s);
        printf("%d",n);
        short int p = 0;
        for(int i=0;i<n;i++){
            if(s[i]!='1'&&s[i]!='Z'&&s[i]!='0'){
                printf("Radix Error\n");
                p=1;
            }
        }
        if(p == 1){
            continue;
        }
        long long ans = 0 , sum = 1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') ans += sum;
            if(s[i]=='Z') ans -= sum;
            sum = sum * 3;
        }
        printf("%lld\n",ans);
    }
}