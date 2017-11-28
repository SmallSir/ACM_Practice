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

int n,k,x,i;
int a[105],sum;
int main()
{
	cin>>n>>k; 
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[x]=1;
	}
	sum=0;
	for(i=0;i<k;i++)
	{
		if(a[i]==0)
			sum++;
	}
	if(a[k]==1)
		sum++;
	cout<<sum<<endl;

 return 0;
}
