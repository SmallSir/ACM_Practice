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

int T;
LL x,y;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x;
		if(x%2!=0)
		{
			cout<<"No"<<endl;
			continue;
		}
		else
		{
			y = 1;
			for(;;)
			{
				y*=2;
				if(y>=x)
				{
					cout<<1<<" "<<x<<endl;
					break;
				}
				if((x/y)%2!=0)
				{
					cout<<x/y<<" "<<y<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
