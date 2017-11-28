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

int a[100005];
int i,n,MAX,x,ans;
int main()
{
	while(cin >> n)
	{
		memset(a,0,sizeof(a));
		MAX = 0;
		for( i = 1 ;i <= n; i ++)
		{
			cin >> x;
			a[x] ++;
			MAX = max(x,MAX);
		}
		ans = 0;
		for( i = 1 ;i <= MAX - 2;i ++)
		{
			if(a[i] % 2!=0&&a[i+1]%2!=0&&a[i+2]!=0)
			{
				ans++;
				a[i]--;
				a[i+1]--;
				a[i+2]--;
			}
				ans +=a[i]/2;
		}
		ans += a[MAX - 1]/2;
		ans += a[MAX]/2;
		cout<<ans<<endl;
	}
}
