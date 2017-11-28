#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;

int n, m;
int num[105][105];
//int bb[5];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int cnt;
bool check(int x, int y)
{
	if(x < 0 || x > 101) return 0;
	if(y < 0 || y > 101) return 0;
	return 1;
}
void dfs(int x, int y)
{
		for(int i = 1; i <= 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(check(nx, ny) && num[nx][ny] >= 2)
			{
				cnt += num[x][y] + num[nx][ny] - 4;
				num[x][y] = 2;
				num[nx][ny] = 2;
			}
		}
}
void dfs2(int x, int y)
{
	for(int i = 1; i <= 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(check(nx, ny) && num[nx][ny] == 2)
		{
		//	printf("nx = %d ny = %d\n", nx, ny);
			cnt++;
			num[x][y] = 1;
			num[nx][ny] = 1;
		}
	}
}
int main()
{
	while(scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0) break;
		cnt = 0;
	//	int MAXx = 0, MAXy = 0;
	//	int MINx = 1 << 20, MINy = 1 << 20;
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			num[x][y]++;
			num[x + 1][y]++;
		}
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			num[x][y]++;
			num[x][y + 1]++;
		}
		//printf("num[1][1] = %d num[2][1] = %d\n", num[1][1], num[2][1]);
		for(int i = 0; i <= 101; i++)
		{
			for(int j = 1; j <= 101; j++)
			{
				if(num[i][j] > 2)
				{
					dfs(i, j);
				}
			}
		}
		//printf("cnt = %d\n", cnt);
	//	printf("num[1][1] = %d num[2][1] = %d\n", num[1][1], num[2][1]);
		for(int i = 0; i <= 101; i++)
		{
			for(int j = 0; j <= 101; j++)
			{
				if(num[i][j] == 2)
				{
					dfs2(i, j);
				}
			}
		}
		for(int i = 0; i <= 101; i++)
			for(int j = 0; j <= 101; j++)
				if(num[i][j] == 2)
					cnt++;
		//printf("cnt = %d\n", cnt);
		printf("%d\n", n + m - cnt);
		memset(num, 0, sizeof(num));
	}
	return 0;
}
