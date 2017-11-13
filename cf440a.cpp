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

int i,n,k,MIN,MAX;
int a[100005],b[100005],L[100005],R[100005];
int main()
{
	int i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		MIN=(1<<30);
		for(i=1;i<=n;i++)
			MIN=min(MIN,a[i]);
		cout<<MIN<<endl;
	}
	else if(k==2)
	{
		L[1]=a[1],R[n]=a[n];
		for(i=2;i<=n;i++)
			L[i]=min(a[i],L[i-1]);
		for(i=n-1;i>=1;i--)
			R[i]=min(a[i],R[i+1]);
		MAX=-(1<<30);
		for(i=1;i<=n;i++)
			MAX=max(MAX,max(L[i],R[i]));
		cout<<MAX<<endl;
	}
	else
	{
		MAX=-(1<<30);
		for(i=1;i<=n;i++)
		{
			MAX=max(a[i],MAX);
		}
		cout<<MAX<<endl;
	}
}
