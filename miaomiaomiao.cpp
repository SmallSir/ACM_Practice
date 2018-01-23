#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
bool vis[210][210];
struct point
{
    int x, y;
}PP[505];
struct Vector
{
    int x, y;
};

int check(int a, int b, int c) //mid is a
{
    Vector ab;
    ab.x = PP[b].x - PP[a].x;
    ab.y = PP[b].y - PP[a].y;

    Vector ac;
    ac.x = PP[c].x - PP[a].x;
    ac.y = PP[c].y - PP[a].y;

    int tmp = ac.x * ab.x + ac.y * ab.y;
    if(tmp == 0) return 1;
    else return 0;
}

bool judge(int a, int b, int c)
{
    Vector ab;
    ab.x = PP[b].x - PP[a].x;
    ab.y = PP[b].y - PP[a].y;
    //printf("ab.x = %d ab.y = %d\n", ab.x, ab.y);

    Vector ac;
    ac.x = PP[c].x - PP[a].x;
    ac.y = PP[c].y - PP[a].y;
    //printf("ac.x = %d ac.y = %d\n", ac.x, ac.y);

    int lab = ab.x * ab.x + ab.y * ab.y;
    int lac = ac.x * ac.x + ac.y * ac.y;
    //printf("lab = %d lac = %d\n", lab, lac);

    Vector ad; //¶Ô½Ç
    ad.x = ab.x + ac.x;
    ad.y = ab.y + ac.y;

    point d;
    d.x = ad.x + PP[a].x;
    d.y = ad.y + PP[a].y;
    //printf("d.x = %d d.y = %d\n", d.x, d.y);
    if(lab == lac && vis[d.x + 101][d.y + 101] == 1) return 1;
    else return 0;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &PP[i].x, &PP[i].y);
            vis[PP[i].x + 101][PP[i].y + 101] = 1;
        }
        /*for(int i = 101; i <= 105; i++) {
            for(int j = 101; j <= 105; j++) {
                printf("%d ", vis[i][j]);
            }
            printf("\n");
        }*/
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                for(int k = j + 1; k <= n; k++) {
                    if(i != j && j != k && i != k) {
                        int mid = i, l = j, r = k;
                        if(check(i, j, k)) {
                            //printf("i = %d j = %d k = %d\n", i, j, k);
                            if(judge(mid, l, r)) cnt++;
                        }
                        //if(check(i, j, k)) mid = i, l = j, r = k;
                        //else if(check(j, i, k)) mid = j, l = i, r = k;
                        //else if(check(k, i, j)) mid = k, l = i, r = j;
                    }
                }
            }
        }
        printf("%d\n", cnt);

        memset(vis, 0, sizeof(vis));
        memset(PP, 0, sizeof(PP));
    }
    return 0;
}
