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
const int MaxN = 1e5;

int n, all;
int pre[2 * MaxN + 5], last[2 * MaxN + 5], other[2 * MaxN + 5];
int dep[MaxN + 5];
bool vis[MaxN + 5];
int cnt[MaxN + 5];

void build(int x, int y)
{
	pre[++all] = last[x];
	last[x] = all;
	other[all] = y;
}

void Dfs(int x, int fa) {
	int ed, dr;
	ed = last[x];
	bool f = 0;
	while(ed != -1) {
		dr = other[ed];
		if(dr != fa) {
			f = 1;
			dep[dr] = dep[x] + 1;
			Dfs(dr, x);
		}
		ed = pre[ed];
	}
	if(f == 0) vis[x] = 1;
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		all = -1; memset(last, -1, sizeof(last));
		for(int i = 1; i < n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			build(u, v); build(v, u);
		}
		dep[1] = 0;
		Dfs(1, 0);
		for(int i = 1; i <= n; i++) {
			if(vis[i] == 1) {
				cnt[dep[i]]++;
			}
		}
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
				sum += cnt[i];
		}
		//printf("sum = %d\n", sum);
		double ans = 0.00;
		for(int i = 1; i <= n; i++) {
				ans += (((1.0 * i) / (1.0 * sum) ) * 1.0 * cnt[i]);
		}
		if(n == 1) printf("1.000000000000000\n");
		else printf("%.15lf\n", ans);
	}
	return 0;
}

