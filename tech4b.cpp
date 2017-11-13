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


LL cnt,sum;
int n,m;
int a[55][55];
int b[55],c[55];

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			{
				b[i]++;
				c[j]++;
			}
		}
	}
	cnt=0;
	for(i=1;i<=n;i++)
	{
		sum=1;
		if(b[i]<2)
			continue;
		for(j=b[i]-2+1;j<=b[i];j++)
			sum*=j;
		cnt+=sum/2;
	}
	for(i=1;i<=m;i++)
	{
		sum=1;
		if(b[i]<2)
			continue;
		for(j=b[i]-2+1;j<=b[i];j++)
			sum*=j;
		cnt+=sum/2;
	}
	cout<<cnt+n*m<<endl;
	return 0;
}
