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

int T,n,k;
long long ans;
long long int pt=1e9+7;
long long int check[10005],a[10005];;
long long int fast_pow(long long int x,long long int y)
{
	long long int res;
	res=1;
	x%=pt;
	while(y!=0)
	{
		if(y&1) res=(res*x)%pt;
		y>>=1;
		x=(x*x)%pt;
	}
	return res;
}
int main()
{
	long long int i;
	cin>>T;
	check[1]=0;
	check[2]=1;
	for(i=3;i<=1000;i++)
	{
		check[i]=(i-1)*(check[i-1]+check[i-2])%pt;
	}
	a[0]=1;
	for(i=1;i<=1000;i++)
	{
		a[i]=a[i-1]*i%pt;
	}
	while(T--)
	{
		cin>>n>>k;
		ans=0;
		for(i=k;i<=n;i++)
		{
			ans=(ans+check[n-i]*a[n] % pt *fast_pow(a[i],pt-2)%pt*fast_pow(a[n-i],pt-2) % pt)%pt;
		}
		cout<<(1+ans)<<endl;
	}
}
