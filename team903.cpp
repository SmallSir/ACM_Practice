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

map<LL,int> cnt;
LL a[125255],b[125250];
int n,m,pos;
int main()
{
	while(scanf("%lld", &n) != EOF)
	{
		int i,k;
		cnt.clear();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)
		{
			if(i*(i+1)/2==n)
			{
				m=i;
				break;
			}
		}
		pos=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			cnt[a[i]]++;
		}
		sort(a+1,a+1+n);
		b[1]=a[1];
		b[2]=a[2];
		cnt[a[1]]--;
		cnt[a[2]]--;
		pos=2;
		k=3;
		for(;;)
		{
			for(i=1;i<pos;i++)
			{
				cnt[b[i]+b[pos]]--;
			}
			for(i=k;i<=n;i++)
			{
				if(cnt[a[i]]!=0)
				{
					cnt[a[i]]--;
					k=i+1;
					b[++pos]=a[i];
					break;
				}
			}
			if(pos==m)
				break;
		}
		cout<<m<<endl;
		for(i=1;i<m;i++)
			printf("%lld ",b[i]);
		printf("%lld\n",b[i]);
	}
	return 0;
}
