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

char s,t;
int i,x,y;
LL n;
char a[]={'v','<','^','>'};
int main()
{
	cin>>s>>t;
	cin>>n;
	for(i=0;i<4;i++)
	{
		if(s==a[i])
		{
			x=i;
			break;
		}
	}
	for(i=0;i<4;i++)
	{
		if(t==a[i])
		{
			y=i;
			break;
		}
	}
	n%=4;
	if((x+n)%4==y&&(y+n)%4==x)
	{
		cout<<"undefined"<<endl;
	}
	else if((y+n)%4==x)
	{
		cout<<"ccw"<<endl;
	}
	else
	{
		cout<<"cw"<<endl;
	}
	 return 0;
}
