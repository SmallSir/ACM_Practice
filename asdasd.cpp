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

int a[10005];
int i,n,k,sum,j;
int main()
{
	a[1]=1,a[0]=1;
	for(i=1;i<=10000;i++)
	{
		if(!a[i])
		{
			for(j=i*2;j<=10000;j+=i)
			{
				a[j]=1;
			}
		}
	}
	for(;;)
	{
		cin>>n;
		sum=0;
		if(n==0)
			break;
		for(i=1;i<=n/2;i++)
		{
			if(!a[i]&&!a[n-i]&&i!=n-i)
				sum++;
		}
		cout<<sum<<endl;
	}
 return 0;
}
