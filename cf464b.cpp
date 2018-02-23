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

int k,i,flag;
LL MAXN,n,x,cnt;
int main()
{
	cin>>n>>k;
	MAXN=n;
	if(n==0)
	{
		cout<<1<<" "<<0<<endl;
		return 0;
	}
	for(i=1;i<=k;i++)
	{
		cin>>x;
		if(MAXN>n%x)
		{
			flag=i;
			MAXN=n%x;
			cnt=n/x;
		}
	}
	cout<<flag<<" "<<cnt<<endl;
	return 0;
}
