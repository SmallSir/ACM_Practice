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

int i,n,sum,x;;
int a[10];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
	}
	sum=min(a[2],a[1]);
	a[1]-=min(a[2],a[1]);
	sum+=a[1]/3;
	cout<<sum<<endl;
 return 0;
}
