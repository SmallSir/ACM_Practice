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
const int inf = 0x3f3f3f3f;
int n,p;
vector<int> tu[155];
int dp[155][155],MIN,sum[155];
int father[155];
void dfs(int son,int fa)
{
	int i,j,k,u;
	sum[son] = 1;///注意这里
    if(tu[son].size()==0)
    {
        dp[son][1] = 0;
        sum[son] = 1;
        return ;
    }
	for(i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(k == fa)
			continue;
		dfs(k,son);
		sum[son]+=sum[k];
		for(int j = sum[son];j>0;j--)
        {
            for(int s = 1; s < j ; s++ )
            {
                dp[son][j] = min(dp[son][j-s]+dp[k][s]-1,dp[son][j]);
            }
        }
	}
}
int main()
{
	int x,y,i;
	while(cin>>n>>p)
	{
		memset(dp,inf,sizeof(dp));
		memset(tu,0,sizeof(tu));
		memset(father,0,sizeof(father));
		for(i=1;i<n;i++)
		{
			cin>>x>>y;
			tu[x].push_back(y);
			father[x]++;
		}
		for(i=1;i<=n;i++)
			dp[i][1]=father[i];
		dfs(1,0);
		MIN=dp[1][p];
		for(i=2;i<=n;i++)
		{
			MIN=min(MIN,dp[i][p]+1);//+1原因是若是不以1为跟节点，则需要+1
		}
		cout<<MIN<<endl;
		
	}
	return 0;
}
