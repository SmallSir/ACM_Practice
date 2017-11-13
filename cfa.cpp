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


int n,MAX,i;
int b[1005],a[1005],ans,pos;
int main()
{
	cin>>n;
	MAX=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		MAX=max(a[i],MAX);
		b[a[i]]++;
		
	}
	bool flag=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==MAX)
		{
			pos=i;
			break;
		}
	}
	for(i=2;i<=pos;i++)
	{
		if(a[i]<=a[i-1])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(i=pos+1;i<=n;i++)
	{
		if(a[i]>a[i-1]||a[i]==a[i-1]&&a[i]!=MAX)
		{
		//cout<<a[i]<<endl;
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}
