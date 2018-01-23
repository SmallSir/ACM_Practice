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

int i,cnt;
LL n;
int a[100005];
int main()
{
	cin>>n;
	cnt = 0;
	for(;;)
	{
		if(n%2==0)
		{
			a[++cnt]=2;
			n=(n-2)/2;
		}
		else
		{
			a[++cnt]=1;
			n=(n-1)/2;
		}
		if(n==0)
			break;
	}
	for(i=cnt;i>=1;i--)
		cout<<a[i];
	cout<<endl;
 return 0;
}
