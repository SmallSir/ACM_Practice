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
LL sum,x,a[100005];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(sum>a[n-1]+a[n])
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
 return 0;
}
