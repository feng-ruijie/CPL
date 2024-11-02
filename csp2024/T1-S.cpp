#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 7;
int a[N],n,b[N];
int main(){
  //  freopen("a1.in","r",stdin);
  //  freopen("a1.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int sum = 1, tot = 0;
    for(int i=2;i<=n;i++){
        if(a[i] == a[i-1]) sum ++;
        else{
            b[++tot] = sum;
            sum = 1;
        }
    }
    b[++tot] = sum;
    int ans = n,lst = b[1];
    for(int i=2;i<=tot;i++){
        if(b[i] >= lst){
            ans -= lst;
            lst = b[i]; //lst 被清空了
        }
        else{
            ans -= b[i]; //清了b_i
        }
    }
    printf("%d",ans);
}