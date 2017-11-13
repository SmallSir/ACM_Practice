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
int n,m,i,sum,x;
int a[1005],k;
int main()
{
	cin>>n>>m;
	sum=0;
	for(i=1;i<=m;i++)
	{
		cin>>x;
		if(a[x]==1)
			continue;
		else
		{
			sum++;
			if(qua.size()==n)
			{
				k=qua.front();
				qua.pop();
				a[k]=0;
				a[x]=1;
				qua.push(x);
			}
			else
				qua.push(x);
		}
	}
	cout<<sum<<endl;
 return 0;
}
