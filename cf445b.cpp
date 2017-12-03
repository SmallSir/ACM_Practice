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

int n,i,x,u,MAX;
int a[200010];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[x]=i;
	}
	MAX=n+1;
	for(i=0;i<=200005;i++)
	{
		if(a[i]!=0&&MAX>a[i])
		{
			MAX=a[i];
			u=i;
		}
	}
	cout<<u<<endl;
	return 0;
}
