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

int i,n,x;
int tu[105][105],cnt;
int check[105],qu[105];
int main()
{
	cin >> n;
	for(i = 1;i <= n;i ++)
	{
		for(;;)
		{
			cin >> x;
			if(x == 0)
				break;
			tu[i][x] = 1;
			check[x]++;
		}
	}
	cnt = 0;
	queue<int> qua;
	for(i = 1;i <= n;i ++)
	{
		if(check[i] == 0)
		{
			qua.push(i);
			qu[++cnt]=i;
		}
	}
	while(!qua.empty())
	{
		x = qua.front();
		qua.pop();
		for(i = 1;i<=n;i++)
		{
			if(tu[x][i]==1)
			{
				check[i]--;
				if(check[i]==0)
				{
					qua.push(i);
					qu[++cnt]=i;
				}
			}
		}
	}
	for(i=1;i<n;i++)
		cout<<qu[i]<<" ";
	cout<<qu[i]<<endl;
 return 0;
}
