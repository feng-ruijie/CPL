#include<bits/stdc++.h>

using namespace std;
int read(){
	int f = 1 , s = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}

int main(){
	struct _timeb T;
	_ftime(&T);
	srand(T.millitm);
	int n = rand() % 15 , m = rand() % 15 , k = rand() % min(n,m);
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x = rand() % 20;
			if(rand()%5 == 0) x = -x; 
			printf("%d ",x);  
		}
		printf("\n");
	}
	
}

