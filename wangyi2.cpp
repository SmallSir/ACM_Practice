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
int n,i;
int a[100005];
int main()
{
	cin>>str;
	n = str.length();
	for(i=0;i<n;i++)
	{
		a[i]=str[i]-'0';
		a[i]+=str[n-i-1]-'0';
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>=10)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
	if(a[n]!=0)
		cout<<a[n];
	for(i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
 return 0;
}
