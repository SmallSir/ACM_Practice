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

long long int check[100005],up[100005],down[100005];
vector<int> tree[100005];
int n;
void dfs(int son,int father)
{
	int k,i;
	up[son]=down[son]=0;
	for(i=0;i<tree[son].size();i++)
	{
		k=tree[son][i];
		if(k==father)
			continue;
		dfs(k,son);
		up[son]=max(up[son],up[k]);
		down[son]=max(down[son],down[k]);
	}
	check[son]+=up[son]-down[son];
	if(check[son]>0)
		down[son]+=check[son];
	else
		up[son]-=check[son];
}
int main()
{
	int x,y,i;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	for(i=1;i<=n;i++) cin>>check[i];
	dfs(1,0);
	cout<<up[1]+down[1]<<endl;
}
