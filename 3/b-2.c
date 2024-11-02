#include<stdio.h>
#include<string.h>
int check(char s[]){
    int n = strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]!='-'&&(s[i]-'0' < 0 || s[i]-'0' > 9)){
            return 1;
        }
    }
    return 0;
}
int Pro(char s[]){
    int n = strlen(s),ans = 0,p=1;
    for(int i=0;i<n;i++){
        ans *= 10;
        if(s[i] == '-'){
            p = -p;
        }
        else{
            ans += s[i]-'0';
        }
    }
    return ans * p;
}
int main(){
  //  freopen("a1.in","r",stdin);
   // freopen("a1.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        char a[25];
        scanf("%s",a);
        if(check(a)){
            printf("Radix Error\n");
            continue;
        }
        n = Pro(a);
        int a1[25];
        char a2[25];
        for(int i=0;i<=21;i++){
            a1[i] = 0;
        }
        int p = 1 , tot = 0;
        if(n == 0){
            printf("0\n");
            continue;
        }
        if(n < 0){
            p = -1;
            n = -n;
        }
        while(n){
            a1[++tot] = n%3;
            n/=3;
        }
        int jw = 0;
        for(int i=1;i<=tot;i++){
            int dw = jw + a1[i];
            if(dw >= 3){
                jw = 1;
                a2[i] = '0';
            }
            if(dw == 0){
                a2[i] = '0';
                jw = 0;
            } 
            if(dw == 1){
                a2[i] = '1';
                jw = 0;
            } 
            if(dw == 2){
                a2[i] = 'Z';
                jw = 1;
            } 
        }
        if(jw == 1){
            a2[++tot] = '1';
        }
        if(p == -1){
            for(int i=1;i<=tot;i++){
                if(a2[i] == 'Z') a2[i] = '1';
                else if(a2[i] == '1') a2[i] = 'Z';
            }
        }
        for(int i=tot;i>=1;i--){
            printf("%c",a2[i]);
        }
        printf("\n");    
    }
  //  fclose(stdin);
  //  fclose(stdout);
    return 0;
}