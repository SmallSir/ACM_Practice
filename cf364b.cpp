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

int cnt,j,w,n,d,i,x,sum;
int dp[55*10000+10];
int main()
{
	cin>>n>>d;
	sum=0;
	memset(dp,0,sizeof(dp));
	cnt=w=0;
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		for(j=sum;j>=x;j--)
		{
			if(dp[j-x])
			{
				dp[j]=1;
			}
		}
	}
	while(true)
	{
		j=w+d;
		while(!dp[j] && w<j)
			j--;
		if(j ==w)
			break;
		w=j;
		cnt++;
	}
	cout<<w<<" "<<cnt<<endl;
	return 0;
}
