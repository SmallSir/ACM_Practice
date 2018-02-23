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

struct point
{
	char x,y;
}a[100005];
int fa[100005];
int n,sum;
char s[100005],str[100005];
int find(int x)
{
	if(fa[x]==x)
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void join(int flag)
{
	int x=find(str[flag]-'a'+1);
	int y=find(s[flag]-'a'+1);
	if(x!=y)
	{
		a[++sum].x=str[flag];
		a[sum].y=s[flag];
		fa[y]=x;
	}
}
int main()
{
	int i;
	for(i=1;i<=26;i++)
		fa[i]=i;
	cin>>n;
	sum=0;
	for(i=1;i<=n;i++)
		cin>>str[i];
	for(i=1;i<=n;i++)
		cin>>s[i];
	for(i=1;i<=n;i++)
	{
		if(s[i]==str[i])
			continue;
		join(i);
	}
	cout<<sum<<endl;
	for(i=1;i<=sum;i++)
	{
		cout<<a[i].x<<" "<<a[i].y<<endl;
	}
	return 0;
}
