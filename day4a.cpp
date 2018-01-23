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

int main()
{
	cin>>a;
	cin>>str;
	n=str.length();
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i]=(str[i]-'0')*(str[j]-'0');//ÐÐ´æÈ¡
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[j]-b[i-1]==a)
			{
				sum++;
			}
		}
	}
}
