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

char str[55];
int n,sum,i,j;
int dp[55][55];
int main()
{
	cin>>str;
	n=strlen(str);
	sum=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
			{
				dp[i][j]=1;
			}
			else if(str[i]==str[j])
			{
				dp[i][j]=dp[i][j-1]+j-i;
			}
			else
			{
				dp[i][j]=dp[i][j-1];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		//cout<<dp[i][n-1]<<endl;
		sum+=dp[i][n-1];
	}
	cout<<sum<<endl;
}
