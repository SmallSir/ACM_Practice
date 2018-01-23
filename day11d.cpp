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

int n,k,cnt,i;
int main()
{
	cin>>n>>k;
	//long long int cnt;
	bool flag=0;
	for(i=1;i<n;i++)
	{
		cnt+=i;
		if(k<cnt)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"no solution"<<endl;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		cout<<0<<" "<<i<<endl;
	}
	dfs(1);

}
