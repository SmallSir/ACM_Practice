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
string a[]={"0","050","080","170","020","200","110"};
int main()
{
	cin>>n;
	if(n==1||n==2)
	{
		cout<<-1<<endl;
	}
	else if(n==3)
	{
		cout<<210<<endl;
	}
	else
	{
		k=n-3;
		k=k%6;
		if(k==0)
			k=6;
		for(i=1;i<=n-3;i++)
		{
			if(i==1)
				cout<<1;
			else
				cout<<0;
		}
		cout<<a[k]<<endl;
	}

}
