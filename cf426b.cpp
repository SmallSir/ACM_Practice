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

struct point 
{
	int l,r;
}a[30];
string str;
int i,k,j,n;
int b[1000008];
int main()
{
	cin>>n>>k;
	cin>>str;
	n=str.length();
	for(i=0;i<30;i++)
	{
		a[i].l=1000005;
		a[i].r=0;
	}
	for(i=0;i<n;i++)
	{
		a[str[i]-'A'].l=min(a[str[i]-'A'].l,i);
		a[str[i]-'A'].r=max(a[str[i]-'A'].r,i);
	}
	for(i=0;i<26;i++)
	{
		for(j=a[i].l;j<=a[i].r;j++)
		{
			b[j]++;
		}
	}
	for(i=1;i<=1000005;i++)
	{
		if(b[i]>k)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
 return 0;
}
