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

int n,i;
string str;
int a[105];
int main()
{
	cin>>str;
	int flag=0;
	n = str.length();
	if(str[n-1]=='0')
		a[n-1]=1;
	for(i=n-2;i>=0;i--)
	{
		if(str[i]=='0')
		{
			a[i]=a[i+1]+1;
		}
		else
		{
			flag=1;
			a[i]=a[i+1];
		}
	}
	if(flag==0)
	{
		cout<<"no"<<endl;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>=6&&str[i]=='1')
		{
			cout<<"yes"<<endl;
			return 0;
		}
	}
	cout<<"no"<<endl;
	return 0;
}
