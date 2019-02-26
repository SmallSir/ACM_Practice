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

int a[505][505];
int flag[250005];
int b[250005];
int xx[] = {1,0,-1,0};
int yy[] = {0,1,0,-1};
int n,m,sum;
int tt(int x)
{
    if(flag[x] == x)
        return x;
    else
        flag[x] = tt(flag[x]);
    return flag[x];
    
}
void check(int x,int y)
{
    for(int i = 0;i < 4;i++)
    {
        int dx = xx[i] + x;
        int dy = yy[i] + y;
        if(dx < 0 || dx >= n || dy < 0 || dy >= m || a[dx][dy] == 0)
            continue;
        int t = tt(a[dx][dy]);
        int u = tt(a[x][y]);
        if(t != u)
        {
            sum--;
            flag[u] = flag[t];
        }
    }
}

int main(int argc, char const *argv[])
{
    int k,x,y;
    while(cin >> n >> m >> k)
    {
        memset(a,0,sizeof(a));
        sum = 0;
        for(int i = 1;i <= k ;i++)
        {
            cin >> x >> y;
            if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] != 0)
            {
                b[i] = sum;
                continue;
            }
            flag[i] = i;
            a[x][y] = i;
            check(x,y);
            b[i] = ++sum;
        }
        for(int i = 1;i <= k;i++)
        {
            if(i == k)
                cout << b[i] << endl;
            else   
                cout << b[i] << " ";
        }
    }
    return 0;
}