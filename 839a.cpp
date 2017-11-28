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

int a[105];
int n,k,sum,ans,i,kk;
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	ans=0;
	sum=0;
	for(i=1;i<=n;i++)
	{
		ans+=a[i];
		kk=min(ans,8);
		sum+=kk;
		ans-=kk;
		if(sum>=k)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
