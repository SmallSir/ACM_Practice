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

int a[30][1705],b[30];
char str[1505],ch;
int k,n,i,j,T,z,sum,x,MAX,l,r;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>str[i];
	cin>>T;
	memset(a,0,sizeof(a));
	for(z=1;z<=27;z++)
	{
		for(l=1;l<=n;l++)
		{
			sum=0;
			for(r=l;r<=n;r++)
			{
				if(str[r]-'a'+1!=z)
					sum++;
				a[z][sum]=max(a[z][sum],r-l+1);
			}
		}
	}
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
	{
		b[str[i]-'a'+1]++;
	}
	while(T--)
	{
		cin>>x>>ch;
		//if(x==1)
		if(x+b[ch-'a'+1]>=n)
			cout<<n<<endl;
		else
		cout<<a[ch-'a'+1][x]<<endl;
	}
}
