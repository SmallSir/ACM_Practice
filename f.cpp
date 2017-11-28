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
LL n;
int num[15];
int ans[30];
int tmp[30];
void get(LL x)
{
	int tot = 0;
	while(x > 0)
	{
		num[++tot] = x % 10;
		x = x / 10;
	}
	num[0] = tot;
	//for(int i = 1; i <= num[0] / 2; i++)
	//	swap(num[i], num[num[0] - i + 1]);
	/*for(int i = 1; i <= num[0]; i++)
		printf("%d ", num[i]);
	printf("\n");*/
}
void getans()
{
	for(int i = 1; i <= num[0]; i++) //8n
		tmp[i] = num[i] * 8;
	tmp[1] -= 7;
	int pa = 1;
	while(tmp[pa] < 0)
	{
		tmp[pa] += 10;
		tmp[pa + 1] -= 1;
		pa++;
	}
	int pos = 25;
	while(tmp[pos] == 0) {pos--;}
	for(int i = 1; i <= num[0]; i++)
	{
		for(int j = 1; j <= pos; j++)
		{
			ans[i + j - 1] = num[i] * tmp[j];
		}
	}
	ans[1] += 1;
	int p = 1;
	while(ans[p] >= 10)
	{
		ans[p + 1] += ans[p] / 10;
		ans[p] = ans[p] % 10;
		p++;
	}
	int pp = 25;
	while(ans[pp] == 0) {pp--;}
	for(int i = pp; i >= 1; i--)
		printf("%d", ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &n);
		get(n);
		getans();
		memset(ans, 0, sizeof(ans));
		memset(tmp, 0, sizeof(tmp));
		memset(num, 0, sizeof(num));
	}
}
