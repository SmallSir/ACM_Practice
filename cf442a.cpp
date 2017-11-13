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

LL k;
int n,MAX,a[10005];
int i,cnt,ans;
int main()
{
	cin>>n>>k;
	MAX=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
		MAX=max(a[i],MAX);
	}
	if(k>=n)
	{
		cout<<MAX<<endl;
		return 0;
	}
	cnt=1;
	ans=0;
	for(i=2;i<=n*2;i++)
	{
		if(a[cnt]>a[i])
		{
			ans++;
			if(ans==k)
			{
				cout<<a[cnt]<<endl;
				return 0;
			}
		}
		else
		{
			cnt=i;
			ans=1;
		}
	}
}
