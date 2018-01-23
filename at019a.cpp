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

int main()
{
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i].x<=max(x1,x2)&&a[i].x>=min(x1,x2)&&a[i].y<=max(y1,y2)&&a[i].y>=min(y1,y2)
			b[++cnt].x=a[i].x,b[++cnt].y=a[i].y;
	}
}
