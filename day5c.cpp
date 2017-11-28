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


char str[205];
int j,k,n,i,ans,s,sum;
int main()
{
	cin>>str;
	cin>>k;
	n=strlen(str);
	if(k>=n)
	{
		cout<<(n+k)/2*2<<endl;
		return 0;
	}
	else
	{
		ans=0;
		sum=0;
		for(i=0;i<n;i++)
		{
			for(j=1;j<=n-i;j++)
			{
				ans=0;
				for(s=i;s<i+j;s++)
				{
					if(s+j<n&&str[s]==str[s+j])
					{
						ans++;
					}
					else if(s+j>=n&&s+j<n+k)
					{
						ans++;
					}
				}
				if(ans==j)
				{
					sum=max(ans,sum);
				}
			}
		}
		cout<<sum*2<<endl;
	}
}
