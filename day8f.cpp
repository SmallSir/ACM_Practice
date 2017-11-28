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

long long int m,k,n,cnt,sum;
long long int check(int x)
{
	int i;
	long long int kk=0;
	for(i=1;i<=x;i++)
	{
		kk=((kk+k)*2)%1000000009;
	}
	return kk;
}
int main()
{
	cin>>n>>m>>k;
	cnt=n/k;
	if(cnt*(k-1)>=m-n%k)
	{
		cout<<m%1000000009<<endl;
		return 0;
	}
	cnt=m-n%k-cnt*(k-1);
	sum=(m-cnt*k+check(cnt))%1000000009;
	cout<<sum<<endl;

}
