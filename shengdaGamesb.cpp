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

string str="DCBAS";
int sum,i,x,n,t,f;
bool flag;
int main()
{
	while(cin>>n)
	{
		i=0;
		sum=0;
		t=f=0;
		while(n--)
		{
			cin>>x;
			if(flag==true)
			{
				if(x==1)
					t++;
				else
					f++;
				if(t==2)
				{
					flag=false;
					t=0,f=0;
					i++;
					sum=0;
				}
				else if(f==2)
				{
					flag=false;
					t=f=0;
					sum=60;
				}
			}
			else
			{
				if(x==0)
				{
					t=f=0;
					sum=max(0,sum-5);
				}
				else
				{
					t=f=0;
					sum+=10;
					if(sum>=100)
					{
						sum=0;
						flag=true;
						//cout<<11111<<endl;
					}
				}
			}
		}
		if(i>=4)
			cout<<str[4]<<endl;
		else
			cout<<str[i]<<endl;
	}

}
