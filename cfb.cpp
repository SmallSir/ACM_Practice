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

int a[50];
string str,str1;
char s[1005],st[1005];
int n,m,i;
int main()
{
	cin>>str;
	cin>>str1;
	cin>>st;
	n=str.length();
	for(i=0;i<n;i++)
		a[str[i]-'a']=str1[i]-'a';
	m=strlen(st);
	for(i=0;i<m;i++)
	{
		if(st[i]<='Z'&&st[i]>='A')
		{
			s[i]=a[st[i]-'A']+'A';
		}
		else if(st[i]<='z'&&st[i]>='a')
		{
			s[i]=a[st[i]-'a']+'a';
		}
		else
		{
			s[i]=st[i];
		}
	}
	for(i=0;i<m;i++)
	{
		cout<<s[i];
	}
	cout<<endl;
}
