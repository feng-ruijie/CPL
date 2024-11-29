#include<stdio.h>
#include<malloc.h>
#include<string.h>
char opp(char p){
    if(p == 'A') return 'B';
    return 'A';
}
int main(){
    char *s = malloc(sizeof(char)*1005) , *s1 = malloc(sizeof(char)*1005);
    int n;
    scanf("%d\n",&n);
    scanf("%s",s);
    int len = strlen(s);
    for(int i=1;i<=n;i++){
        for(int j=0;j<len;j++){
            *(s1+j) = *(s+j);
        }
        printf("%s\n",s1);
        for(int j=0;j<len;j++){
            char p = *(s1+j);
            
            if(p == 'A' || p == 'B'){
                int sum = 0;
                if(j-3>=0 && *(s1+j-3) == p) sum++;
                if(j-2>=0 && *(s1+j-2) == p) sum++;
                if(j-1>=0 && *(s1+j-1) == p) sum++;
                if(j+1<len && *(s1+j+1) == p) sum++;
                if(j+2<len && *(s1+j+2) == p) sum++;
                if(j+3<len && *(s1+j+3) == p) sum++;

                if(j-3>=0 && *(s1+j-3) == opp(p)) sum=0;
                if(j-2>=0 && *(s1+j-2) == opp(p)) sum=0;
                if(j-1>=0 && *(s1+j-1) == opp(p)) sum=0;
                if(j+1<len && *(s1+j+1) == opp(p)) sum=0;
                if(j+2<len && *(s1+j+2) == opp(p)) sum=0;
                if(j+3<len && *(s1+j+3) == opp(p)) sum=0;
                if(sum >= 5 || sum <= 1){
                    *(s+j) = '.';
                }
                else *(s+j) = p;
            }
            else{
                int suma = 0 , sumb = 0;
                char q = 'A';
                if(j-3>=0 && *(s1+j-3) == q) suma++;
                if(j-2>=0 && *(s1+j-2) == q) suma++;
                if(j-1>=0 && *(s1+j-1) == q) suma++;
                if(j+1<len && *(s1+j+1) == q) suma++;
                if(j+2<len && *(s1+j+2) == q) suma++;
                if(j+3<len && *(s1+j+3) == q) suma++;

                if(j-3>=0 && *(s1+j-3) == opp(q)) sumb++;
                if(j-2>=0 && *(s1+j-2) == opp(q)) sumb++;
                if(j-1>=0 && *(s1+j-1) == opp(q)) sumb++;
                if(j+1<len && *(s1+j+1) == opp(q)) sumb++;
                if(j+2<len && *(s1+j+2) == opp(q)) sumb++;
                if(j+3<len && *(s1+j+3) == opp(q)) sumb++;

                if(suma >= 2 && suma <= 4 && sumb == 0){
                    *(s+j) = 'A';
                }
                else if(sumb >= 2 && sumb <= 4 && suma == 0){
                    *(s+j) = 'B';
                }
                else *(s+j) = '.';
            }
        }
    }
    printf("%s",s);
}