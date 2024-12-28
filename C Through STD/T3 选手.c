#include <stdio.h>
int a[50001];
int t[50001];
int dp[50001];
int last[50001];
int stack[50001];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i]=i;
    for(int i=1;i<=n;i++)
        if(a[i]==a[i-1]) last[i]=last[i-1];
        else last[i]=i;
    for(int i=1;i<=n;i++) last[i]=last[i]-1;
    for(int i=1;i<=n;i++)
    {
        t[a[i]]=i;
        for(int j=i-1,tmp=1,top=0;j>=0&&tmp*tmp<dp[i];j=last[j])
        {
            if(t[a[j]]!=i)
            {
                if(dp[j]+tmp*tmp<dp[i]) dp[i]=dp[j]+tmp*tmp;
                while(top) last[stack[top]]=j,top--;
                t[a[j]]=i,tmp++;
            }
            else if(j) stack[++top]=j;
            else
                if(tmp*tmp<dp[i]) dp[i]=tmp*tmp;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}