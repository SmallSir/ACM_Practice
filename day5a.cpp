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

int i;
long long int sum;
int main()
{
	sum=1;
	for(i=1;i<=500;i++)
	{
		sum*=i;
	}
	cout<<sum<<endl;
}
