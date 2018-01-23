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
#include<stack>
using namespace std;
typedef long long LL;


struct point
{
    LL l,r;
}a[100005],c[100005];
struct pp
{
    int flag;
    int index;
    LL k;
}b[100005];
int n,sum,MAX,T;
int check[100005];
bool cmp(pp x,pp y)
{
    if(x.k==y.k)
    {
        return x.flag<y.flag;
    }
    return x.k<y.k;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int i,j,pos;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(check,0,sizeof(check));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            c[i].l=1<<30;
            c[i].r=0;
        }
        pos=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i].l,&a[i].r);
            b[++pos].k=a[i].l;
            b[pos].index=i;
            b[pos].flag=0;
            b[++pos].k=a[i].r-1;
            b[pos].flag=1;
            b[pos].index=i;
        }
        sort(b+1,b+1+pos,cmp);
        MAX=0;
        sum=0;
        for(i=1;i<=pos;i++)
        {
            if(b[i].flag==0)
                sum++;
            else
                sum--;
            MAX=max(MAX,sum);
        }
        sum=0;
        stack<int>sta;
        for(i=pos;i>=1;i--)
            sta.push(i);
        for(i=1;i<=pos;i++)
        {
            if(b[i].flag==0)
            {
                check[b[i].index]=sta.top();
                sta.pop();
            }
            else
            {
                sta.push(check[b[i].index]);
            }
        }
        for(i=1;i<=pos;i++)
        {
            int k=check[b[i].index];
            if(b[i].flag==0)
            {
                c[k].l=min(c[k].l,b[i].k);
            }
            else
            {
                c[k].r=max(c[k].r,b[i].k+1);
            }
        }
        LL cnt=0;
        for(i=1;i<=MAX;i++)
        {
            cnt+=c[i].r-c[i].l;
        }
        printf("%d %lld\n",MAX,cnt);
    }
    return 0;
}


