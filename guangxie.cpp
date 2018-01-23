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

int main()
{
	while(cin>>n>>q)
	{
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			for(j=0;j<=30;j++)
			{
				if((1<<j)&a[i])
					cnt[j]++;
			}
		}
		int AND=a[1],OR=a[1],XOR=a[1];
		for(i=2;i<=n;i++)
		{
			AND=a[i] & AND;
			OR=a[i] | OR;
			XOR=XOR ^ a[i];
		}
		x=AND,y=OR,z=XOR;
		for(i=1;i<=q;i++)
		{
			x=AND,y=OR,z=XOR;
			cin>>k;
			for(j=0;j<=30;j++)
			{
				if((1<<j) &a[j])
				{
					if(cnt[j]==1)
					{

					}

				}
			}
		}
	}
 return 0;
}
