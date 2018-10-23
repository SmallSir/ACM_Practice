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

struct point
{
	int l,r;
}a[200005];
int l[200005],r[200005],ans[200005];
int N,i,n,sum_1,sum_2;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].r;
		l[a[i].l]++;
		r[a[i].r]++;
		ans[a[i].l]++;
		ans[a[i].r]--;
		N=max(a[i].r,N);
	}
	for(i=1;i<=N;i++)
	{
		l[i]+=l[i-1];
		r[i]+=r[i-1];
	}
	for(i=1;i<=n;i++)
		sum_1 =max(sum_1, l[a[i].r-1] -r[a[i].l]);
	for(i=1;i<=N;i++)
	{
		ans[i]+=ans[i-1];
		sum_2 = max(sum_2,ans[i]);
	}
	cout<<sum_1<<" "<<sum_2<<endl;
	return 0;
}
