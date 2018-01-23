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
#define INF 1000000000  
using namespace std;
typedef long long LL;


vector<int> tu[500005],cost[500005],rtu[500005],ccost[500005];
int n,m,s,t,T;
int dis[500005],vis[500005];
void build(int x,int y,int c)
{
	tu[x].push_back(y);
	cost[x].push_back(c);
	rtu[y].push_back(x);
	ccost[y].push_back(c);
}

struct A
{
	int pos,f,g;//g表示的是源点s到当前点pos的距离，f表示的是pos这个点的估值
	bool operator <(const A a)const { 
		if(a.f == f) return a.g < g;  
        return a.f < f;  
    }  
};
void spfa(int x)
{
	int i,tot,k,c;
	for(i=1;i<=n;i++)
	{
		dis[i]=INF;
		vis[i]=0;
	}
	queue<int> qua;
	qua.push(x);
	dis[x]=0;//dis数组表示的是到终点t的最短距离
	vis[x]=1;
	while(!qua.empty())
	{
		tot=qua.front();
		qua.pop();
		for(i=0;i<rtu[tot].size();i++)
		{
			k=rtu[tot][i];
			c=ccost[tot][i];
			if(dis[k]>dis[tot]+c)
			{
				dis[k]=dis[tot]+c;
				if(vis[k]!=0)
				{
					vis[k]=1;
					qua.push(k);
				}
			}
		}
		vis[tot]=0;
	}
}
int Astar(int x,int y)
{
	int i,tot,c;
	int cnt=0;
	priority_queue<A> qua;
	if(x==y) T++;
	if(dis[x]==INF) 
	{
		return -1;
	}
	A a,b;
	a.pos=x,a.g=0,a.f=a.g+dis[x];//f(n)=g(n)+h(n),h(n)就是dis[n]
	qua.push(a);
	while(!qua.empty())
	{
		b=qua.top();
		qua.pop();

		if(b.pos==y)
		{
			//cout<<b.pos<<" "<<b.f<<" "<<b.g<<endl;
			cnt++;
			if(cnt==T)
				return b.g;
		}
		for(i=0;i<tu[b.pos].size();i++)
		{
			a.pos=tu[b.pos][i];
			a.g=b.g+cost[b.pos][i];
			a.f=a.g+dis[a.pos];
			//cout<<"------"<<a.pos<<" "<<a.g<<" "<<a.f<<endl;
			qua.push(a);
		}
	}
	return -1;
}
int main()
{
	int x,y,c,i;
	while(cin>>n>>m)
	{
		
		for(i=1;i<=m;i++)
		{
			cin>>x>>y>>c;
			build(x,y,c);
		}
		cin>>s>>t>>T;
		spfa(t);//反向建图跑
		cout<<Astar(s,t)<<endl;
	}
}
