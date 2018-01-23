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

long long int pt=1e9+7;
string str;
int k,n;
long long int cnt,sum;
long long int fast_pow(long long int x,long long int y)
{
	long long int res;
	res=1;
	while(y!=0)
	{
		if(y&1) res=(res*x)%pt;
		y>>=1;
		x=(x*x)%pt;
	}
	return res;
}
int main()
{
	long long int i,j;
	cin>>str;
	cin>>k;
	n=str.length();
	cnt=0;
	for(i=0;i<n;i++)
	{
		if(str[i]=='0'||str[i]=='5')
		{
			long long int a=fast_pow(2,i);
			long long int qn=fast_pow(fast_pow(2,n),k);
			a=a*(1-qn+pt)%pt;
			long long int c=fast_pow((1-fast_pow(2,n)+pt),pt-2)%pt;
			sum=(sum+a*c)%pt;
		}
	}
	cout<<sum<<endl;
}
