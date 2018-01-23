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

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>str;
		cin>>s;
		n=str.length();
		m=s.length();
		if(n<m)
		{
			cout<<"Bob"<<endl;
			continue;
		}
		if(s==str)
		{
			cout<<"Alice"<<endl;
			continue;
		}
	}
}
