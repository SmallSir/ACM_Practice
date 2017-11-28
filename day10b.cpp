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

long long int sum,ans,a[1000005];
int n,m,k,i;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sum=ans=0;
	k=(n+1)/2;
	for(i=n;i>=k;i-=m)
		ans+=a[i]-a[k];
	for(i=1;i<k;i+=m)
		ans+=a[k]-a[i];
	cout<<ans*2<<endl;
}
