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
bool vis[15];
bool qus[1005];
struct con
{
	int who, num;
	double po;
	friend bool operator < (con a, con b)
	{
		//if(a.po == b.po) return a.who < b.who;
		return a.po < b.po;
	}
}PP[15][1005];
int main()
{
	freopen("input.txt", "r", stdin);
	t = 0;
	scanf("%d", &T);
	while(T--)
	{
		memset(qus, 0, sizeof(qus));
		double ans = 0;
		int cnt = 0;
		priority_queue<con> q;
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
		if(n == 1)
		{
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= m; j++)
					ans += PP[i][j].po;
		}
		else
		{
			if(m >= n)
			{
				for(int k = 1; k <= m / n; k++)
				{
					//q.clear();
					for(int i = 1; i <= n; i++)
						for(int j = (k - 1) * n + 1; j <= k * n; j++)
							q.push(PP[i][j]);
					memset(vis, 0, sizeof(vis));
					while(true)
					{
						con x = q.top();
						if(vis[x.who] == 0 && qus[x.num] == 0)
						{
							cnt++;
							vis[x.who] = 1;
							qus[x.num] = 1;
							//		printf("who = %d po = %lf\n", x.who, x.po);
							ans += x.po;
						}
						q.pop();
						if(cnt == n) break;
					}
					while(!q.empty()) q.pop();
				}
			}
			//q.clear();
			while(!q.empty()) q.pop();
			memset(vis, 0, sizeof(vis));
			cnt = 0;
			for(int i = 1; i <= n; i++)
				for(int j = (m / n) * n + 1; j <= m; j++)
					q.push(PP[i][j]);
			//	int gap = 0;
			//	if(n != 1) gap = m % n;
			//	else gap = m - (m / n) * n;
			while(true)
			{
				con x = q.top();
				if(vis[x.who] == 0 && qus[x.num] == 0)
				{
					//		printf("who = %d po = %lf\n", x.who, x.po);
					cnt++;
					vis[x.who] = 1;
					qus[x.num] = 1;
					ans += x.po;
				}
				q.pop();
				if(cnt == (m % n)) break;
			}
		}
		printf("Case #%d: %.5lf\n", ++t, ans);
		memset(PP, 0,  sizeof(PP));
	}
	return 0;
}
