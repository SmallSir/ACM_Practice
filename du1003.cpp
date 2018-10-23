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

int a[100005],dp[100005],tot;
int main()
{
	int T,MAX,n,l,r,i;
	cin>>T;
	while(T--)
	{
		tot++;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		l=r=1;
		MAX = a[1];
		dp[1]=a[1];
		int st=1;
		for(i=2;i<=n;i++)
		{
			if(dp[i-1] >=0)
			{
				dp[i]=dp[i-1]+a[i];
			}
			else
			{
				st=i;
				dp[i]=a[i];
			}
			if(dp[i]>MAX)
			{
				MAX=dp[i];
				l=st;
				r=i;
			}
		}
		cout<<"Case "<<tot<<":"<<endl;
		cout<<MAX<<" "<<l<<" "<<r<<endl;
		if(T!=0)
			cout<<endl;
	}
	return 0;
}
