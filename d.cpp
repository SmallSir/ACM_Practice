#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
 
const int MaxN = 2e5, MaxM = 4e6;
int X, all, tot;
int pre[MaxM + 5], last[MaxN + 5], other[MaxM + 5], cost[MaxM + 5];
int dis_1[MaxN + 5], dis_2[MaxN + 5];
int seq[MaxM + 5];
bool Inseq[MaxN + 5];
struct EDGE {
	int u, v, w;
}edge[MaxM + 5];
 
void Build(int x, int y, int w)
{
	pre[++all] = last[x];
	last[x] = all;
	other[all] = y;
	cost[all] = w;
}
 
void Init()
{
	all = -1; memset(last, -1, sizeof(last));
	tot = 0;
	for (int i = 0; i < X; i++) {
		for (int d = 0; d <= 9; d++) {
			int now = (i * 10 + d) % X;
			Build(i, now, d);
			edge[++tot].u = i;
			edge[tot].v = now;
			edge[tot].w = d;
		}
	}
}
 
void Spfa(int s, int dis[])
{
	for (int i = 0; i <= X; i++) dis[i] = 1 << 30; 
	dis[s] = 0; memset(Inseq, 0, sizeof(Inseq));
	int head = 1, tail = 0;
	seq[++tail] = s; Inseq[s] = true;
	while (head <= tail) {
		int now = seq[head];
		int ed = last[now], dr;
		while (ed != -1) {
			dr = other[ed];
			if (dis[now] + cost[ed] < dis[dr]) {
				dis[dr] = dis[now] + cost[ed];
				if (!Inseq[dr]) {
					seq[++tail] = dr;
					Inseq[dr] = true;
				}
			}
			ed = pre[ed];
		}
		head++;
		Inseq[now] = false;
	}
}
 
void Solve()
{
	Spfa(0, dis_1);
	all = -1; memset(last, -1, sizeof(last));
	for (int i = 1; i <= tot; i++) Build(edge[i].v, edge[i].u, edge[i].w);
	Spfa(0, dis_2);
	int ans = 1 << 30;
	for (int i = 1; i <= X - 1; i++) ans = min(ans, dis_1[i] + dis_2[i]);
	printf("%d\n", ans);
}
 
int main()
{
	while (~scanf("%d", &X)) {
		Init();
		Solve();
	}
	return 0;
}
