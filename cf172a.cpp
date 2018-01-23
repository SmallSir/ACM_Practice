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

char str[30005][25];
int i,j,n,m;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str[i];
	}
	m=strlen(str[1]);
	for(i=0;i<m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(str[1][i]!=str[j][i])
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
