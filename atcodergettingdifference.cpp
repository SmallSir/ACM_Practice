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

int n,i,k;
int a[1005];
double cnt,sum,MIN;
int main()
{
	cin>>n;
	sum = 0;
	for( i = 1;i <= n;i ++) 
	{
		cin >> a[i];
		sum += a[i];
	}
	double ans = (double)(sum / n);
	MIN=1<<15;
	for (i = 1 ;i <= n; i ++)
	{
		cnt = abs(a[i]-ans);
		if(cnt < MIN )
		{
			MIN = cnt;
			k = i;
		}
	}
	cout<<k<<endl;

}
