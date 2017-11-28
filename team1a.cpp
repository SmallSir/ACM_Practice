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

int n;
int main()
{
	int i,k;
	i=1;
	while(cin>>n)
	{
		//if(n==1) k=0;
		 k=n*log10(2);
		cout<<"Case #"<<i<<": "<<k<<endl;
		i++;
	}
}
