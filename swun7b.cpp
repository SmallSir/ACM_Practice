#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

char str[100005],s[100005];
int MIN,MAX,flag,x,y,n,k,i;
int b[35];
int main()
{
	MIN =30;
	MAX = 0;
	flag =0;
	cin>>n>>k;
	for(i=1;i<=n;i++) {
		cin>>str[i];
		MIN=min(MIN,str[i]-'a');
		MAX=max(MAX,str[i]-'a');
		if(i==k)
		{
			flag = str[i]-'a';
		}
		b[str[i]-'a']=1;
	}
	if(n<k)
	{
		for(i=1;i<=n;i++)
			cout<<str[i];
		for(i=n+1;i<=k;i++)
			cout<<char(MIN+'a');
		cout<<endl;
	}
	else
	{
		if(flag==MAX)
		{
			x=k-1;
			while(x!=0)
			{
				if(str[x]-'a'!=MAX)
				{
					flag = str[x]-'a';
					break;
				}
				x--;
			}
			for(i=1;i<x;i++)
				s[i]=str[i];
			for(i=flag+1;i<30;i++)
			{
				if(b[i]==1)
				{
					s[x]=i+'a';
					break;
				}
			}
			for(i=x+1;i<=k;i++)
				s[i]=MIN+'a';
		}
		else
		{
			for(i=1;i<=k-1;i++)
			{
				s[i]=str[i];
			}
			for(i=flag+1;i<30;i++)
			{
				if(b[i]==1)
				{
					s[k]=i+'a';
					break;
				}
			}
			//s[k-1]=MIN+'a';
		}
		for(i=1;i<=k;i++)
			cout<<s[i];
		cout<<endl;
	}
	return 0;
}
