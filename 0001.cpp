#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MM = 1e7;
const int Max = 2e5 + 5;

int n, prime[MM], tot;

int flag[MM + 5];
struct pp {
	double x,y;
}a[1005],b[1005];

int main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lf%lf",&b[i].x, &b[i].y);
	}
	double xx = a[1].x - b[1].x,yy = a[1].y - b[1].y;
	for(int i = 1; i <= n; i++){
		b[i].x += xx;
		b[i].y += yy;
	}
	double bb = (a[1].x - a[2].x)* (a[1].x - a[2].x) + (a[1].y - a[2].y) * (a[1].y - a[2].y);
	double cc = (a[1].x - b[2].x)* (a[1].x - b[2].x) + (a[1].y - b[2].y) * (a[1].y - b[2].y);
	double aa = (a[2].x - b[2].x)* (a[2].x - b[2].x) + (a[2].y - b[2].y) * (a[2].y - b[2].y);
    double ha = (bb + cc - aa) / (2 * sqrt(bb * cc));
    double ans = acos(ha);
    printf("%.10lf\n",ans);
	return 0;
}
