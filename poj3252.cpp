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

int dp[35];
int slove(LL x)
{
	memset(dp,-1,sizeof(dp));
	int pos=0;
	while(x!=0)
	{
		a[++pos]=x%2;
		x/=2;
	}
	return dfs(pos,0,1);
}
int main()
{
	while(cin>>l>>r)
	{
		cout<<slove(r)-solve(l-1)<<endl;
	}
	return 0;
}
