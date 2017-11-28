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



struct point
{
	string str;
	int k;
}a[100005],b[100005];
int n,m,ans,ans1,i,j;
bool flag;
int tu[505][505],tu1[505][505];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>tu[i][j];
			tu1[i][j]=tu[i][j];
		}
	}
	ans=ans1=0;
	for(i=1;i<=n;i++)
	{
		for(;;)
		{
			flag=false;
			for(j=1;j<=m;j++)
			{
				if(tu[i][j]==0)
					flag=true;
			}
			if(flag)
				break;
			ans++;
			a[ans].str="row";
			a[ans].k=i;
			for(j=1;j<=m;j++)
				tu[i][j]--;
		}
	}
	for(i=1;i<=m;i++)
	{
		for(;;)
		{
			flag=false;
			for(j=1;j<=n;j++)
				if(tu[j][i]==0)
					flag=true;
			if(flag)
				break;
			ans++;
			a[ans].str="col";
			a[ans].k=i;
			for(j=1;j<=n;j++)
				tu[j][i]--;
		}
	}

	for(i=1;i<=m;i++)
	{
		for(;;)
		{
			flag=false;
			for(j=1;j<=n;j++)
				if(tu1[j][i]==0)
					flag=true;
			if(flag)
				break;
			ans1++;
			b[ans1].str="col";
			b[ans1].k=i;
			for(j=1;j<=n;j++)
				tu1[j][i]--;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(;;)
		{
			flag=false;
			for(j=1;j<=m;j++)
			{
				if(tu1[i][j]==0)
					flag=true;
			}
			if(flag)
				break;
			ans1++;
			b[ans1].str="row";
			b[ans1].k=i;
			for(j=1;j<=m;j++)
				tu1[i][j]--;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(tu[i][j]!=0)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	if(ans<ans1)
	{
		cout<<ans<<endl;
		for(i=1;i<=ans;i++)
		{
			cout<<a[i].str<<" "<<a[i].k<<endl;
		}
	}
	else
	{
		cout<<ans1<<endl;
		for(i=1;i<=ans1;i++)
			cout<<b[i].str<<" "<<b[i].k<<endl;
	}
	
}

