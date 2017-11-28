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

int a[30];
int f[40000005],n,m,ans;
void dfs(int c,int boom,int cnt)
{
	if(c>n)
	{
		int k=f[cnt];
		ans=min(ans,max(k,boom));
		return;
	}
	dfs(c+1,boom,cnt|a[c]);
	dfs(c+1,boom+1,cnt);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char s;
	int i,j;
	f[0]=0;
	for(i=1;i<=(1<<25);i++)
	{
		f[i]=f[i ^(i&(-i))]+1;
	}
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>s;
			if(s=='*')
				a[i] |=(1<<(j-1));
		}
	}
	ans=1<<30;
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
