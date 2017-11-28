#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long LL;

int T, t;
int n, m;
int vis[15];
struct con
{
	int who, num;
	double po;
	friend bool operator < (con a, con b)
	{
		return a.po < b.po;
	}
}PP[15][1005];
int tot;
double ans;

bool cmp(con x, con y)
{
	return x.po > y.po;
}
bool check(int peo)
{
	vis[peo]++;
	//printf("peopel = %d\n", peo);
	int MIN = 1 << 30;
	for(int i = 1; i <= n; i++)
		MIN = min(MIN, vis[i]);
	//printf("MIN = %d\n", MIN);
	if(vis[peo] - MIN <= 1) return 1;
	else 
	{
		vis[peo]--;
		return 0;
	}
}
int main()
{
	t = 0;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		tot = 0;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%lf", &PP[i][j].po);
				PP[i][j].who = i;
				PP[i][j].num = j;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			printf("2222\n");
			priority_queue<con> q;
			for(int j = 1; j <= n; j++)
				q.push(PP[j][i]);
			printf("11111\n");
			while(!q.empty())
			{
				con x = q.top();
				if(check(x.who)) 
				{
					ans += x.po;
					printf("ans = %lf\n", ans);
					break;
				}
			}
		}
		printf("%.5lf\n", ans);
		memset(PP, 0, sizeof(PP));
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
