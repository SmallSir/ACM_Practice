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

int x,y,c,u,i;
float k;
int main()
{
	cin>>x>>y>>c;
	for(i=1;i<=1e5+5;i++)
	{
		x*=10;
		if(x/y==c)
		{
			cout<<i<<endl;
			return 0;
		}
		x%=y;
	}
	cout<<-1<<endl;
	return 0;
}
