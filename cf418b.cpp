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


bool check[1005],flag;
int n,i;
int a[1005],b[1005],c[1005],x,y,k;
int main()
{
	cin>>n;
	memset(check,false,sizeof(check));
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(check[a[i]])
			x=a[i];
		check[a[i]]=true;
	}
	memset(check,false,sizeof(check));
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		if(check[b[i]])
			y=b[i];
		check[b[i]]=true;
	}
	memset(check,false,sizeof(check));
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
	{
		if(a[i]==b[i])
		{
			c[i]=a[i];
			check[c[i]]=true;
		}
	}
	if(check[x]&&check[y])
	{
		int j;
		for(i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				for(j=1;j<=n;j++)
				{
					if(check[j]==false)
					{
						k=j;
						break;
					}
				}
				if(check[a[i]]&&check[b[i]])
				{
					//cout<<k<<endl;
					//cout<<"11111"<<endl;
					c[i]=k;
					//cout<<"c["<<i<<"]"<<c[i]<<endl;
				}
				else if(!check[a[i]])
				{
					c[i]=a[i];
				}
				else
					c[i]=b[i];
			}
		}
	}//bool flag;
	else if(!check[x]&&!check[y])
	{
		//cout<<111<<endl;
		flag=false;
		for(i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				if(!flag)
				{
					c[i]=x;
					flag=true;
				}
				else
				{
					c[i]=y;
					flag=false;
				}
			}
		}
	}
	else
	{
		if(!check[x])
		{
			//cout<<11111<<endl;
			for(i=1;i<=n;i++)
			{
				if(c[i]==0)
				{
					if(check[b[i]]==true)
						c[i]=x;
					else
						c[i]=b[i];
				}
			}
		}
		else
		{
			//cout<<1111<<endl;
			for(i=1;i<=n;i++)
			{
				if(c[i]==0)
				{
					if(check[a[i]]==true)
						c[i]=y;
					else
						c[i]=a[i];
				}
			}
		}
	}
	//cout<<k<<endl;
	for(i=1;i<n;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<c[i]<<endl;
}

