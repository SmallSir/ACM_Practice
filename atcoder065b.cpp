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

int a[100005];
int n,i,sum;
bool flag[100005];
bool check(int x)
{
	if(flag[x]!=true)
	{
		sum++;
		flag[x]=true;
		if(x==2)
			return true;
		else
			check(a[x]);
	}
	else
	{
		return true;
	}
	return true;

}
int main()
{
	cin>>n;
	memset(flag,false,sizeof(flag));
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum=0;
	check(1);
	if(flag[2]==true)
		cout<<sum-1<<endl;
	else
		cout<<-1<<endl;
}
