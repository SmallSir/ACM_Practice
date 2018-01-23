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
#include<queue>  
#include<map> 
#include<stack>
#define inf 9999999; 
using namespace std;


string str;
int sum,n,m,i,ans;
int a[80],b[80];
int main()
{
	while(cin>>str>>m)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		n=str.length();
		for(i=0;i<n;i++)
		{
			a[i+1]=str[i]-'a';
		}
		for(i=1;i<=n;i++)
		{
			ans=0;
			sum=a[i];
			//i=0;
			stack<int> qua;
			while(sum)
			{
				//i++;
				qua.push(sum%m);
				sum/=m;
			}
			while(!qua.empty())
			{
				ans+=qua.top();
				qua.pop();
				ans*=10;
			}
			ans/=10;
			b[i]=ans;
			//cout<<ans<<endl;

		}
		for(i=1;i<=n;i++)
			cout<<b[i];
		cout<<endl;
	}
}
