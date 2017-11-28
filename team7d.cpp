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

int a[1000010];
int n,k,x,i,MAX,cnt;
int main()
{
	cin>>n>>k;
	cnt=0;
	MAX=0;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
		a[x+1000]--;
	}
	for(i=1;i<1000005;i++)
	{
		a[i]+=a[i-1];
		MAX=max(a[i],MAX);
	}
	cnt=MAX/k;
	if(MAX%k!=0)
		cnt++;
	cout<<cnt<<endl;
}
