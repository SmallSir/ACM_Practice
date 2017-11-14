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

int dx[5]={1,-1,0,0};
int dy[5]={0,0,1,-1};
int n,m,k,sum;
char a[505][505];
void dfs(int x,int y)
{
	int i;
	if(x<1||x>n||y<1||y>m)
		return;
	if(sum!=k&&a[x][y]=='X')
	{
		a[x][y]='.';
		sum--;
		for(i=0;i<4;i++)
			dfs(x+dx[i],y+dy[i]);
	}
}
int main()
{
	int i,j;
	cin>>n>>m>>k;
	sum=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='.')
			{
				a[i][j]='X';
				sum++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(sum==k)
				break;
			if(a[i][j]=='X')
				dfs(i,j);
		}
		if(sum==k)
			break;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
