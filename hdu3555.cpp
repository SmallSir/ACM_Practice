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

LL dp[20][3];
int a[20];
LL dfs(int k,int flag,bool Top)
{
	int n,i;
	if(k<=0) return flag == 2;
	if(Top ==0 && dp[k][flag]!=-1)
		return dp[k][flag];
	if(Top == 0)
		n = 9;
	else
		n = a[k];
	LL ans=0;
	for(i=0;i<=n;i++)
	{
		int cnt = flag;
		if(flag == 1&&i==9)
			cnt =2;
		else if(flag == 0&&i==4)
			cnt=1;
		else if(flag==1&&i!=4)
			cnt=0;
		ans+=dfs(k-1,cnt,Top&&i==n);
	}
	if(Top==0)
		dp[k][flag] = ans;
	return ans;
}
LL solve(LL x)
{
	int pos=0;
	while(x!=0)
	{
		a[++pos]=x%10;
		x/=10;
	}
	return dfs(pos,0,1);
}
int main()
{
	int T;
	LL n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(dp,-1,sizeof(dp));
		cout<<solve(n)<<endl;
	}
	return 0;
}
