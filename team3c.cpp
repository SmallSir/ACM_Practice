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

LL pt=1e9+7;
LL cnt,sum;
LL a[250010],ans[250010];
int b[250010];
int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	while(cin>>n)
	{
		int i;
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++) 
		{
			cin>>a[i];
			a[i]-=i;
		}
		ans[n]=a[i];
		for(i=n-1;i>=1;i--)
			ans[i]=max(a[i],ans[i+1]);
		for(i=1;i<=n;i++) cin>>b[i];
		sort(b+1,b+1+n);
		sum=0;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(cnt<ans[b[i]])
				sum=(sum+ans[b[i]])%pt;
			else
				sum=(sum+cnt)%pt;
			cnt=max(cnt,ans[b[i]]-(n+i));
		}
		cout<<sum<<endl;
			
	}
	return 0;
}
