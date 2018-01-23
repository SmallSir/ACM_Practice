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

char str[100005],s[100005];
int n,j;
struct point
{
	int sum,index;
}a[30];
bool dfs(int x)
{
	int i;
	if(x == n)
		return true;
	for(i=1;i<=26;i++)
	{
		if(str[x]!=a[i].index-1+'a' && a[i].sum!=0)
		{
			s[x]=char(a[i].index-1+'a');
			a[i].sum--;
			if(!dfs(x+1))
			{
				a[i].sum++;
			}
			else
				return true;
		}
	}
	return false;
}
int main()
{
	int i;
	scanf("%s",str);
	n=strlen(str);
	for(i=1;i<=26;i++)
		a[i].index=i;
	for(i=0;i<n;i++)
	{
		a[str[i]-'a'+1].sum++;
	}
	for(i=1;i<=26;i++)
	{
		if(n-a[i].sum<a[i].sum)
		{
			printf("impossible\n");
			return 0;
		}
	}
	dfs(0);
	for(i=0;i<n;i++)
		printf("%c",s[i]);
	printf("\n");
 return 0;
}
