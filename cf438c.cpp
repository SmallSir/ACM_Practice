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


int n,k,flag;
string a[100005];
int vis[20];
int b[100005];
void dfs(int pos,string s)
{
	if(s.length()==k)
	{
		int cnt=0;
		cout<<s<<endl;
		for(int i=0;i<k;i++)
		{
			cnt+=(s[i]-'0')*pow(2,k-i-1);
		}
		if(vis[cnt]!=1)
		{
			return;
		}
		for(int i=0;i<k;i++)
		{
			if(s[i]==1&&s[i]==a[pos][i])
			{
				return;
			}
		}
		flag=1;
	}
	dfs(pos,s+'1');
	dfs(pos,s+'0');
}
int main()
{
	cin>>n>>k;
	int i,x,j;
	for(i=1;i<=n;i++)
	{
		string s;
		for(j=1;j<=k;j++)
		{
			cin>>x;
			if(x==1)
				s+='1';
			else
				s+='0';
		}
		for(j=0;j<k;j++)
		{
			b[i]+=(s[j]-'0')*pow(2,k-j-1);
		}
		vis[b[i]]=1;
		a[i]=s;
	}
	flag=0;
	for(i=1;i<=n;i++)
	{
		string s;
		s="";
		dfs(i,s);
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
