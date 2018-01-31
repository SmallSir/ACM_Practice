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

int i,n,x,y,k;
char a[1005];
int main()
{
	cin>>n;
	a[1]='O';
	a[2]='O';
	x=1;
	y=1;
	for(i=2;i<=n;i++)
	{
		if(i==x+y)
		{
			a[i]='O';
			k=x+y;
			x=y;
			y=k;
		}
		else
			a[i]='o';
	}
	for(i=1;i<=n;i++)
		cout<<a[i];
	cout<<endl;
 return 0;
}
