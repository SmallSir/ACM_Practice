#include <iostream>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>  
#include <queue>  
#define MAXN 1005  
#define MAXM 500005  
#define INF 1000000000  
using namespace std;  

vector<int> tu[500005],rtu[500005],ccost[500005],cost[500005];
struct A  
{  
    int f, g, v;  
    bool operator <(const A a)const {  
        if(a.f == f) return a.g < g;  
        return a.f < f;  
    }  
};  
int e, vis[MAXN], d[MAXN], q[MAXM * 5];  
int head[MAXN], revhead[MAXN];  
int n, m, s, t, k;  
void insert(int x, int y, int w)  
{  
   tu[x].push_back(y);
   cost[x].push_back(w);
   rtu[y].push_back(x);
   ccost[y].push_back(w);
}  
void spfa(int src)  
{  
    for(int i = 1; i <= n; i++) d[i] = INF;  
    memset(vis, 0, sizeof(vis));  
    vis[src] = 0;  
    int h = 0, t = 1;  
    q[0] = src;  
    d[src] = 0;  
    while(h < t)  
    {  
        int u = q[h++];  
        vis[u] = 0;  
        for(int i = 0;i<rtu[u].size();i++)  
        {  
            int v = rtu[u][i];
            int w = ccost[u][i];
            if(d[v] > d[u] + w)  
            {  
                d[v] = d[u] + w;  
                if(!vis[v])  
                {  
                    q[t++] = v;  
                    vis[v] = 1;  
                }  
            }  
        }  
    }  
}  
int Astar(int src, int des)  
{  
    int cnt = 0;  
    priority_queue<A>Q;  
    if(src == des) k++;  
    if(d[src] == INF) return -1;  
    A t, tt;  
    t.v = src, t.g = 0, t.f = t.g + d[src];  
    Q.push(t);  
    while(!Q.empty())  
    {  
        tt = Q.top();  
        Q.pop();  
        if(tt.v == des)  
        {  
            cnt++;  
            if(cnt == k) return tt.g;  
        }  
        for(int i=0;i<tu[tt.v].size();i++)  
        {  
            t.v = tu[tt.v][i];
            t.g = tt.g + cost[tt.v][i];  
            t.f = t.g + d[t.v];
            Q.push(t); 
        }  
    }  
    return -1;  
}  
int main()  
{  
    int x, y, w;  
   scanf("%d%d", &n, &m) ;
        for(int i = 1; i <= m; i++)  
        {  
            scanf("%d%d%d", &x, &y, &w);  
            insert(x, y, w);  
        }  
        scanf("%d%d%d", &s, &t, &k); 
        spfa(t);  
        printf("%d\n", Astar(s, t));  
    return 0;  
}   
