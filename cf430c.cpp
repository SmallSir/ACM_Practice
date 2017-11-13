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

vector<int> tu[200005];
int b[200005],a[200005],check[200005],cnt[200005];
int n;
int gcd(int x, int y){
	if(y == 0) return x;
	else return gcd(y, x % y);
}
void dfs(int son,int fa,int deep)
{
	int i,flag;
	b[son]=gcd(a[son],b[fa]);
	check[son]=b[fa];
	for(i=1;i*i<=a[son];i++)
	{
		if(a[son]%i==0)
		{
			flag=i;
			if(cnt[flag]>=deep-2) check[son]=max(flag,check[son]);
			flag=a[son]/i;
			if(cnt[flag]>=deep-2) check[son]=max(flag,check[son]);
			if(i*i==a[son])
				cnt[i]++;
			else
				cnt[i]++,cnt[a[son]/i]++;
		}
	}
	for(i=0;i<tu[son].size();i++)
	{
		int k=tu[son][i];
		if(k==fa)
			continue;
		dfs(k,son,deep+1);
	}
	for(i=1;i*i<=a[son];i++)
	{
		if(a[son]%i==0)
		{
			if(i*i==a[son])
				cnt[i]--;
			else
				cnt[i]--,cnt[a[son]/i]--;
		}
	}
}
int main()
{
	int x,y,i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	dfs(1,0,1);
	for(i=1;i<=n;i++) cout<<check[i]<<" ";
	cout<<endl;
}
