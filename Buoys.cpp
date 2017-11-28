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

int n,i,x,j,y,cnt,l,k,r;
int a[405];
double res,ss,s;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	double ans=double(1<<30);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			ss=double((a[j]-a[i])/(j-i));
			cnt=i;
			res=0;
			for(k=1;k<=n;k++)
			{
				if(k<=cnt)
				{
					s=ss*(cnt-k);
					s=abs(a[cnt]-s-a[k]);
				}
				else
				{
					s=ss*(k-cnt);
					s=abs(a[k]-a[cnt]-s);
				}
				res+=s;
			}
			if(res<ans)
			{
				ans=res;
				l=i;
				r=j;
			}
		}
	}
	printf("%0.7lf\n",ans);
	res=(a[r]-a[l])/(r-l)*1.0;
	for(i=1;i<=n;i++)
	{
		if(i<=l)
		{
			s=a[l]-(l-i)*res;
		}
		else
		{
			s=a[l]+(i-l)*res;
		}
		if(i==n)
			printf("%0.7lf\n",s);	
		else
			printf("%0.7lf ",s);
	}
	return 0;
}
