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

int a[100005];
int vis[100005];
vector<int> tu[100005];
int de[100005],b[100005];
int n;
double sum,cnt;
void dfs(int son,int fa,int deep)
{
	bool flag=0;
	int i,k;
	for(i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(vis[k]||k==fa)
			continue;
		flag=1;
		vis[k]=1;
		dfs(k,son,deep+1);
	}
	if(!flag)
	{
		de[i]=deep;
		sum+=deep;
	}
}
int main()
{
	int i,n,x,y;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
		a[x]++;
		a[y]++;
	}
	sum=0;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	dfs(1,0,0);
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			b[de[i]]++;
			cnt++;
		}
	}
	double ans;
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans=(ans+(b[i]*1.0)/(sum*1.0)*(i*1.0))*1.0;
	}
	if(n == 1) printf("1.000000000000000\n");
	else
		printf("%0.15lf\n",ans);
 return 0;
}
