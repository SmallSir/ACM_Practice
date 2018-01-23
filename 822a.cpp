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

LL a,b,n,sum,i;
int main()
{
	cin>>a>>b;
	n=min(a,b);
	sum=1;
	for(i=1;i<=n;i++)
	{
		sum*=i;
	}
	cout<<sum<<endl;
	return 0;
}
