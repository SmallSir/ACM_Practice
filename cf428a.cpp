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

int n,i,sum;
LL k,ans,cnt;
LL a[105];
int main()
{
	ans=0;
	cnt=0;
	sum=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		ans+=a[i];
		cnt+=min(8LL,ans);
		ans-=min(8LL,ans);
		if(cnt>=k)
		{
			sum=i;
			break;
		}
	}
	if(sum==0)
		cout<<-1<<endl;
	else
		cout<<sum<<endl;
}
