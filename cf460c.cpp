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

int n,m,k,sum;
char a[2005][2005];
int main()
{
	int i,j,res;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	res=0;
	if(k!=1)
	{
		for(i=1;i<=m;i++)
		{
			sum=0;
			for(j=1;j<=n;j++)
			{
				if(a[j][i]=='.')
					sum++;
				else
				{
					if(sum>=k)
						res+=sum-k+1;
					sum=0;
				}
			}
			if(sum>=k)
				res+=sum-k+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='.')
				sum++;
			else
			{
				if(sum>=k)
					res+=sum-k+1;
				sum=0;
			}
		}
		if(sum>=k)
		{
			res+=sum-k+1;
		}
	}
	cout<<res<<endl;
	return 0;
}
