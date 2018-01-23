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

int deep[100005];
vector<int> tu[100005];
LL ans;
int n;
void bfs()
{
	int i,k,x;
	memset(deep,0,sizeof(deep));
	deep[1]=1;
	queue<int> qua;
	qua.push(1);
	while(!qua.empty())
	{
		x=qua.front();
		qua.pop();
		for(i=0;i<tu[x].size();i++)
		{
			k=tu[x][i];
			if(deep[k]==0)
			{
				deep[k]=deep[x]+1;
				qua.push(k);
			}
		}
	}
}
int main()
{
	int i,x,y;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	bfs();
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(deep[i]%2==0)
			ans++;
	}
	cout<<ans*(n-ans)-(n-1)<<endl;
	return 0;
}
