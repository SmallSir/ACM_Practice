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
}a[100005];
char s;
int n,sum,x,y,i;
int main()
{
	cin>>n;
	sum=0;
	a[0].x=0,a[0].y=0;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		if(s=='U')
		{
			a[i].x=a[i-1].x;
			a[i].y=a[i-1].y+1;
		}
		else
		{
			a[i].x=a[i-1].x+1;
			a[i].y=a[i-1].y;
		}

	}
	for(i=1;i<=n-2;i++)
	{
		if(a[i].x<a[i].y&&a[i+1].x==a[i+1].y&&a[i+2].x>a[i+2].y)
			sum++;
		else if(a[i].x>a[i].y&&a[i+1].x==a[i+1].y&&a[i+2].x<a[i+2].y)
			sum++;
	}
	cout<<sum<<endl;
 return 0;
}
