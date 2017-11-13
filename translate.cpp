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

int n,m,i,sum,x;
int a[1005],k;
int qua[1005];
int main()
{
	int l,r;
	l=r=1;
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
			if(r-l==n)
			{
				a[qua[l]]=0;
				l++;
				qua[r++]=x;
				a[x]=1;
			}
			else
			{
				a[x]=1;
				qua[r++]=x;
			}
		}
	}
	cout<<sum<<endl;
 return 0;
}
