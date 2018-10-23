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

int i,sum,n,cnt;
int a[200005];
int main()
{
	sum=0;
	cnt=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		cnt+=a[i];
		if(cnt*2>=sum)
		{
			cout<<i<<endl;
			break;

		}
	}
 return 0;
}
