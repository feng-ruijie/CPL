#include<stdio.h>
#include<string.h>
typedef struct Bigint_{
    int bit[10007];
}bigint;
bigint Zero = {};
bigint One = (bigint){.bit[0] = 1};
bigint add(bigint x,bigint y){
    int jw = 0;
    bigint z = Zero; 
    for(int i=0;i<10005;i++){
        z.bit[i] = x.bit[i] + y.bit[i] + jw;
        jw = z.bit[i] / 10;
        z.bit[i] %= 10;
    }
    return z;
}
bigint sub(bigint x,bigint y){
    int jw = 0;
    bigint z = Zero;
    for(int i=0;i<10005;i++){
        z.bit[i] = x.bit[i] - y.bit[i] - jw; 
        if(z.bit[i] < 0){
            jw = 1;
            z.bit[i] += 10; 
        }
        else{
            jw = 0; 
        }
    }
    return z;
}
int eq(bigint x,bigint y){
    for(int i=0;i<105;i++){
        if(x.bit[i] != y.bit[i]){
            return 0;
        }
    }
    return 1;
}
int Compare(bigint x,bigint y){ // x > y 1 | x <= y 0
    int highx=0,highy=0;
    for(int i=105;i>=0;i--){
        if(x.bit[i]){
            highx = i;
            break;
        }
    }
    for(int i=105;i>=0;i--){
        if(y.bit[i]){
            highy = i;
            break;
        }
    }
    if(highx > highy) return 1;
    if(highy > highx) return 0;
    for(int i=highx;i>=0;i--){
        if(x.bit[i] != y.bit[i]) return x.bit[i] > y.bit[i];
    }
    return 1;
}
bigint div2(bigint x){
    bigint z = Zero;
    for(int i=105;i>=0;i--){
        if(x.bit[i] & 1 && i !=0){
            x.bit[i-1] ++;
        }
        z.bit[i] = x.bit[i] / 2;
    }
    return z;
}
bigint mul(bigint x,bigint y){
    bigint z = Zero,p = One;
    while(!eq(y,Zero)){
        if(y.bit[0] & 1){
            z = add(z,p);
        }
        p = add(p,p);
        y = div2(y);
        Printbigint(y);
    }
    return z;
}
bigint div(bigint x,bigint y){
    bigint pow2 = One , z = Zero;
    while(Compare(x,pow2)){
        pow2 = add(pow2,pow2);
    }
    while(!eq(pow2,Zero)){
        if(Compare(x,mul(pow2,y))){ 
            z = add(z,pow2);
            x = sub(x,mul(pow2,y));
        }
        pow2 = div2(pow2);
    }
    return z;
}
bigint Readbigint(char s[]){
    int n = strlen(s);
    bigint a;
    a = Zero;
    for(int i=0;i<n;i++){
        a.bit[i] = s[n-i-1] - '0';
    }
    return a;
}
void Printbigint(bigint x){
    int High = 0;
    for(int i=10005;i>=0;i--){
        if(x.bit[i]){
            High = i;
            break;
        }
    }
    for(int i=High;i>=0;i--){
        printf("%d",x.bit[i]);
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s1[10005],s2[10005],op;
        scanf("%s %c %s",s1,&op,s2);
        bigint a = Readbigint(s1) , b = Readbigint(s2);
        if(op == '+') Printbigint(add(a,b));
        if(op == '-') Printbigint(sub(a,b));
        if(op == '*') Printbigint(mul(a,b));
        if(op == '/') Printbigint(div(a,b));
    }
}