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
	int x,y;
}p[100005];
bool tu[10002][10002];
int cnt;
void check(int rr,int x,int y,int l,int r,int u,int d)
{
	for(int i=l;i<=r;i++)
	{
		for(int j=d;j<=u;j++)
		{
			if(abs(x-i)*abs(x-i)+abs(y-j)*abs(y-j)<=rr*rr)
					tu[i][j]=1;
		}
	}
}
int main()
{
	int n,x,y,rr,T,i,l,r,u,d;
	cin>>n;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>rr;
		l=max(0,x-rr);
		r=min(10000,x+rr);
		u=min(10000,y+rr);
		d=max(0,y-rr);
		check(rr,x,y,l,r,u,d);
	}
	for(i=1;i<=n;i++)
	{
		if(tu[p[i].x][p[i].y]==0)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
