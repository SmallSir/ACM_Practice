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
#include <iomanip>

using namespace std;
typedef long long LL;
typedef long double ld;
ld cnt,sum[200005];
map<LL,int> a;
LL x;
int i,n;
int main()
{
	cin>>n;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		cnt+=x*(i-1)-sum[i-1];
		if(a[x-1])
			cnt-=a[x-1];
		if(a[x+1])
			cnt+=a[x+1];
		sum[i]=sum[i-1]+x;
		a[x]++;
	}
	cout << fixed << setprecision(0) << cnt << endl;
}
