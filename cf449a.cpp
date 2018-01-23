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

char str[105];
char s,k;
int n,m,i,j,r,l;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>str[i];
	for(i=1;i<=m;i++)
	{
		cin>>l>>r>>s>>k;
		for(j=l;j<=r;j++)
		{
			if(str[j]==s)
				str[j]=k;
		}
	}
	for(i=1;i<=n;i++)
		cout<<str[i];
	cout<<endl;
 return 0;
}
