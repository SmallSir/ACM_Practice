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

int ans,t,s,q;
int main()
{
	ans = 0;
	cin>>t>>s>>q;
	while(s<t)
	{
		s*=q;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
