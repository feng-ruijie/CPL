#include<stdio.h>
#include<math.h>
int reverse(int n){
    int ans = 0;
    while(n){
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}   
int isprime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int main(){
    int n,ans = 0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int x = reverse(i);
        if(isprime(x) && isprime(i)) ans ++;
    }
    printf("%d\n",ans); 
}