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
 
vector<int> tu[10005];
int n,m;
int flag[10005];
int check[10005];
int b[10005];
int a[10005];
int dfs(int x)
{
    int u = 0;
    flag[x] = 1;
    for(int i = 0;i<tu[x].size();i++)
    {
        int k = tu[x][i];
        if(flag[k] == 1||check[k] == 1)
        {
            check[x] = 1;
            flag[x] = 0;
            return 1;
        }
        u = max(u,dfs(k));
    }
    flag[x] = 0;
    check[x] = u;
    return u;
}
int main(int argc, char const *argv[])
{
    int x,y;
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d,%d",&x,&y);
        tu[x].push_back(y);
        a[y] = 1;
    }
    int k = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0)
        {
            k++;
            check[i] = dfs(i);
        }
    }
    if(k == 0)
    {
        cout << "None" <<endl;
        return 0;
    }
    int cum = 0;
    for(int i = 1;i <= n;i++)
    {
        if(check[i] == 0)
        {
            b[++cum] = i;
        }
    }
    for(int i = 1;i<=cum;i++)
    {
        if(i == cum)
            cout << b[i] <<endl;
        else
        {
            cout << b[i] << " ";
        }
    }
    if(cum == 0)
        cout << "None" <<endl;
}
