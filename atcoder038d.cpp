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

LL a[35][35],sum;
int i,n,j,k;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			sum+=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(i==j||k==j||k==i)
					continue;
				if(a[k][j]==a[k][i]+a[i][j])
				{
					sum-=a[k][j]*2;
					a[k][j]=0;
					a[j][k]=0;
				}
				if(a[k][j]>a[k][i]+a[i][j])
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
