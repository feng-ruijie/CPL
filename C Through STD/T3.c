#include<stdio.h>

const int N=5e4+10,M=225;

int n,m,a[N],w[N][M],dp[N];

int cnt,pos,p[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int k=1;k*k<=n;k++){
		
		cnt=0;
		memset(p,0,sizeof(p));
		int j=1;
		for(int i=1;i<=n;i++){
			while(1){
				if(p[a[j]]==0 && cnt==k)break; //p_i是一个桶
				p[a[j]]++;
				if(p[a[j]]==1) cnt++;
				j++;
				if(j==n+1)break;
			}
			if(j==n+1){
				for(int tmp=i;tmp<=n;tmp++)
					w[tmp][k]=n; //tmp开始，出现第k个不相同的数的最大位置
				break;
			}
			w[i][k]=j-1; //i开始，出现k个不相同的数的最大位置
			p[a[i]]--;
			if(p[a[i]]==0) cnt--;
		}
	}
	
	//dp[i] = j , 答案为i时，能到达的最大下标是j
	for(int i=1;i<=n;i++)
		for(int j=1;j*j<=i;j++){
			
			int k=i-j*j; //价值为i，与价值为k最大下标之间有j*j个不同的数
			dp[i]=max(dp[i],w[dp[k]+1][j]); //从dp[k]+1开始，出现第j个不相同的数的最大位置
		}
	
	for(int i=1;i<=n;i++)
		if(dp[i]==n){
			printf("%d",i);
			return 0;
		}
	
	return 0;
}
