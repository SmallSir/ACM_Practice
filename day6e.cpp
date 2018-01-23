#include<iostream>  
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<climits>   
#include<cmath>
#include<stack>
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

long long int sum,ans;
int i,n;
int a[100005];
//map<int,bool> t;
int check(int x)
{
	int cnt=0;
	for(;;)
	{
		if(x%2!=0)
			cnt++;
		x/=2;
		if(x==0)
			break;
	}
	return cnt;
}
int main()
{
	int x;
	cin>>n;
	//int u=0;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=check(x);
	}
	sort(a+1,a+1+n);
	ans=0;
	sum=0;
	for(i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			ans=1;
			for(;i<=n;i++)
			{
				if(a[i]!=a[i-1])
				{
					//cout<<i<<" "<<ans<<endl;;
					sum+=ans*(ans-1)/2;
					//cout<<sum<<endl;
					ans=0;
					break;
					//ans=0;
				}
				ans++;
			}
		}
	}
	sum+=ans*(ans-1)/2;
	cout<<sum<<endl;
}
