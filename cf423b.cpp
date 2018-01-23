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

char s[1005],t[1005];
int n,m,i,j,ans,cnt,sum,k;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>s[i];
	for(j=1;j<=m;j++) cin>>t[j];
	cnt=10000;
	ans=0;
	for(i=1;i<=m-n+1;i++)
	{
		sum=0;
		k=i;
		for(j=1;j<=n;j++)
		{
			if(s[j]!=t[k])
				sum++;
			k++;
		}
		if(sum<cnt)
		{
			ans=i;
			cnt=sum;
		}
	}
	cout<<cnt<<endl;
	for(i=ans,j=1;j<=n;j++,i++)
	{
		if(s[j]!=t[i])
			cout<<j<<" ";
	}
	cout<<endl;
	return 0;
}
