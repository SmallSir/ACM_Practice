#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map>  
using namespace std; 

vector<int>tree[100003];
int t,f;
vector<long long int>lu[100003];
long long int ma,l,sum;
long long int check[100003];
long long int dis[100003],a[100003];
int n;

int bfs(int x)
{
    int i,k,ans;
    ma=0;
    memset(dis,0,sizeof(dis));
    memset(check,0,sizeof(check));
    queue<int> qua;
    qua.push(x);
    dis[x]=0;
    check[x]=x;
    while(!qua.empty())
    {
        //cout<<11111111111111<<endl;
        k=qua.front();
        qua.pop();
        for(i=0;i<tree[k].size();i++)
        {
            int ss=tree[k][i];
            if(check[ss]==0)
            {
                check[ss]=k;
                qua.push(ss);
                dis[ss]=dis[k]+lu[k][i];
                if(ma<dis[ss])
                {
                //	cout<<"ss"<<ss<<endl;
                    ans=ss;
                    ma=dis[ss];
                }
            }
        }
    }
    return ans;
}
int main()
{
	int i,x,y,k;
    while(~scanf("%d", &n))
    {
    	memset(tree,0,sizeof(tree));
    	memset(lu,0,sizeof(lu));
    	memset(check,0,sizeof(check));
        for(i=1;i<n;i++)
        {
            scanf("%d%d%I64d", &x, &y, &l);
            tree[x].push_back(y);
            lu[x].push_back(l);
			tree[y].push_back(x);
            lu[y].push_back(l);
        }
        t=f=0;
        t=bfs(1);
       // cout<<"---------------"<<endl;
        f=bfs(t);
        //cout<<t<<" "<<f<<endl;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
           a[i]=max(dis[i],a[i]);
        }
        sum=0;
        bfs(f);
        for(i=1;i<=n;i++)
        {
            a[i]=max(a[i],dis[i]);
            sum+=a[i];
        }
        sum-=ma;
        printf("%I64d\n", sum);
    }
    return 0;
}
