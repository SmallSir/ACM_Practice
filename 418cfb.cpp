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

bool check[1005];
int a[1005],b[1005],c[1005],vis[1005];
int x,y,i,n;
int main()
{
	cin>>n;
	x=y=0;
	memset(check,false,sizeof(check));
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[a[i]]++;
		if(vis[a[i]]==2)
			x=a[i];
	}
	memset(vis,0,sizeof(vis));
	
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		//vis[b[i]]++;
		vis[b[i]]++;
		if(vis[b[i]]==2)
			y=b[i];
		//cout<<y<<endl;
	}
	
//	cout<<x<<" "<<y<<endl;
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
	{
		if(a[i]==b[i])
		{
			c[i]=a[i];
			check[c[i]]=true;
		}
	}
	//cout<<x<<" "<<y<<endl;
	//cout<<check[x]<<endl;
	if(x!=0&&y!=0)
	{
		//cout<<"1111111111"<<endl;
		if(check[x]==true&&!check[y])
		{
			for(i=1;i<=n;i++)
			{
				if(c[i]==0)
				{
					//cout<<11111111111111<<endl;
					check[y]=true;
					c[i]=y;
					break;
				}
			}
		}
		else if(check[y]==true&&!check[x])
		{
			for(i=1;i<=n;i++)
			{
				if(c[i]==0)
				{
					check[x]=true;
					c[i]=x;
					break;
				}
			}
		}
		else
		{
			//cout<<"111111111"<<endl;
			for(i=1;i<=n;i++)
			{
				if(!check[a[i]]&&!check[b[i]])
				{
					if(x==a[i]&&y==b[i])
					{
						if(check[a[i]]!=true)
						{
							check[a[i]]=true;
							c[i]=a[i];
						}
						else
						{
							check[b[i]]=true;
							c[i]=b[i];
						}
					}
					else
					{
						if(y==b[i])
						{
							check[b[i]]=true;
							c[i]=b[i];
						}
						else
						{
							check[a[i]]=true;
							c[i]=a[i];
						}
					}
				}
				else
				{
					if(!check[a[i]])
					{
						c[i]=a[i];
						check[a[i]]=true;
					}
					else if(!check[b[i]])
					{
						c[i]=b[i];
						check[b[i]]=true;
					}
				}
			}
		}
	}
	int j;
	for(i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			for(j=1;j<=n;j++)
			{
				if(!check[j])
				{
					c[i]=j;
				}
			}
		}
	}
	for(i=1;i<n;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<c[i]<<endl;
}
