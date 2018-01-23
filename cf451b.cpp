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

LL n,a,b,i;
int main()
{
	cin>>n>>a>>b;
	for(i=0;i<=n;i++)
	{
		if((n-a*i)%b==0&&(n-a*i)>=0)
		{
			cout<<"YES"<<endl;
			cout<<i<<" "<<(n-a*i)/b<<endl;
			return 0;
		}
	}
	for(i=0;i<=n;i++)
	{
		if((n-b*i)%a==0&&(n-b*i)>=0)
		{
			cout<<"YES"<<endl;
			cout<<(n-b*i)/a<<" "<<i<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
 return 0;
}
