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
#define inf 9999999; 
using namespace std;

int n, m;
int cnt;
int a[1005][1005];
bool vis[1005][1005];
int tot;
int PP[1005][1005];
int b[1005];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
bool flag[1005];
bool check(int x, int y)
{
	if(x < 1 || x > 1000) return 0;
	if(y < 1 || y > 1000) return 0;
	if(vis[x][y] == 1) return 0;
	return 1;
}
void dfs(int x, int y)
{
	vis[x][y] = 1;
	PP[x][y] = tot; 
	for(int i = 1; i <= 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(check(nx, ny))
		{
			dfs(nx, ny);
			cnt++;
		}
	}
}
bool judge(int x, int y)
{
	if(a[x][y] == 0) return 0;
	if(flag[PP[x][y]] == 1) return 0;
	return 0;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		cnt = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(a[i][j] == 1)
				{
					cnt = 0;
					tot++;
					dfs(i, j);
					b[tot] = cnt;
				}
			}
		}
		int num = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(a[i][j] == 0)
				{
					num = 0;
					for(int k = 1; k <= 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if(judge(nx, ny))
						{
							num += b[PP[nx][ny]];
							flag[PP[nx][ny]] = 1;
						}
					}
					ans = max(ans, num);
					for(int k = 1; k <= 4; k++)
						flag[PP[i + dx[k]][j + dy[k]]] = 0;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

