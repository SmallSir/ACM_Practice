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

int n,i;
LL a;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			a=0;
			scanf("%lld",&a);
			printf("%d\n",a%100000+600000);
		}
	}
 return 0;
}
