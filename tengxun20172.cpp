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

int n;
int a[100005];
LL b[100005];
int i,Min,Max;
int main()
{
	while(cin>>n)
	{
		Max=Min=0;
		for(i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		for(i=1;i<=n/2;i++)
		{
			b[i]=LL(a[n-i+1]-a[i]);
		}
		sort(b+1,b+1+n/2);
		cout<<b[1]<<" "<<b[n/2];
		for(i=1;i<=n/2;i++)
			if(b[i]==b[1])
				Min++;
			if(b[i]==b[n/2])
				Max++;
		cout<<Min<<" "<<Max<<endl;
	}
}
