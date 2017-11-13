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

int cnt[35];
int n,i,q,j,x;
int a[100005];
int main()
{
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(j=0;j<=30;j++)
			{
				if((1 << j) & a[i])
					cnt[j]++;
			}
		}
		int AND=a[1],OR=a[1],XOR=a[1];
		for(i=2;i<=n;i++)
		{
			AND=a[i] & AND;
			OR =a[i] | OR;
			XOR=XOR ^ a[i];
		}
		while(q--)
		{
			int _AND=AND,_OR=OR,_XOR=XOR;
			scanf("%d",&x);
			for(i=0;i<=30;i++)
			{
				if((1 << i) & a[x])
				{
					if(cnt[i]==1)
						_OR=_OR ^ (1 << i);
				}
				else
				{
					if(cnt[i]==n-1)
					{
						_AND= _AND | (1 << i);
					}
				}
			}
			_XOR=_XOR ^ a[x];
			printf("%d %d %d\n",_AND,_OR,_XOR);
			
		}
		memset(cnt,0,sizeof(cnt));
	}
 return 0;
}
