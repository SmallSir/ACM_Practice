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

int n,m,i,l,r,x;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>l>>r;
		if(x>=l)
		{
			x=max(r,x);
		}
	}
	if(x>=m)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
