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

LL ans,p;
int n,i;
LL check(int x)
{
	LL y = x;
	while(x>0)
	{
		y = y*10+(x%10);
		x/=10;
	}
	return y;
}
int main()
{
	cin>>n>>p;
	for(i=1;i<=n;i++)
	{
		ans=(ans+check(i))%p;
	}
	cout<<ans<<endl;
 return 0;
}
