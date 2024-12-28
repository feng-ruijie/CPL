## T3 大珠小珠落玉盘 题解
最简单的 $O(n^2)$ dp是很好想的 ， $dp[i] = min(dp[i],dp[j]+sum(i,j));$ 其中$sum(i,j)$为$i,j$之间不同数的个数
 
考虑到能转移到的状态有限，如果位置 $i,j$ 之间有 $k$ 个不一样的数，且$k^2 >= n$，那么把$i,j$之间分为一组显然是不明智的。

如果位置 $i,j$ 之间有 $k$ 个不一样的数，且位置 $i,t$ 之间有 $k$ 个不一样的数，$j < t$ 那么将$ i,t $分为一组是更好的选择。 

我们可以维护一个能转移到的状态的集合(大小为$\sqrt{n}$)，随着遍历，对这个集合进行增减。这样可以写一个dp, $dp[i]=j$ 表示从 $1-i$ 位置的最小不和谐值为 $j$

还有另外一种思路，考虑答案越大，能分组到的最大下标越大。dp[i] = j 表示, 答案为i时，能分组到最大下标是j。可以参考下面的代码理解第二种思路。两种思路的时间复杂度都是$O(n\sqrt{n})$。

```c
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
				if(p[a[j]]==0 && cnt==k)break; //p 是一个桶
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
