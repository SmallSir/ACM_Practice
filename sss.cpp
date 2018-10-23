#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 100000000
using namespace std;
int map[1005][1005];
bool used[10009];
int a[505],b[505];
int s,t,m,p;
int dfs(int b,int e,int f)
{
    int d;
    if(b==e) return f;
    for(int i=1;i<=p+m+1;i++)
    {
        if(map[b][i]>0&&!used[i])
        {
            used[i]=true;
            d=dfs(i,e,min(f,map[b][i]));
            if(d>0) 
            {
                map[b][i]-=d;
                map[i][b]+=d;
                return d;
            }
        }
    }
}
int maxflow(int b,int e)
{
    int flow=0;
    while(1)
    {
        memset(used,false,sizeof(used));
        int d=dfs(b,e,INF);
        printf("%d\n", d);
        if(d==0) return flow;
        flow+=d;    
    }
    return flow;
}
int main()
{
	memset(map, 0, sizeof(map));
	int x,j;
    cin>>p>>m;
    for(int i=1;i<=p;i++)
    {
    	cin>>a[i];
    }
    for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
    for(int i=1;i<=p;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>x;
			if(a[i]<b[j])
				map[i][p+j] = x;
			else
				map[i][p+j] = 0;
		}
	}
	int i;
	for(i=1;i<=p;i++)
	{
		map[0][i] = 10000;
	}
	for(i=1;i<=m;i++)
	{
		map[p+i][p+m+1]=10000;
	}
    printf("%d\n",maxflow(0,p+m+1));
    return 0;
} 
