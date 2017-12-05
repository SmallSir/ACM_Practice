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
int i,j,n,m,x,y,c,k;
int main()
{	
	for(;;)
	{
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				tu[i][j]=1<<25;
		for(i=1;i<=m;i++)
		{
			cin>>x>>y>>c;
			tu[x][y]=min(tu[x][y],c);
			tu[y][x]=min(tu[y][x],c);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					if(i==j||i==k||j==k)
						continue;
					tu[j][k]=min(tu[j][i]+tu[i][k],tu[j][k]);
				}
			}
		}
		cout<<tu[1][n]<<endl;
	}
	return 0;
}
