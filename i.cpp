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
struct domi
{
	int xh, yh;
	int xt, yt;
};
domi hor[1005];
domi ver[1005];
int num[105][105];
int main()
{
	while(scanf("%d %d", &n, &m) == 2)
	{
		if(n == 0 && m == 0) break;
		int ans = n + m;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d", &hor[i].xh, &hor[i].yh);
			hor[i].xt = hor[i].xh + 1;
			hor[i].yt = hor[i].yh;
			num[hor[i].xh][hor[i].yh]++;
			num[hor[i].xt][hor[i].yt]++;
		}
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d", &ver[i].xh, &ver[i].yh);
			ver[i].xt = ver[i].xh;
			ver[i].yt = ver[i].yh + 1;
			num[ver[i].xh][ver[i].yh]++;
			num[ver[i].xt][ver[i].yt]++;
		}
		for(int i = 1; i <= n; i++)
		{
			if(num[hor[i].xh][hor[i].yh] == 2 && num[hor[i].xt][hor[i].yt] == 2)
			{
				ans--;
				num[hor[i].xh][hor[i].yh]--;
				num[hor[i].xt][hor[i].yt]--;
			}
		}
		int cnt = 0;
		for(int i = 0; i <= 101; i++)
			for(int j = 0; j <= 101; j++)
				if(num[i][j] > 1)
					cnt++;
		printf("%d\n", ans - cnt);
		memset(hor, 0, sizeof(hor));
		memset(ver, 0, sizeof(ver));
		memset(num, 0, sizeof(num));
	}
	return 0;
}
