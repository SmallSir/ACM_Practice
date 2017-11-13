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

int n,i;
LL a;
int main()
{
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			a=0;
			cin>>a;
			cout<<6<<a%100000<<endl;
		}
	}
 return 0;
}
