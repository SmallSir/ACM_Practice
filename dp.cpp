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


int T,n,v;
int a[1005],b[1005];
int f[1005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&v);
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		for(int i = 1; i <= n; i++) scanf("%d",&b[i]);
		for(int i = 1; i <= n; i++){
			for(int j = v; j >=b[i]; j--){
				f[j] = max(f[j], f[j - b[i]] + a[i]);
			}
		}
		printf("%d\n",f[v]);
	}
}

