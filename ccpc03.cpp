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

int ans,n;
vector<int> tu[3005],ru[3005];
int a[3005],check[3005],vis[3005];
void dfs(int x)
{
    int k;
    for(int i=0;i<tu[x].size();i++)
    {
        k=tu[x][i];
        if(check[k]==0)
        {
            check[k]=ans;
            dfs(k);
        }
    }
}
void rfs(int x)
{
    int k;
    for(int i=0;i<ru[x].size();i++)
    {
        k=ru[x][i];
        if(check[k]==0)
        {
            check[k]=ans;
            rfs(k);
        }
    }

}
bool ddfs(int x,int y)
{
    vis[x]=-1;
    bool flag=1;
    int k;
    for(int i=0;i<tu[x].size();i++)
    {
        k=tu[x][i];
        if(k==y)
            continue;
        if(vis[k]==-1)
            return false;
        else if(vis[k]==0)
        {
            flag=ddfs(k,x);
            if(flag==0)
                return 0;
        }
    }
    vis[x]=1;
    return true;
}
bool rrfs(int x,int y)
{
    vis[x]=-1;
    bool flag=1;
    int k;
    for(int i=0;i<ru[x].size();i++)
    {
        k=ru[x][i];
        if(k==y)
            continue;
        if(vis[k]==-1)
            return false;
        else if(vis[k]==0)
        {
            flag=rrfs(k,x);
            if(flag==0)
                return 0;
        }
    }
    vis[x]=1;
    return true;
}
int main()
{
    int T,i,j,x;
    //cin>>T;
    scanf("%d",&T);
    bool flag;
    while(T--)
    {
        memset(tu,0,sizeof(tu));
        memset(ru,0,sizeof(ru));
    //    cin>>n;
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            for(j=1;j<=n-i;j++)
            {
                scanf("%d",&x);
                //cin>>x;
                if(x==0)
                {
                    ru[j+i].push_back(i);
                    ru[i].push_back(i+j);
                }
                else
                {
                    tu[i].push_back(i+j);
                    tu[i+j].push_back(i);
                }
            }
        }
        flag=false;
        memset(check,0,sizeof(check));
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(!check[i])
            {
                ans++;
                check[i]=ans;
                dfs(i);
            }
        }
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
            a[check[i]]++;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=-1;
                if(!ddfs(i,0)&&a[check[i]]>=3)
                {
                    flag=true;
                    break;
                }
                vis[i]=1;
            }
        }
        if(flag)
        {
            printf("Bad Team!\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        memset(check,0,sizeof(check));
        memset(a,0,sizeof(a));
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(check[i]==0)
            {
                ans++;
                check[i]=ans;
                rfs(i);
            }
        }
        for(i=1;i<=n;i++)
            a[check[i]]++;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=-1;
                if(!rrfs(i,0)&&a[check[i]]>=3)
                {
                    flag=1;
                    break;
                }
                vis[i]=1;
            }
        }
        if(flag)
        {
            printf("Bad Team!\n");
            continue;
        }
        printf("Great Team!\n");

    }
    return 0;
}
