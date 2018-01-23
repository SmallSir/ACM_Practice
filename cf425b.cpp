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

string str,ss,s;
int n,m,i,ans,k,j,T;
int a[50];
int main()
{
	cin>>s;
	cin>>str;
	n=s.length();
	for(i=0;i<n;i++)
	{
		k=s[i]-'a';
		a[k+1]=1;
	}
	n=str.length();
	cin>>T;
	int l,r;
	int flag=0;
	while(T--)
	{
		flag=0;
		cin>>ss;
		m=ss.length();
		ans=m;
		l=0;
		for(i=0;i<m;i++)
		{
			if(ss[i]==str[l]) l++;
			else if(str[l]=='?')
			{
				k=ss[i]-'a';
				if(a[k+1]==0)
				{
					flag=1;
					break;
				}
				l++;
			}
			else if(str[l]=='*')
			{
				ans=l;
				break;
			}
			else
			{
				flag=1;
				break;
			}
		}
		r=n-1;
		for(i=m-1;i>=ans;i--)
		{
			if(str[r]==ss[i])  r--;
			else if(str[r]=='?')
			{
				k=ss[i]-'a'+1;
				if(a[k]==0)
				{
					flag=1;
					break;
				}
				r--;
			}
			else if(str[r]!='*')
			{
				flag=1;
				break;
			}
			else
			{
				k=ss[i]-'a'+1;
				if(a[k]==1)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
		{
			for(i=l;i<=r;i++)
			{
				if(str[i]!='*')
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
}
