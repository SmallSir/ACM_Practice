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

int n,m;
vector<int> tu[105],cost[105];
int check[105],dis[105];
void dfs(int x)
{
    queue<int> qua;
    qua.push(x);
    check[x] = 0;
    while(!qua.empty())
    {
        int u = qua.front();
        qua.pop();
        for(int i = 0;i < tu[u].size();i++)
        {
            int k = tu[u][i];
            int c = cost[u][i];
            if(dis[u] + c < dis[k])
            {
                dis[k] = dis[u] + c;
                if(check[k] == 0)
                {
                    check[k] = 1;
                    qua.push(k);
                }
            }
        }
        check[u] = 0;
    }
}
int main(int argc, char const *argv[])
{
    int x,y,c;
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        cin >> x >> y >> c;
        tu[x].push_back(y);
        cost[x].push_back(c);
    }
    for(int i = 0;i <= n;i++)
        dis[i] = (1 << 20);
    int flag = 1 << 20;
    dis[0] = 0;
    dfs(0);
    if(dis[n] == flag)
        cout << -1 << endl;
    else
        cout << dis[n] <<endl;
    return 0;
}