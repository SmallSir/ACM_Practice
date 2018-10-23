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

int n,i;
LL m,x,sum,MAX,ans;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		MAX=max(MAX,x);
		ans=1;
		if(m>=sum)
		{
			ans = floor((m-sum)*1.0/MAX)+2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
