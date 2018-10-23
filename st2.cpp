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

string str;
int i,n,dp[100005];
int main()
{
	cin>>str;
	n = str.length();
	if(str[0] == '0')
	{
		if(str[1] == '0')
		{
			dp[0]=dp[1] = 0;
		}
		else
		{
			dp[0] = 0;
			dp[1] = 1;
		}
	}
	else
	{
		if((str[0]=='1')||(str[0]=='2'&&str[1]<='6'))
		{
			dp[0] = 1;
			if(str[1]=='0')
				dp[1] = 1;
			else
				dp[1] = 2;
		}
		else
		{
			if(str[1] == '0')
				dp[1] = dp[0] = 0;
			else
			{
				dp[1] = dp[0] = 1;
			}
		}
	}
	for(i=2;i<n;i++)
	{
		if(str[i-1] == '0')
			dp[i] = dp[i-1];
		else if((str[i-1]=='1')||(str[i-1]=='2'&&str[i]<='6'))
		{
			dp[i] = dp[i-1]+dp[i-2];
		}
		else
			dp[i] = dp[i-1];
	}
	cout<<dp[n-1]<<endl;
 return 0;
}
