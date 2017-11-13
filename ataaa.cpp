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

string str;
int n,i,cnt;
int a[26];
int l,r,sum,ans,flag;
int main()
{
	cin>>str;
	n=str.length();
	for(i=0;i<n;i++)
	{
		a[str[i]-'a']++;
	}
	cnt=0;
	for(i=0;i<26;i++)
	{
		if(a[i]%2!=0&&i+'a'!='x')
		{
			cnt++;
		}
	}
	if(cnt>1)
	{
		cout<<-1<<endl;
		return 0;
	}
	flag=0;
	sum=0;
	l=0;
	r=n-1;
	while(l<r)
	{
		if(str[l]!=str[r])
		{
			if(str[l]=='x')
			{
				sum++;
				l++;
			}
			else if(str[r]=='x')
			{
				sum++;
				r--;
			}
			else
			{
				flag=1;
				break;
			}
		}
		else
		{
			l++;
			r--;
		}
	}
	if(flag)
		cout<<-1<<endl;
	else
		cout<<sum<<endl;
}
