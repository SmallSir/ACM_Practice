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


struct point
{
	int x,y,c;
}a[10005];
int sum,n,m,cnt;
int check[10005],path[10005];;
void init()
{
	for(int i=1;i<=n;i++)
		 check[i]=i;
}
int find(int x)
{
	if(check[x]==x)
		return x;
	check[x]=find(check[x]);
	return check[x];
}
bool cmp(point x,point y)
{
	return x.c<y.c;
}
bool merage(int x,int y)
{
	int t1=find(x);
	int t2=find(y);
	if(t1!=t2)
	{
		check[t2]=t1;
		return true;
	}
	else
		return false;
}
void Kruskal()
{
	int i;
	init();
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++)
	{
		if(merage(a[i].x,a[i].y))
		{
			cnt++;
			path[cnt]=i;//将生成最小生成树的边的下标记下来
			sum+=a[i].c;//算出最小生成树的权值和
		}
		if(cnt==n-1)
			break;
	}
}
bool mst()
{
	int ans,i,j;
	int k;
	for(i=1;i<=cnt;i++)//枚举最小生成树中的边
	{
		ans=0,k=0;
		init();
		for(j=1;j<=m;j++)
		{
			if(j==path[i]) continue;
			if(merage(a[j].x,a[j].y))
			{
				k++;
				ans+=a[j].c;
			}
		}
		if(k==n-1&&ans==sum)//判断在删除一个边的情况下，是否生成了一个次小生成树与最小生成树的权值相同
			return false;
	}
	return true;
}
int main()
{
	int T,i;
	cin>>T;
	while(T--)
	{
		memset(check,0,sizeof(check));
		memset(a,0,sizeof(a));
		memset(path,0,sizeof(path));
		sum=0;
		cnt=0;
		cin>>n>>m;
		for(i=1;i<=m;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].c;
		}
		Kruskal();//预处理出来一个最小生成树
		if(mst())
		{
			cout<<sum<<endl;
		}
		else
		{
			cout<<"Not Unique!"<<endl;
		}
	}
}
