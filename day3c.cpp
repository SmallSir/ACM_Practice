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

int i,n;
long long int m,l,r,k,sum;
struct point
{
	long long int t;
	int pos;
}a[100005],pp;
queue<point> qua;
bool check(long long int x)
{
	if(x*n<m)
		return 1;
	else
		return 0;
}
int main()
{
	int s;
	cin>>n>>m;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i].t;
		a[i].pos=i;
		sum+=a[i].t;
	}
	if(sum<=m)
	{
		cout<<-1<<endl;
		return 0;
	}
	l=0,r=100000000000005;
	while(l<r-1)
	{
		k=(l+r)/2;
		if(check(k))
			l=k;
		else
			r=k;
		//cout<<k<<endl;
	}
	bool flag=0;
	//cout<<l<<endl;
	for(i=1;i<=n;i++)
	{
		m-=min(a[i].t,l);
		//cout<<a[i].t<<endl;
		a[i].t-=min(a[i].t,l);
		//cout<<m<<endl;
		//cout<<i<<" "<<m<<endl;

	}
	//cout<<s<<endl;
	//cout<<m<<endl;
	for(i=1;i<=n;i++)
	{
		if(m==0)
		{
			if(a[i].t>0)
			{
				qua.push(a[i]);
				a[i].t=0;
			}
		}
		else
		{	
			if(a[i].t>0)
			{
				m--;
				a[i].t--;
				//cout<<m<<" "<<i<<" "<<a[i].t<<endl;
				//m--;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i].t>0)
		{
			qua.push(a[i]);
		}
	}
	while(!qua.empty())
	{
		pp=qua.front();
		//flag=1;
		cout<<pp.pos<<" ";
		qua.pop();
	}
	cout<<endl;
}
