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

int a1,a2,c,h1,h2,cnt,i;
int a[10000050];
int main()
{
	cin>>h1>>a1>>c>>h2>>a2;
	cnt=0;
	for(;;)
	{
		if(h1<=a2&&a1<h2)
		{
			a[++cnt]=1;
			h1+=c;
		}
		else
		{
			a[++cnt]=0;
			h2-=a1;
		}
		h1-=a2;
		if(h2<=0)
			break;
		
	}
	cout<<cnt<<endl;
	for(i=1;i<=cnt;i++)
	{
		if(a[i]==0)
			cout<<"STRIKE"<<endl;
		else
			cout<<"HEAL"<<endl;
	}
	return 0;
}
