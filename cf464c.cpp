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

LL a[100005],cnt,sum;
int n,i,l,t,r,flag,k;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	cin>>l>>r;
	t = r-l;
	cnt=0;
	flag=0;
	for(i=1;i<=n;i++)
	{
		if(i+t>n)
			sum=a[n]-a[i-1]+a[t-n+i-1];
		else
			sum=a[i+t-1] - a[i-1];
		if(sum>=cnt)
		{	
			if(sum == cnt)
			{
				if(i>l)
					k=1-(i-l)+n;
				else
					k=l-i+1;
				flag=min(flag,k);
			}
			else
			{
				if(i>l)
					flag=1-(i-l)+n;
				else
					flag=l-i+1;
			}
			cnt =sum;
		}
	}
	cout<<flag<<endl;
	return 0;
}
