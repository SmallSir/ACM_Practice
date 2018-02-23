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
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,a+1+m);
	if(a[1]>=0&&b[1]>=0)
	{
		if(b[1]>=0)
			cout<<b[m]*a[n-1]<<endl;
		else if(b[n]<0)
			cout<<b[1]*a[2]<<endl;
		else

	}
	else if(a[1]<0&&a[n]>=0)
	{
		if(b[1]
	}
	else
	{
	}
	return 0;
}
