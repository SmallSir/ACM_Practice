#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int n,x1, x2, x3;
bool vis[210][210];

struct pp
{
    int x, y;
}a[505];

int cmp(pp c, pp d){
	if(c.x == d.x) return c.y < d.y;
	return c.x < d.x;
}

int check(int q, int w, int e, int r){
	if(q < 0 || q > 100 || w < 0 || w > 100 || e < 0 || e > 100 || r < 0 || r > 100) return true;
	return false;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &a[i].x, &a[i].y);
            a[i].x += 100; a[i].y += 100;
            vis[a[i].x][a[i].y] = 1;
        }
        sort(a + 1, a + n + 1, cmp);
        int cnt = 0;
        for(int i = 1; i <= n - 3; i++) {
            for(int j = i + 1; j <= n - 2; j++) {
           // 	if(a[i].x < a[j].x && a[i].y < a[j].y){
            		int x1 = a[j].x - a[i].x;
            		int y1 = a[j].y - a[i].y;
            		if(check(a[i].x + y1,a[i].y - x1, a[j].x + y1, a[j].y - x1)) continue; 
            		if(vis[a[i].x + y1][a[i].y + x1] && vis[a[j].x + y1][a[j].y + x1]) cnt++;
			/*	}
				else if(a[i].x >= a[j].x && a[i].y >= a[j].y){
					int x1 = a[j].x - a[i].x;
					int y1 = a[i].y - a[j].y;
					if(vis[a[j].x + y1][a[j].y + x1] && vis[a[i].x + y1][a[i].y+ x1]) cnt++;
                }
                else if(a[i].x == a[j].x){
                    int x1 = a[j].x - a[i].x;
            		int y1 = a[j].y - a[i].y;
            		if(vis[a[i].x + y1][a[i].y] && vis[a[j].x + y1][a[j].y]) cnt++;
				}
				else if(a[i].y == a[j].y){ 
					int x1 = a[j].x - a[i].x;
            		int y1 = a[j].y - a[i].y;
                    if(vis[a[i].x][a[i].y + x1] && vis[a[j].x][a[j].y + x1]) cnt++;
                }
            */}
		}
        printf("%d\n", cnt);
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}



