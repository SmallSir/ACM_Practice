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

int n,m,i,x,y,MAX;
int main()
{
	cin>>n;
	MAX=-1e6-10;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x<0)
			MAX=max(x,MAX);
		else
		{
			y=sqrt(x);
			if(y*y!=x)
				MAX=max(MAX,x);
		}
	}
	cout<<MAX<<endl;
	return 0;
}
