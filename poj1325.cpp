#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=1001;
int map[N][N],vis[N],link[N];
int n1,n2,k;
int find(int x)
{
    int i;
    for(i=1;i<=n2;i++)
    {
        if(map[x][i]&&!vis[i])
        {
            vis[i]=1;
            if(!link[i]||find(link[i]))
            {
                link[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int a,b,c,i,sum;
    while(~scanf("%d",&n1))
    {
        if(!n1)
            break;
        scanf("%d%d",&n2,&k);
        sum=0;
        memset(map,0,sizeof(map));
        memset(link,0,sizeof(link));
        while(k--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(b*c)
                map[b][c]=1;
        }
        for(i=1;i<=n1;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
            {
            	sum++;
            	printf("%d\n",i);
			}
        }
        printf("%d\n",sum);
    }
    return 0;
}
