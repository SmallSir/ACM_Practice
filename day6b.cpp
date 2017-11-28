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

string str;
long long int a[15],s,sum,k;
int i,n;
int main()
{
	cin>>str;
	n=str.length();
	k=9;
	if(n==1)
	{
		cout<<str<<endl;
		return 0;
	}
	for(i=1;i<=9;i++)
	{
		a[i]=a[i-1]+k*i;
		k*=10;
		//cout<<"a["<<i<<"]: "<<a[i]<<endl;
	}
	sum=a[n-1];
	s=0;
	for(i=0;i<n;i++)
	{
		s*=10;
		if(i==0)
			s+=str[i]-'1';
		else
			s+=str[i]-'0';
	}
	//cout<<sum<<" "<<s<<endl;
	//cout<<n<<endl;
	//cout<<s<<endl;
	sum=sum+(s+1)*n;
	cout<<sum<<endl;
}
