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


/*start:17/5/19 14:54*/
/*end:17/5/19   14:37  */
long long int p,q,x,y,l,r,k,a,b;
int T;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>p>>q;
		l=0;
		r=1e10;
		while(l<r)
		{
			k=(l+r)/2;
			a=k*p-x;
			b=k*q-y;
			if(a>=0&&b>=0&&a<=b)
			{
				//cout<<1111<<endl;
				r=k;
			}
			else
			{
				l=k+1;
			}
		}
		//cout<<r<<endl;
		if(l==1e10)
			cout<<-1<<endl;
		else
			cout<<(r*q-y)<<endl;
	}
}
