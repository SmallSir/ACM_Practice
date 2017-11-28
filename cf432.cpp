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
	LL x,y;
}a,b,c;
LL AB,BC;
double k1,k2;
LL t(point x,point y)
{
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
double tt(point x,point y)
{
	return (y.y-x.y)/(y.x-x.x);
}
int main()
{
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	AB=t(a,b);
	BC=t(b,c);
	if(AB==BC)
	{
		if(a.x-b.x==0&&b.x-c.x==0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			k1=tt(a,b);
			k2=tt(b,c);
			if(k1!=k2)
			{
				cout<<"Yes"<<endl;
			}
			else
				cout<<"No"<<endl;
		}
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
