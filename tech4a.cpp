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

map<int,bool> a;
int n,k,i,x,cnt;
string str;
int main()
{
	cin>>str;
	n=str.length();
	cin>>k;
	if(n<k)
	{
		cout<<"impossible"<<endl;
		return 0;
	}
	cnt=0;
	for(i=0;i<n;i++)
	{
		x=str[i]-'a';
		if(a[x]!=1)
		{
			a[x]=1;
			cnt++;
		}
	}
	if(cnt>=k)
		cout<<0<<endl;
	else
		cout<<k-cnt<<endl;
 return 0;
}
