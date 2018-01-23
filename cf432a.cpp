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

struct point{
	LL x,y;
}a[10];
int i;
int main()
{
	for(i=1;i<=3;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	double AB=sqrt(((a[1].x - a[2].x) * (a[1].x - a[2].x) + (a[1].y - a[2].y) * (a[1].y - a[2].y))*1.0);
	double BC=sqrt(((a[2].x - a[3].x) * (a[2].x - a[3].x) + (a[2].y - a[3].y) * (a[2].y - a[3].y))*1.0);
	double AC=sqrt(((a[1].x - a[3].x) * (a[1].x - a[3].x) + (a[1].y - a[3].y) * (a[1].y - a[3].y))*1.0);
	if(AB==BC&&AB+BC>AC)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}
