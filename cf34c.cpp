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

int i,j,n,cnt;
LL a[5005];
int b[5005];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[j]>a[i]&&b[j]!=1&&b[i]!=-1)
			{
				b[i]=-1;
				b[j]=1;
				break;
			}
		}
	}
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(b[i]==1||b[i]==0)
			cnt++;
	}
	cout<<cnt<<endl;
 return 0;
}
