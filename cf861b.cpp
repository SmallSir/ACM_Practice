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

vector<int> tu[105];
int n,m,i,j,kk,k,x,y,ans,tot,flag;
int a[105];
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		tu[y].push_back(x);
	}
	ans=0;
	for(i=1;i<=100;i++)
	{
		tot=1;
		for(j=1;j<=100;j++)
		{
			if(j<=i*tot)
				a[j]=tot;
			else
			{
				tot++;
				a[j]=tot;
			}
		}
		flag=0;
		for(j=1;j<=100;j++)
		{
			for(k=0;k<tu[j].size();k++)
			{
				int kk;
				kk=tu[j][k];
				if(a[kk]!=j)
				{
					flag=1;
					break;
				}
			}
		}
		if(!flag)
		{
			if(ans==0)ans=a[n];
			else
			{
				if(a[n]!=ans)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<ans<<endl;
}
