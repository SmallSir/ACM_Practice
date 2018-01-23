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

int n,q,c,i,t,xx,yy,x,y,j,k;
int tu[15][105][105],a[15][105][105];
struct point
{
	int x,y,k;
}star[100005];
int main()
{
	cin>>n>>q>>c;
	for(i=1;i<=n;i++)
	{
		cin>>star[i].x>>star[i].y>>star[i].k;
		tu[0][star[i].x][star[i].y]+=star[i].k;
	}
	for(i=1;i<=c;i++)
	{
		for(j=1;j<=n;j++)
		{
			star[j].k++;
			tu[i][star[j].x][star[j].y]+=star[j].k%(c+1);
		}
	}
	for(i=0;i<=c;i++)
	{
		for(j=1;j<=100;j++)
		{
			for(k=1;k<=100;k++)
			{
				a[i][j][k]+=tu[i][j][k]+a[i][j][k-1];
			}
		}
		for(j=1;j<=100;j++)
		{
			for(k=1;k<=100;k++)
			{
				a[i][j][k]+=a[i][j-1][k];
			}
		}
	}
	while(q--)
	{
		cin>>t>>x>>y>>xx>>yy;
		t%=(c+1);
		cout<<a[t][xx][yy]-a[t][x-1][yy]-a[t][xx][y-1]+a[t][x-1][y-1]<<endl;
	}
	return 0;
}
