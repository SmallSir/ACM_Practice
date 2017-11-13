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

LL ans[100005];
vector<int> tu[100005];
int a[100005];
int n,T;
void dfs(int son,int fa)
{
	int k;
	int cnt;
	if(son==1)
		cnt=1+tu[son].size();
	else
		cnt=1+tu[son].size()-1;
	//cout<<cnt<<endl;
	for(int i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(k==fa)
			continue;
		cnt+=tu[k].size()-1;
		dfs(k,son);
		ans[son]+=ans[k];
	}
	ans[son]+=cnt*a[son];
}
int main()
{
	int i,x,y;
	scanf("%d",&T);
	//cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		memset(tu,0,sizeof(tu));
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			//cin>>x>>y;
			tu[x].push_back(y);
			tu[y].push_back(x);
		}
		dfs(1,0);
		for(i=1;i<=n;i++)
			printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}
