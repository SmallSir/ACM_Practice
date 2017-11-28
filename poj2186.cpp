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
#include<stack>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

const int MAXN=5e4;
vector<int> tu[MAXN+5];
int check[MAXN+5],slow[50005];
int index,cnt;
int n,m,fllow[50005],instack[50005],outt[50005],a[50005];
stack<int> st;

void tarjan(int x)
{
	check[x]=slow[x]=++index;
	instack[x]=1;
	st.push(x);
	for(int i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(!check[k])
		{
			tarjan(k);
			slow[x]=min(slow[x],slow[k]);
		}
		else if(instack[k])
			slow[x]=min(slow[x],check[k]);
	}
	if(check[x]==slow[x])
	{
		int k=0;
		cnt++;
		while(k!=x)
		{
			k=st.top();
			st.pop();
			fllow[k]=cnt;
			instack[k]=0;
			a[cnt]++;
		}
	}
}
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		tu[x].push_back(y);
	}
	index=0;
	memset(slow,0,sizeof(slow));
	memset(fllow,0,sizeof(fllow));
	memset(check,0,sizeof(check));
	
	for(i=1;i<=n;i++)
		if(!check[i])
			tarjan(i);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<tu[i].size();j++)
		{
			int k=tu[i][j];
			if(fllow[k]!=fllow[i])
			{
				outt[fllow[i]]++;
			}
		}
	}
	int ans=0;
	for(i=1;i<=cnt;i++)
	{
		if(outt[i]==0)
		{
			if(ans>0)
			{
				printf("0\n");
				return 0;
			}
			ans=a[i];
		}		
	}
	printf("%d\n",ans);
	return 0;
}
