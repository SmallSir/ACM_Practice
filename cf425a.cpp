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
	while(T--)
	{
		cin>>ss;
		m=ss.length();
		ans=0;
		bool flag=0;
		int l=m;
		int r;
		ans=0;
		for(i=0;i<m;i++)
		{
			if(ss[i]==str[ans]) ans++;
			else 
			{
				if(str[ans]=='?')
				{
					k=ss[i]-'a';
					if(a[k+1]==0)
					{
						flag=1;
						break;
					}
					ans++;
				}
				else if(str[ans]!='*')
				{	
					flag=1;
					break;
				}
				else if(str[ans]=='*')
				{
					r=i;
					break;
				}
			}
		}
		int sum=n-1;
		for(i=m-1;i>=r;i--)
		{
			if(ss[i]==str[ans]) sum--;
			else 
			{
				if(str[ans]=='?')
				{
					k=ss[i]-'a';
					if(a[k+1]==0)
					{
						flag=1;
						break;
					}
					sum--;
				}
				else if(str[ans]!='*')
				{
					flag=1;//l=i;
					break;
				}
				else
				{
					k=ss[i]-'a';
					if(a[k+1]==1)
					{
						flag=1;
						break;
					}
				}
			}
			
		}
		if(flag==0)
		{
			for(i=ans;i<=sum;i++)
			{
				if(str[i]!='*')
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

