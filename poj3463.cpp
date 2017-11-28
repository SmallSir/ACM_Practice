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

queue<int> qua;
int a[200005],b[200005];
int i,n,sum,x;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=x;
		b[x]++;
	}
	sum=0;
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			qua.push(i);
			sum++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(b[a[i]]!=1&&a[i]>qua.front())
		{
			b[a[i]]--;
			a[i]=qua.front();
			qua.pop();
		}
	}
	cout<<sum<<endl;
	for(i=1;i<n;i++)
		cout<<a[i]<<" ";
	cout<<a[i]<<endl;
}
