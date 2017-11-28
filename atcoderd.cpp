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
vector<int> tu[100005];
int n,cnt1,cnt2;
bool check[100005];
int a[100005];
void dfs(int x,int index)
{
	int k,i;
	for(i=0;i<tu[x].size();i++)
	{

		k=tu[x][i];
		if(check[k]!=1)
		{
			if(k==1&&index==-1||k==n&&index==1)
				continue;
			check[k]=1;
			a[k]=index;
			dfs(k,index);
		}
	}
}
int main()
{
	int x,y,i,k;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	//memset(b,0,sizeof(b));
	memset(a,0,sizeof(a));
	a[1]=1,a[n]=-1;
	memset(check,0,sizeof(check));
	check[1]=1;
	dfs(1,1);
	for(i=1;i<n;i++)
		if(a[i]==0)
			cnt2++;
	memset(check,0,sizeof(check));
	check[n]=1;
	dfs(n,-1);
	for(i=2;i<=n;i++)
		if(a[i]==1)
			cnt1++;
	k=n-2-cnt1-cnt2;
	if(k%2==0)
	{
		cnt1+=k/2;
		cnt2+=k/2;
	}
	else
	{
		cnt1+=k/2+1;
		cnt2+=k/2;
	}
	if(cnt1<=cnt2)
	{
		cout<<"Snuke"<<endl;
	}
	else
	{
		cout<<"Fennec"<<endl;
	}
}
