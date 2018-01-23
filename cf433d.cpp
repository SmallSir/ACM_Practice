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
	int d,s,e,c;
}a[1000005];
LL s[1000005],e[1000005],ans,sum;
int i,n,m,k,j,flag,x,MAX;
int check[1000005];
bool cmp(point x,point y){return x.d<y.d;}

int main()
{
	cin>>n>>m>>k;
	MAX =0;
	for(i=1;i<=m;i++)
	{
		cin>>a[i].d>>a[i].s>>a[i].e>>a[i].c;
		MAX=max(MAX,a[i].d);
	}
	sort(a+1,a+1+m,cmp);
	flag=n;
	for(i=1;i<=m;i++)
	{
		if(a[i].s)
		{
			if(check[a[i].s]==0)
			{
				check[a[i].s]=a[i].c;
				flag--;
				if(!flag)//说明截止到当前，他们都能飞到0城市
				{
					for(j=1;j<=n;j++)
						s[a[i].d]+=check[j];
					ans=s[a[i].d];
				}
			}
			else if(a[i].c<check[a[i].s])
			{
				ans-=check[a[i].s]-a[i].c;
				check[a[i].s]=a[i].c;
				if(!flag)//若已经都能飞回去后，出现当前飞机更便宜，在之前的基础上sum,更新花费sum
				{
					s[a[i].d]=ans;
				}
			}
		}
	}
	if(flag)
	{
		cout<<-1<<endl;
		return 0;
	}
	memset(check,0,sizeof(check));
	flag = n;
	for(i=m;i>=1;i--)
	{
		if(a[i].e)
		{
			if(check[a[i].e]==0)
			{
				check[a[i].e]=a[i].c;
				flag--;
				if(flag==0)
				{
					for(j=1;j<=n;j++)
						e[a[i].d]+=check[j];
					ans=e[a[i].d];
				}
			}
			else if(a[i].c<check[a[i].e])
			{
				ans-=check[a[i].e]-a[i].c;
				check[a[i].e]=a[i].c;
				if(flag==0)
				{
					e[a[i].d]=ans;
				}
			}
		}
	}
	if(flag!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(i=1;i<=MAX;i++)
	{
		if(s[i]==0)//如果当前i天无法判断是否已经到了，那么若是前一天i-1天可以判断出来，就s[i]=s[i-1]
			s[i]=s[i-1];
		else if(s[i-1])
			s[i]=min(s[i],s[i-1]);
	}
	for(i=MAX;i>=1;i--)
	{
		if(e[i]==0)//同上
			e[i]=e[i+1];
		else if(e[i+1])
			e[i]=min(e[i],e[i+1]);
	}
	sum=1e18;
	for(i=1;i<=MAX-k-1;i++)
	{
		if(s[i]!=0&&e[i+k+1]!=0)
		{
			sum=min(sum,s[i]+e[i+k+1]);
		}
	}
	if(sum==1e18)
		cout<<-1<<endl;
	else
		cout<<sum<<endl;
	return 0;
}
