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


string str,str1;
int n,l,m,i,j,k,ans,sum,flag,flag1;
int main()
{
	cin>>n>>m;
	cin>>str;
	cin>>str1;
	sum=10005;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(str1[j]==str[i])
			{
				ans=i+1;
				for(k=i+1,l=j+1;l<m,k<n;k++,l++)
				{
					if(str1[j+l]!=str[k])
					{
						ans++;
					}
				}
				if(k!=n)
					break;
				if(ans<sum)
				{
					flag=i;
					flag1=j;
					sum=ans;
				}
			}
		}
	}
	if(sum==10005)
	{
		sum=1;
		flag=0;
	}
	cout<<sum<<endl;
	cout<<"flag"<<flag<<" flag1"<<flag1<<endl;
	for(i=0;i<flag;i++)
	{
		k=i+1;
		cout<<k<<" ";
	}
	for(i=flag,j=flag1;i<n;i++,j++)
	{
		if(str[i]!=str1[j])
		{
			k=i+1;
			cout<<k<<" ";
		}
	}
	cout << endl;
}
