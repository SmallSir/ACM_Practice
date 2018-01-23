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
	string str;
	int n;
}a[1000005];
int T,j,q;
int b[1000005];
int main()
{
	int i,x,ans;
	int cnt=0;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>a[i].str;
		a[i].n=(a[i].str).length();
		cin>>q;
		while(q--)
		{
			cin>>x;
			cnt=max(cnt,x);
			if(a[i].n>a[b[x]].n)
			{
				b[x]=i;
			}
		}
	}
	for(i=1;i<=cnt;i++)
	{
		if(b[i]==0)
			b[i]=b[i-1];
	}
	for(i=1;i<=cnt;i++)
	{
		if(b[i]=0)
		{
			cout<<"a";
		}
		else
		{
			for(j=0;j<a[b[i]].n;j++)
			{
				if(b[j+i+1]!=i)
					break;
				cout<<a[b[j]].str[i];
			}
			i+=j-1;
		}
	}
	cout<<endl;

}
