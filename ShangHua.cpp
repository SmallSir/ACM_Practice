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
using namespace std; 



int T;
long long int a[1005],b[1005],check[1005],ans;
vector<int> tu[1005];
int n;
void dfs(int x)
{
	int xx,i;
	int k;
	queue<int> qua;
	qua.push(x);
	check[x]=1;
	while(!qua.empty())
	{
		k=qua.front();
		//cout<<"k:"<<k<<endl;
		qua.pop();
		for(i=0;i<tu[k].size();i++)
		{
			xx=tu[k][i];
			check[xx]+=check[k];
		}
		if(b[xx]!=0)
			qua.push(xx);
	}
}
int main()
{
	int x,i,y;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(tu,0,sizeof(tu));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(check,0,sizeof(check));
		for(i=1;i<=n;i++)
		{
			cin>>x;
			b[i]=x;
			if(x==0)
				continue;
			//cout<<"b[i]: "<<b[i]<<endl;
			while(x--)
			{
				cin>>y;
				a[y]++;
				tu[i].push_back(y);
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				//cout<<1111<<endl;
				//cout<<i<<endl;
				dfs(i);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(b[i]==0)
				ans+=check[i];
		}
		cout<<ans<<endl;
	}
}
