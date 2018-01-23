//01字典树-查询数列中与给定x的异或最大值
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MaxN = 100005;

int T, n, Q;
int Node[31 * MaxN][2];
int val[31 * MaxN];
int sz;

void Init() {
	sz = 1;
	memset(Node[0], 0, sizeof(Node[0]));
}

void Insert(int x) {
	int cur = 0;
	for(int i = 31; i >= 0; i--) {
		int tmp = (x >> i) & 1;
		if(!Node[cur][tmp])  {
			memset(Node[sz], 0, sizeof(Node[sz]));
			Node[cur][tmp] = sz;
			val[sz] = 0;
			sz++;
		}
		cur = Node[cur][tmp];
	}
	val[cur] = x;
}

int query(int x) {
	int cur = 0;
	for(int i = 31; i >= 0; i--) {
		int tmp = (x >> i) & 1;
		if(Node[cur][tmp ^ 1]) cur = Node[cur][tmp ^ 1];
		else cur = Node[cur][tmp];
	}
	return val[cur];
}

int main()
{
	int t = 0;
	scanf("%d", &T);
	while(T--) {
		Init();
		scanf("%d %d", &n, &Q);
		for(int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			Insert(x);
		}
		printf("Case #%d:\n", ++t);
		for(int i = 1; i <= Q; i++) {
			int x;
			scanf("%d", &x);
			printf("%d\n", query(x));
		}
	}
	return 0;
}
