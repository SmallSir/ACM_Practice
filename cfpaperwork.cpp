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

int n,a[105],b[105],i;
int cnt,tot;
int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	tot=0;
	cnt=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			if(tot==2)
			{
				tot=1;
				b[++cnt]++;
			}
			else
			{
				tot++;
				b[cnt]++;
			}
		}
		else
		{
			tot=0;
			b[cnt]++;
		}
	}
	cout<<cnt<<endl;
	for(i=1;i<=cnt;i++)
		cout<<b[i]<<" ";
	cout<<endl;
 return 0;
}
