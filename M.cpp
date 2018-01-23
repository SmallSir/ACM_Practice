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
struct PP
{
	int num, pos;
};

PP a[105], b[105];
bool flag[105];

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(flag, 0, sizeof(flag));
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i].num);
			a[i].pos = i;
		}
		int x;
		scanf("%d", &x);
		for(int i = 1; i <= x; i++)
		{
			int ans;
			scanf("%d", &ans);
			flag[ans] = 1;
		}
		int sum = -1;
		for(int i = 0; i < n; i++)
		{
			if(flag[i] == 0) b[++sum] = a[i];
		}
		int l_, r_, cnt, cnt_ = 300000;
		for(int i = 0; i <= sum - m + 1; i++)
		{
			for(int j = i + 1; j <= i + m - 1; j++)
			{
				cnt = b[i].num;
				cnt += b[j].num;
				if(cnt < cnt_)
				{
					cnt_ = cnt;
					l_ = b[i].pos;
					r_ = b[j].pos;
				}
			}
		}
		printf("%d %d\n", l_, r_);
	}
	return 0;
}
