#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>
#include<math.h>
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 99999999; 
using namespace std;


long long int m,a[50005],ans,k;
int n;
bool cmp(long long int x,long long int y)
{
	if(x<0)
		x=-x;
	if(y<0)
		y=-y;
	return x<y;
}
int main()
{
	int i;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		//a[i]+=100000;
	}
	sort(a+1,a+1+n,cmp);
	
	if(a[1]<0)
	{
		m-=-a[1];
	}
	else
	{
		m-=a[1];
	}
	if(m<0)
	{
		cout<<0<<endl;
		return 0;
	}
	ans=1;
	//cout<<a[1]<<endl;
	for(i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
			k=a[i]-a[i-1];
		else
			k=a[i-1]-a[i];
	//	cout<<m<<endl;
		m-=k;
		if(m<0)
			break;
		ans++;
	}
	cout<<ans<<endl;
}

