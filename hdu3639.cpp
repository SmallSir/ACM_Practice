#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

void tarjan(int x)
{
	check[x]=low[x]=++index;
	instack[x]=1;
	st.push(x);
	for(i=0;i<tu[x].size();i++)
	{
		k=tu[x][i];
		if(check[k]==-1)
		{
			tarjan(k);
			low[x]=min(low[x],low[k]);
		}
		else if(instack[k])
			low[x]=min(low[x],check[k]);
	}
	if(check[x]==low[x])
	{
		k=-1;
		cnt++;
		while(k!=x)
		{
			k=st.top();
			st.pop();
			instack[k]=0;
			fllow[k]=cnt;
			a[cnt]++;
			b[cnt][a[cnt]]=k;
		}
	}
}
void dfs(int x)
{

}
int main()
{
	cin>>T;
	int tot=0;
	while(T--)
	{
		memset(tu,0,sizeof(tu));
		memset(tt,0,sizeof(tt));
		memset(vis,0,sizeof(vis));
		memset(fllow,0,sizeof(fllow));
		memset(c,0,sizeof(c));
		memset(outt,0,sizeof(outt));
		tot++;
		cin>>n>>m;
		for(i=1;i<=m;i++)
		{
			cin>>x>>y;
			tu[x].push_back(y);
		}
		index=0;
		cnt=0;
		memset(check,-1,sizeof(check));
		for(i=0;i<n;i++)
			if(check[i]==-1)
				tarjan(i);
		for(i=0;i<n;i++)
		{
			for(j=0;j<tu[i].size();i++)
			{
				x=tu[i][j];
				if(fllow[x]!=fllow[i]&&!c[fllow[i]][fllow[j]])
				{
					outt[fllow[i]]++;
					c[fllow[i]][fllow[j]]=1;
					tt[fllow[i]].push_back(fllow[x]);
				}
			}
		}
		memset(vote,0,sizeof(vote));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=cnt;i++)
		{
			if(!vis[i])
				dfs(i);
		}
		index=-1;
		MAX=0;
		for(i=1;i<=cnt;i++)
		{
			if(outt[i]==0&&vote[i]>MAX)
			{
				MAX=vote[i];
				index=i;
			}
		}
		cout<<"Case "<<tot<<": "<<MAX<<endl;
		for(i=1;i<a[index];i++)
			cout<<b[index][i]<<" ";
		cout<<b[index][i]<<endl;
	}
 return 0;
}
