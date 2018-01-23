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

vector<string> tu;
map<string,int> name;
void check(int x)
{
	int i,j;
	bool flag=0;;
	for(i=0;i<tu[x].size();i++)
	{
		s1=tu[x][i];
		if(a[x][i]==0)
		{
			for(j=i+1;j<tu[x].size();j++)
			{
				s2=tu[x][j];
				len1=(tu[x][i]).length();
				len2=(tu[x][j]).length();
				if(len1>=len2)
				{
					for(k=len1;k>=len1-len2;k--)
					{
						if(s1[k]!=s2
					}
				}
				else
				{

				}
			}
		}
	}
}
int main()
{
	cin >> n;
	for(i = 1; i <= n;i++)
	{
		cin>>str;
		if(name[str]==0) name[str]=++ans;
		b[ans]=str;
		cin>>T;
		while(T--£©
		{
			cin>>s;
			tu[name[str]].push_back(s);
		}
	}
	cout<<ans<<endl;
	for(i=1;i<=ans;i++)
	{
		check(i);
	}
	for(i=1;i<=ans;i++)
	{
		cout<<b[ans]<<" ";
		cout<<number[name[b[ans]]]<<" ";
		for(j=0;j<tu[name[b[ans]]];j++)
		{
			if(a[name[b[ans]]][j]==0)
				cout<<check[name[b[ans]]][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
