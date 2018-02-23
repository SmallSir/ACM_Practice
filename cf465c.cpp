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

LL x1,x2,r,yy1,y2;
double rr,rx,ry;
int main()
{
	scanf("%lld %lld %lld %lld %lld", &r, &x1, &yy1, &x2, &y2);
	if(x1==x2 && yy1==y2)
	{
		printf("%.10lf %.10lf %.10lf\n",double(x1*1.0+r/2.0),double(yy1*1.0),double(r/2.0));
		return 0;
	}
	if((x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2)>=r*r)
	{
		printf("%0.10lf %0.10lf %0.10lf\n",double(x1*1.0),double(yy1*1.0),double(r*1.0));
		return 0;
	}
	//以下上相似三角形的算法
	rr= (sqrt((x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2)) + r)/2.0;
	rx = double(x1-x2);
	ry = double(yy1-y2);
	rx = rr/sqrt((x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2))*rx + x2*1.0;
	ry= rr/sqrt((x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2))*ry + y2*1.0;
	printf("%0.10lf %0.10lf %0.10lf\n",rx,ry,rr);
	return 0;
}
