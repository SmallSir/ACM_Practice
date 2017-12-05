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

int tu[105][105];
int x,y,n,m,i,j,k;
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		tu[x][y]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(i==j||i==k||j==k)
					continue;
				if(tu[j][i]==1&&tu[i][k]==1)
					tu[j][k]=1;
				if(tu[k][i]==1&&tu[i][j]==1)
					tu[k][j]=1;
			}
		}
	}
	int sum=0;
	for(i=1;i<=n;i++)
	{
		int ans=0;
		for(j=1;j<=n;j++)
		{
			if(tu[i][j]==1||tu[j][i]==1)
				ans++;
		}
		if(ans==n-1)
			sum++;
	}
	cout<<sum<<endl;
 return 0;
}
