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
#define inf 9999999;
using namespace std;
typedef long long LL;

int n,T;
int fa[100005],rank[100005];

int getf(int x)
{
	if(x==fa[x])
		return x;
	int k=getf(fa[x]);
	rank[x]+=rank[fa[x]];
	return fa[x]=k;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		rank[i]=0;
	}
}
int main()
{
	char s;
	int t1,t2;
	int x,y,l,i;
	for(;;)
	{
		scanf("%d%d",&n,&T);
		init();
		if(n==0&&T==0)
			break;
		while(T--)
		{
			scanf("%s",&s);
			//cin>>s;
			if(s=='!')
			{
				scanf("%d%d%d",&x,&y,&l);
				t1=getf(x);
				t2=getf(y);
				if(t1!=t2)
				{
					fa[t2]=t1;	
					rank[t2]=rank[x]+l-rank[y];
				}
				
			}
			else
			{
				scanf("%d%d",&x,&y);
				t1=getf(x);
				t2=getf(y);
				if(t1!=t2)
					printf("UNKNOWN\n");
					else
					printf("%d\n",rank[y]-rank[x]);
					//cout<<rank[y]-rank[x]<<endl;;
			}
		}
	}
}
