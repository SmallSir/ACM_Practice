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
	int tot,index,sum;
}a[100005];
int n,i,m,j,k,sum,ans;;
string str[100005],s;
bool cmp(point a,point b)
{
	if(double(a.tot/a.sum) == double(b.tot/b.sum))
		return a.tot>b.tot;
	return double(a.tot/a.sum) >double(b.tot/b.sum);
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>str[i];
	for(i=1;i<=n;i++)
	{
		a[i].tot=0;
		m = str[i].length();
		for(j=0;j<=m;j++)
		{
			if(str[i][j]=='s')
				a[i].tot++;
		}
		a[i].index = i;
		a[i].sum = m;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)
	{
		k=a[i].index;
		s+=str[k];
	}
	m=s.length();
	ans=sum=0;
	for(i=0;i<m;i++)
	{
		if(s[i]=='s')
			ans++;
		else
			sum+=ans;
	}
	cout<<sum<<endl;
	return 0;
}
