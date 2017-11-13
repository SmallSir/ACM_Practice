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

int T;
int a[10000010];
int ans,cnt,l,x;
int main()
{
	a[1]=1,a[2]=2;
	ans=2,cnt=1;
	l=2;
	while(l<=10000010)
	{
		if(cnt==a[ans])
		{
			l++;
			if(a[l-1]==2)
				a[l]=1;
			else
				a[l]=2;
			ans++;
			cnt=1;
		}
		else{
			cnt++;
			a[l+1]=a[l];
			l++;
		}
	}
	cin>>T;
	while(T--)
	{
		cin>>x;
		cout<<a[x]<<endl;
	}
	return 0;
}
