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

int a[10],b[10],check[10];
int i,p,j,sum;
int main()
{
	cin>>p;
	for(i=1;i<=6;i++)
		cin>>a[i];
	for(i=1;i<=6;i++)
		cin>>b[i];
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		{
			sum = a[i]+b[j];
			check[sum%p]++;
		}
	}
	for(i=1;i<p;i++)
	{
		if(check[i]!=check[i-1])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
 return 0;
}
