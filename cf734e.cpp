#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<vector>  
#include<queue>  
using namespace std;  
#define rep(i,a,n) for (int i=a;i<n;i++)  
#define per(i,a,n) for (int i=n-1;i>=a;i--)  
#define pb push_back  
#define mp make_pair  
#define fi first  
#define se second  
typedef vector<int> VI;  
typedef long long ll;  
typedef pair<int,int> PII;  
const ll mod=1000000007;  
const int MAXN=2E5+100;  
struct node  
{  
    int to,next;  
}e[2*MAXN];  
int tol=0;  
int head[MAXN];  
void add(int u,int v)  
{  
    e[++tol].to=v,e[tol].next=head[u],head[u]=tol;  
    e[++tol].to=u,e[tol].next=head[v],head[v]=tol;  
}  
int c[MAXN];  
PII dfs(int u,int fa,int d)  
{  
    PII tmp=make_pair(d,u),t;  
    for(int i=head[u];i;i=e[i].next)  
    {  
        int v=e[i].to;  
        if(v==fa) continue;  
        if(c[u]==c[v]) t=dfs(v,u,d);  
        else t=dfs(v,u,d+1);  
        tmp=max(tmp,t);  
    }  
    return tmp;  
}  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        tol=0;  
        rep(i,1,n+1) scanf("%d",&c[i]);  
        rep(i,1,n)   
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            add(u,v);  
        }  
        PII t=dfs(1,-1,0);  
        PII tt=dfs(t.second,-1,0);  
        printf("%d %d\n",tt.first,(tt.first+1)/2);  
    }  
    return 0;  
}  
