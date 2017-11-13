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
LL AB,BC,x,y,xx,yy;
int main()
{
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	AB=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	BC=(b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y);
	y=b.y-a.y;
	x=b.x-a.x;
	yy=c.y-b.y;
	xx=c.x-b.x;
	if(AB==BC&&yy*x!=xx*y)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
