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

LL x,y;
int main()
{
	cin>>x>>y;
	if(y>=2)
	{
		y--;
		x-=y;
		if(x>=0&&x%2==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	else
	{
		if(x==0&&y!=0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
 return 0;
}
