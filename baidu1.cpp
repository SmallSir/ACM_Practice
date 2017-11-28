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

int dix[]={1,0,-1,0};
int diy[]={0,1,0,-1};
bool vis[105][105];
char tu[105][105];
int n,m;
void dfs(int x,int y,int flag)
{
	int xx,yy,i;
	vis[x][y]=1;
	for(i=0;i<4;i++)
	{
		xx=dix[i]+x;
		yy=diy[i]+y;
		if(yy>=1&&yy<=m&&xx>=1&&xx<=n&&vis[xx][yy]==0&&tu[xx][yy]-'0'==flag)
		{
			vis[xx][yy]=1;
			dfs(xx,yy,flag);	
		}
	}
}
int main()
{
	 while(cin>>n>>m)
	 {
	 	 int flag1,flag2;
	 	 flag1=flag2=0;
	 	 int i,j,cnt0,cnt1;
	 	 memset(tu,0,sizeof(tu));
	 	 for(i=1;i<=n;i++)
		 {
		 	 for(j=1;j<=m;j++)
			 {
			 	 cin>>tu[i][j];
			 }
		 }
		 memset(vis,0,sizeof(vis));
		 cnt1=0,cnt0=0;
		 for(i=1;i<=n;i++)
		 {
			for(j=1;j<=m;j++)
			{
				if(vis[i][j]==0)
				{
					if(tu[i][j]-'0'==0)
					{
						cnt0++;
						dfs(i,j,0);
					}
					else
					{
						if(i==1)
							flag1=1;
						if(i==n)
							flag2=1;
						cnt1++;	
						dfs(i,j,1);
					}
				}
			}
		 }
		 if(cnt1!=1)
		 {
		 	 cout<<-1<<endl;
		 }
		 else
		 {
		 	 if(cnt0==3)
			 {
			 	 if(flag1&&flag2)
				 {
				 	 cout<<0<<endl;
				 }
				 else
				 	 cout<<-1<<endl;
			 }
			 else if(cnt0==2)
			{
				if(flag1&&flag2)
					cout<<1<<endl;
				else if(flag1||flag2)
					cout<<0<<endl;
				else
					cout<<-1<<endl;
			}
			 else if(cnt0==1)
				cout<<1<<endl;
			else
				cout<<-1<<endl;
		 }
	 }
	 return 0;
}
