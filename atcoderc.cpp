#include<iostream>  
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<climits>   
#include<cmath> 
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

long long int MIN,a[200005],cnt[200005];
int i,n;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		cnt[i]=cnt[i-1]+a[i];
	}
	MIN=10000000000;
	//cout<<MIN<<endl;
	for(i=1;i<n;i++)
	{
		//cout<<cnt[i]<<" "<<cnt[n]-cnt[i]<<endl;
		MIN=min(MIN,abs(cnt[i]-(cnt[n]-cnt[i])));
	}
	cout<<MIN<<endl;
}
