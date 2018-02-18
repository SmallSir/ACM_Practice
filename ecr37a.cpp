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

int n,k,i,T,t;
int a[205];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		t=0;
		for(i=1;i<=k;i++)
		{
			cin>>a[i];
			if(a[i]!=1)
				t = max(t,(a[i]-a[i-1])/2);
		}
		t=max(t,(a[1]-1));
		t=max(t,(n-a[k]));
		cout<<t+1<<endl;
	}
	return 0;
}
