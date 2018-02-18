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
	for(i=1;i<=n-m;i++)
	{
		cin>>T;
		while(T--)
		{
			cin>>x>>y;
			tu[i].push_back(x);
			cost[i].push_back(y);
		}
	}
	for(i=1;i<=m;i++)
		cin>>a[n-m+i]
	
	return 0;
}
