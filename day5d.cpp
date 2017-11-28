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

struct point
{
	long long int l,r,len;
}se[100005];
map<long long int,int> a;
int n,cnt,ans;
int Get(long long int x)
{
	long long int kk,l,r;
	long long int k;
	k=x;
	while(true)
	{
		l=1,r=cnt+1;
		while(l<r-1)
		{
			kk=(l+r)/2;
			if(se[kk].l<=k) l=kk;
			else r=kk;
		}
		k=(k-se[l].l+1)%se[l].len;
		if(k==0) k=se[l].len;
		if(a[k]!=0) 
		{
			//cout<<"l: "<<l<<endl;
			return a[k];
		}
	}
}
int main()
{
	int i;
	long long int x,y,l,c; 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x==1)
		{
			cin>>y;
			a[++ans]=y;
		}
		else
		{
			cin>>l>>c;
			se[++cnt].l=ans+1;
			se[cnt].r=ans+l*c;
			se[cnt].len=l;
			ans+=l*c;
		}
	}
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(a[x]!=0) cout<<a[x]<<" ";
		else cout<<Get(x)<<" ";
	}
	cout<<endl;
}
