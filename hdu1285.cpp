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

int check[505];
int tu[505][505];
int i,cnt;
int qu[505];
int x,y,n,m;
int main()
{
	while(cin>>n>>m)
	{
		int i;
		cnt = 0;
		memset(check,0,sizeof(check));
		memset(qu,0,sizeof(qu));
		queue<int> qua;
		memset(tu,0,sizeof(tu));
		for(i=1;i<=m;i++)
		{
			cin>>x>>y;
			if(tu[x][y]==0)
			{
				tu[x][y]=1;
				check[y]++;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(check[i]==0)
			{

				qua.push(i);
				check[i]=-1;
				qu[++cnt]=i;
				break;
			}
		}
		while(!qua.empty())
		{
			x=qua.front();
			qua.pop();
			for(i=1;i<=n;i++)
			{
				if(tu[x][i]==1)
				{
					check[i]--;
				}
			}
			for(i=1;i<=n;i++)
			{
				if(check[i]==0)
				{
					qua.push(i);
					check[i]=-1;
					qu[++cnt]=i;
					break;
				}
			}
		}
		for(i=1;i<n;i++)
			cout<<qu[i]<<" ";
		cout<<qu[i]<<endl;
	}
	return 0;
}
