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


queue<int> qua;
int a[200005],b[200005],vis[200005];
int i,n,cnt;
int main()
{
	cin>>n;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(b[a[i]]!=0)
			cnt++;
		b[a[i]]++;
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
			qua.push(i);
	}
	cout<<cnt<<endl;
	for(i=1;i<=n;i++)
	{
		if(b[a[i]]>1)
		{
			if(a[i]<qua.front())
			{
				if(vis[a[i]]==0)
				{
					vis[a[i]]=1;
				}
				else
				{
					b[a[i]]--;
					a[i]=qua.front();
					qua.pop();
				}
			}
			else
			{
				b[a[i]]--;
				a[i]=qua.front();
				qua.pop();
			}
		}
	}
	for(i=1;i<n;i++)
		cout<<a[i]<<" ";
	cout<<a[i]<<endl;
	return 0;
}
