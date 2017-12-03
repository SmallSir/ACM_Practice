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
LL sum,cnt,a[1000005];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sum=1;
	cnt=n-a[n];
	for(i=n-1;i>=1;i--)
	{
		if(i<cnt)
		{
			sum++;
		}
		cnt=min(cnt,i-a[i]);
	}
	cout<<sum<<endl;
 return 0;
}
