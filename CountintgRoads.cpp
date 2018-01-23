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


/*start:17/5/19 16:00*/
/*end:17/5/19   16:58  */

int i,x,y,n,m;
int b[55];
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		b[x]++;
		b[y]++;
	}
	for(i=1;i<=n;i++)
	{
		cout<<b[i]<<endl;
	}
}

