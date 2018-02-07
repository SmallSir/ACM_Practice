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

int dp[20][10],aa,bb;
int a[10];
int dfs(int k,int flag,int Top)//k位,flag是否前位置是6，Top是否达到上界
{
	int n,ans;
	if(k<=0) return 1;
	if(Top == 0 && dp[k][flag]!=-1) return dp[k][flag];//记忆化
	if(Top == 1)
		n = a[k];
	else
		n = 9;
	ans=0;
	for(int i=0;i<=n;i++)
	{
		if(i==4||i==2&&flag)
			continue;
		else
			ans+=dfs(k-1,i==6,Top&&i==n);
	}
	if(Top==0)dp[k][flag]=ans;//记忆化
	return ans;
}
int solve(int x)
{
	memset(dp,-1,sizeof(dp));
	int pos = 0;
	while(x!=0)
	{
		a[++pos]=x%10;
		x/=10;
	}
	return dfs(pos,0,1);
}
int main()
{
	while(cin>>aa>>bb)
	{
		if(aa==0&&bb==0)
			return 0;
		cout<<solve(bb)-solve(aa-1)<<endl;
	}
	return 0;
}
