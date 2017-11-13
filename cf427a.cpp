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

LL a[105][105],tu[105][105],k,cnt,c,t1;
int n,q,i,x,y,t,xx,j,yy;
int main()
{
	cin>>n>>q>>c;
	memset(a,0,sizeof(a));
	memset(tu,0,sizeof(tu));
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>t;
		tu[x][y]=t;
		a[x][y]=1;
	}
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=100;j++)
		{
			tu[i][j]+=tu[i-1][j]+tu[i][j-1]-tu[i-1][j-1];
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	for(i=1;i<=q;i++)
	{
		cin >> t1 >> x >> y >> xx >> yy;
		k=tu[xx][yy]-tu[xx][y-1]-tu[x-1][yy]+tu[x-1][y-1];
		cnt=a[xx][yy]-a[xx][y-1]-a[x-1][yy]+a[x-1][y-1];
		cout<<(k+cnt*t1)%(c+1)<<endl;
	}
}
