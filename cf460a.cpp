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

int n,m,i,x,y;
double a[5005];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[i]=(x*1.0)/(y*1.0);
	}
	sort(a+1,a+1+n);
	printf("%0.8lf\n",a[1]*m);
 return 0;
}
