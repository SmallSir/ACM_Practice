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

int n,m,i,j,k,sum;
char s;
int check[2005];
int main()
{
	cin>>n>>m;
	int flag=0;
	for(i=1;i<=n;i++)
	{
		k=0;
		for(j=1;j<=m;j++)
		{
			cin>>s;
			if(s=='G')
				k=j;
			if(s=='S')
			{
				if(k==0)
				{
					flag=1;
				}
				else
				{
					check[j-k]++;
				}
			}
		}
	}
	if(flag==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		sum=0;
		for(i=0;i<=m;i++)
		{
			if(check[i]!=0)
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
