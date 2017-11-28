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

int i,k;
LL cnt,tot,n;
int main()
{
	cin>>n>>k;
	cnt=1;
	for(i=1;i<=k;i++) cnt*=10;
	for(i=1;;i++)
	{
		tot+=n;
		if(tot%cnt==0)
		{
			cout<<tot<<endl;
			return 0;
		}
	}

}
