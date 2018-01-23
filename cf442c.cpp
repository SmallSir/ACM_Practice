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

int i,n;
int main()
{
	cin>>n;
	cout<<n+n/2<<endl;
	for(i=2;i<=n;i+=2)
	{
		cout<<i<<" ";
	}
	for(i=1;i<=n;i+=2)
	{
		cout<<i<<" ";
	}
	for(i=2;i<=n;i+=2)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
