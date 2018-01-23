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

int n,i,j;
char str[5005];
int a[5005],ma,sum;
int main()
{
	cin>>str+1;
	n=strlen(str+1);
	for(i=1;i<=n+1;i++)
	{
		if(str[i]=='a')
			a[i]=a[i-1]+1;
		else
			a[i]=a[i-1];
	}
	ma = 0;
	for(i=0;i<=n+1;i++)
	{
		for(j=i+1;j<=n+1;j++)
		{
			sum=a[i]+a[n]-a[j-1]+(j-i-1)-(a[j-1]-a[i]);
			ma=max(sum,ma);
		}
	}
	cout<<ma<<endl;
	return 0;
}
