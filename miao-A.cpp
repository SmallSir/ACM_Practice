#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MaxN = 20000;
int T,n,m,prime[MaxN + 5],tot;
bool flag[MaxN + 5];

int solve(int s){
	for(int i = 1; i <= tot;i++){
		if(s == prime[i]) return true;
	}
	return false;
}

int main()
{
	flag[1] = 1; tot = 0;
	for(int i = 2; i <= 20000; i++){
		if(flag[i] == 0) prime[++tot] = i;
		for(int j = 1; j <= tot; j++)
		{
			if(prime[j] * i > 20000) break;
			flag[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&m,&n);
		int k = m * m + n * n;
		if(solve(k)) printf("P\n");
		else{
			int kk = sqrt(k);
			if( sqrt(k) == kk && solve(kk)) printf("P\n");
		    else printf("C\n");
		}
	}
	return 0;
}
