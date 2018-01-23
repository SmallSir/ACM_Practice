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
const int MaxN = 1e6;

int n, m, x;
int pre[MaxN], other[MaxN], last[MaxN], all;
LL cost[MaxN], dis[10005];
int seq[MaxN];
bool Inque[MaxN];
double sum;
bool vis[10005];

void Build(int x, int y, LL w)
{
	pre[++all] = last[x];
	last[x] = all;
	other[all] = y;
	cost[all] = w;
}

void bfs(int s)
{
	int head = 1, tail = 1, now, ed, dr;
	seq[tail] = s;
	for(int i = 1; i <= n; i++)
		if(i == s) dis[i] = 0;
		else dis[i] = 1ll << 60;
	Inque[s] =  1;
	while(head <= tail) {
		now = seq[head];
		ed = last[now];
		while(ed != -1) {
			dr = other[ed];
			if(dis[now] + cost[ed] < dis[dr]) {
				dis[dr] = dis[now] + cost[ed];
				if(!Inque[dr]) {
					Inque[dr] = 1;
					seq[++tail] = dr;
				}
			}
			ed = pre[ed];
		}
		Inque[now] = 0;
		head++;
	}
}

LL ans;
bool f = 0;
void dfs(int x, int fa, LL mid)
{
	if(ans <= sum && x == n) f = 1;
	if(vis[x]) return;
	vis[x] = 1;
	int ed, dr;
	ed = last[x];
	while(ed != -1) {
		ans += cost[ed];
		dr = other[ed];
		if(dr != fa && cost[ed] <= mid && !vis[dr]) {
			dfs(dr, x, mid);
		}
		ans -= cost[ed];
		ed = pre[ed];
	}
	vis[x] = 0;
}

bool check(LL mid)
{
	ans = 0;
	f = 0;
	memset(vis, 0, sizeof(vis));
	dfs(1, 0, mid);
	if(f) return 1;
	return 0;
}

int main()
{
	LL Min = 1ll << 30, Max = 0ll;
	scanf("%d%d%d", &n, &m, &x);
	all = -1;
	memset(last, -1, sizeof(last));
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		LL w;
		scanf("%d%d%lld", &x, &y, &w);
		Max = Max > w ? Max : w;
		Min = Min < w ? Min : w;
		Build(x, y, w);
		Build(y, x, w);
	}
	bfs(1);
	sum = dis[n] * 1.0 * (1 + x * 1.0 / 100);
	LL l = Min, r = Max, mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(!(check(mid))) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", l);
    return 0;
}
