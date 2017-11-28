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
//strattime:2017/10/9 21:00
//endtime:2017/10/9 21:07

struct toy
{
	int x;
	string name;
}a[100005];
int n,m,i,x,y,k;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].name;
	}
	int k=1;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(x==0)
		{
			if(a[k].x==0)
			{
				k-=y;
				if(k<0)
					k+=n;
			}
			else
			{
				k+=y;
				if(k>n)
					k%=n;
			}
		}
		else
		{
			if(a[k].x==0)
			{
				k+=y;
				if(k>n)
					k%=n;
			}
			else
			{
				k-=y;
				if(k<0)
					k+=n;
			}
		}
	}
	cout<<a[k].name<<endl;
	return 0;
}
