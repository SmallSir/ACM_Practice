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


int n;
vector<int> tu[100005];
int lu[100005];
int a[100005];
bool check[100005];
void dfs(int x,int y)
{
	int ss[5],tot,kk;
	int i,j;
	tot=0;
	int cnt=0;
	for(i=0;i<tu[lu[y]].size();i++)
	{
		cnt=tu[lu[y]][i];
		if(check[cnt]==1)
			continue;
		//cnt;
		for(j=0;j<tu[lu[x]].size();j++)
		{
			if(check[tu[lu[x]][j]]==1)
				continue;
			if(cnt==tu[lu[x]][j])
			{
				ss[++tot]=cnt;
				break;
			}
			else kk=cnt;
		}	
	}
	bool flag=0;
	cout<<kk<<endl;
	for(i=0;i<tu[kk].size();i++)
	{
		for(j=1;j<=tot;j++)
		{
			if(tu[kk][i]==ss[j])
			{
				check[ss[j]]=1;
				lu[y+1]=ss[j];
				flag=1;
				break;
			}
		}
		if(flag)
		{
			break;
		}
	}
	if(y==n-1)
		return;
	dfs(y,y+1);
}
int main()
{
	int x,y,i,j,k;
	cin>>n;
	for(i=1;i<=n*2;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	if(n==5)
	{
		cout<<"1 2 3 4 5"<<endl;
		return 0;
	}
	lu[1]=1;
	memset(check,0,sizeof(check));
	check[1]=1;
	for(i=0;i<tu[1].size();i++)
		check[tu[1][i]]=1;
	memset(a,0,sizeof(a));
	for(i=0;i<tu[1].size();i++)
	{
		k=tu[1][i];
		//cout<<k<<endl;
		for(j=0;j<tu[k].size();j++)
		{
			if(check[tu[k][j]]==0)
			{
			//cout<<tu[k][j]<<endl;
				a[i]++;
			}
		}
	}
	memset(check,0,sizeof(check));
	for(i=0;i<tu[1].size();i++)
	{
		//cout<<a[i]<<endl;
		if(a[i]==1)
		{
			//cout<<tu[1][i]<<endl;
			lu[2]=tu[1][i];
		}
	}
	check[1]=check[lu[2]]=1;
	//sort(tu+1,tu+1+n);
	//cout<<lu[2]<<endl;
	dfs(1,2);
	for(i=1;i<n;i++)
		cout<<lu[i]<<" ";
	cout<<lu[i]<<endl;
}
