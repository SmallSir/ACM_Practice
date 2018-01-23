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

struct point
{
	int index,value;
}a[100005],b[100005];
bool cmp(point x,point y)
{
	return x.value<y.value;
}
int i,n;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].value;
		a[i].index=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)
	{
		cin>>b[i].value;
		b[i].index=i;
	}
	sort(b+1,b+1+n,cmp);
	if(a[1].index!=b[1].index)
		cout<<a[1].value+b[1].value<<endl;
	else
		cout<<min(a[1].value+b[2].value,b[1].value+a[2].value)<<endl;
}
	
