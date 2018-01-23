#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector> 
#include<stack>
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

int a[105],ll,rr;
//stack<int> qua;
char str[105];
int l,r;
int i,n;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str[i];
	}
	l=0;
	r=0;
	int k;
	memset(a,0,sizeof(a));
	ll=rr=1;
//	cout<<1111<<endl;
	for(i=1;i<=n;i++)
	{
		if(str[i]=='(')
		{
			a[++rr]=1;
		}
		if(str[i]==')')
		{
			if(a[rr]==1)
			{
					a[rr]=0;
					rr--;
			}
			else
				l++;
		}
	}
//	cout<<1111<<endl;
	r=rr-ll;
	for(i=1;i<=l;i++)
	{
		cout<<"(";
	}
	for(i=1;i<=n;i++)
	{
		cout<<str[i];
	}
	for(i=1;i<=r;i++)
	{
		cout<<")";
	}
	cout<<endl;
	//cout<<l<<" "<<r<<endl;
}

	

