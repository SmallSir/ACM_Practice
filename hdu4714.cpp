#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

const int MAXN = 1000000;
vector<int> tu[MAXN+5];
int dp[MAXN+5];
int n;
int dfs(int x)  
{  
   memset(check,0,sizeof(check));
   queue<int> qua;
   qua.push(x);
   dp[x]=1;
   int MAX=-1;
   int ind = 0;
   int tot=0;
   while(!qua.empty())
   {
   	   int k = qua.front();
   	   qua.pop();
   	   for(int i=0;i<tu[k].size();i++)
	   {
	   	   ind = tu[k][i];
	   	   if(dp[ind])
	   	   	   continue;
			dp[ind]=dp[k]+1;
		//	cout<<check[k]<<" "<<check[ind]<<endl;
			qua.push(ind);
			if(dp[ind]>MAX)
			{
				MAX =dp[ind];
				tot = ind;
			}
	   }
   }
   return tot;
} 
void dfss(int son,int fa)
{
	int i,k;
	check[son]=1;
	for(i=0;i<tu[son].size();i++)
	{
		int k=tu[son][i];
		if(k==fa||check[k]==1)
			continue;
		dfss(k,son);
		dp[son]+=dp[k]+1;
	}
	if(dp[son]!=0)
		dp[son]--;
}
int main()
{
	int i,x,y,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(tu,0,sizeof(tu));
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			tu[x].push_back(y);
		}
		int k=dfs(1);
		k=dfs(k);
		memset(dp,0,sizeof(dp));
		dfss(k,0);
		printf("%d\n",dp[k]*2+1);
	}
 return 0;
}
