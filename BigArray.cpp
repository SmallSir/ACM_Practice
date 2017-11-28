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


/*start:17/5/19 16:09*/
/*end:17/5/19   16:32  */

int n,i,x;
long long int y,k;
long long int a[100005];
int  main()
{
	cin>>n>>k;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[x]+=y;
	}
	for(i=0;i<=100000;i++)
	{
		if(k<=a[i])
		{
		//	cout<<k<<endl;
		//	cout<<a[i];
			cout<<i<<endl;
			return 0;
		}
		k-=a[i];
	}
}

