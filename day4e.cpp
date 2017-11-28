#include<iostream>  
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<climits>   
#include<cmath>
#include<stack>
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

int a[1000005];
bool b[1000005];
int n,i,m,sum,x;
stack<int> sta;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
		//a[i].pos=i;
	}
	cin>>m;
	for(i=1;i<=m;i++)
	{
		//cin>>x;
		scanf("%d",&x);
		b[x]=1;
	}
	sum=0;
	for(i=n;i>=1;i--)
	{
		//if(b[i]==1)
		//	a[i]=-a[i];
		if(sta.empty() || a[i] != a[sta.top()]||b[i]==1)
		{
		//cout<<i<<endl;
			sta.push(i);
			b[i] = 1;
		}
		else {
			sta.pop();
		}
	}
	if(!sta.empty())
	{
		cout<<"NO"<<endl;
	}
	else
	{
		printf("YES\n");
		//cout<<"YES"<<endl;
		for(i=1;i<=n;i++)
		{
			//cout<<a[i]<<" ";
			if(b[i] == 1)
				printf("%d ",-a[i]);
			else printf("%d ", a[i]);
		}
		//cout<<a[i]<<endl;
		printf("\n");
	}
}
