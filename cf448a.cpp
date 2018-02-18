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

int x,y,i,n,j;
int a[365],sum;
int main()
{
	int MIN=360;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			sum=a[j]-a[i-1];
			MIN=min(abs(360-sum*2),MIN);
		}
	}
	cout<<MIN<<endl;
	return 0;
}
