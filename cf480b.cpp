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

LL sum,a[10005];
int i,k,n;

int main()
{
	cin>>k>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum>k*8)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	sum=0;
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
	{
		b[a[i]%8]++;
		sum+=a[i];
	}
	sum+=b[2]/4*2;
	if(sum<=k*8)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
 return 0;
}
