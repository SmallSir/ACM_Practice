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

map<LL,bool> a;
LL n,k,i,x;
int main()
{
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		x=n%i;
		if(a[x]==1)
		{
			cout<<"No"<<endl;
			return 0;
		}
		a[x]=1;
	}
	cout<<"Yes"<<endl;
	return 0;
}
