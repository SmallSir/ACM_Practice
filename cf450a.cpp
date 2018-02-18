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
int i,n,l,r;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x>=0)
			l++;
		else
			r++;
	}
	if(l<=1||r<=1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
