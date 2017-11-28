#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MaxN = 1e5;

double a[MaxN + 5];
int n, q;

int lowbit(int p) {return p & -p;}

void add(int p, double x){
	while(p <= (n + 1)){
		a[p] += x;
		p += lowbit(p);
	}
}

double query(int p){
	double ans = 0;
	while(p > 0){
		ans += a[p];
		p -= lowbit(p);
	}
	return ans;
}
int main(){
	while(~scanf("%d %d", &n, &q)){
		for(int i = 1; i <= n; i++){
			double x;
			scanf("%lf", &x);
			add(i, x);
			add(i + 1, -x);
		}
		for(int i = 1; i <= q; i++){
			int v;
			scanf("%d", &v);
			if(v == 1){
				int p;
				scanf("%d", &p);
				printf("%.10lf\n", query(p));
			}
			else if(v == 0){
				int p;
				double x;
				scanf("%d %lf", &p, &x);
				add(p, x);
				add(p + 1, -x);
				add(1, -x / (n - 1));
				add(p, +(x / ( n - 1)));
				add(p + 1, -x / ( n - 1));
			}
		}
	}
	return 0;
}
				


