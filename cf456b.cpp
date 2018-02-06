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

LL n,k,ans;
int main()
{
	ans=1;
	cin>>n>>k;
	if(k==1)
		cout<<n<<endl;
	else
	{
		while(n!=0)
		{
			n/=2;
			ans*=2;
		}
		cout<<ans-1<<endl;
	}
 return 0;
}
