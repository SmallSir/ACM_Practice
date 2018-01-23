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


string str;
int n,m,ans;
string s="ILOVECES";
bool check(int x,int y)
{
	int i;
	for(i=x;i<n;i++)
	{
		if(str[i]==s[y]||str[i]==s[y]-'A'+'a')
		{
			if(y==7)
				return true;
			else
				return check(i+1,y+1);
		}
	}
	return false;
}
int main()
{
	while(cin>>str)
	{
		ans=0;
		int i;
		n=str.length();
		m=s.length();
		for(i=0;i<n;i++)
		{
			if(str[i]=='I'||str[i]=='i')
			{
				if(check(i+1,1))
					ans++;
			}
		}
		cout<<ans<<endl;
	}
}
