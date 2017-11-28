#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MaxN = 2e5;
int n,k,x,y,a[MaxN + 5];
char C;
int num[MaxN + 5];

struct segtree{
	int l ,r;
	int MAX;
}tree[4 * MaxN + 5];

void Build(int rt,int l,int r){
	tree[rt].l = l; tree[rt].r = r;
	if(l == r) {
		tree[rt].MAX = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build(rt << 1,l,mid);
	Build(rt << 1 | 1, mid + 1, r);
	tree[rt].MAX = min(tree[rt << 1].MAX , tree[rt << 1 | 1].MAX);
}

int query(int rt, int L, int R){
	if(R < tree[rt].l || L > tree[rt].r) return MaxN + 1000;
	if(L <= tree[rt].l && R >= tree[rt].r) return tree[rt].MAX;
	int mid = (L + R) / 2;
	int a = query(rt << 1, L, mid);
	int b =  query(rt << 1 | 1, mid + 1, R);
	return min(a, b);
}

void update(int rt, int pos, int val)
{
	if(tree[rt].l == tree[rt].r) {
		if(pos == tree[rt].l)
			tree[rt].MAX += val;
		return;
	}
	int mid = (tree[rt].l + tree[rt].r) / 2;
	if(pos <= mid) update(rt << 1, pos, mid);
	else update(rt << 1 | 1, mid + 1, val);
	tree[rt].MAX = min(tree[rt << 1].MAX , tree[rt << 1 | 1].MAX);
}

int main()
{
//	freopen("nice.in","r",stdin);
//	freopen("nice.out","w",stdout);
	while(~scanf("%d %d",&n,&k)){
		int pos = 0;
		for(int i = 0; i <= n; i++) a[i] = MaxN + 5;
		Build(0,0,n);
		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);
			num[x]++;
			update(0,x,1);
			int ans = query(0, 0, x - 1);
			if(x == 0)
			{
				pos = i;
				continue;
			}
			if(ans < num[x] - k) break;
			else pos = i;
		}
		printf("%d\n", pos);
	}
	return 0;
}
