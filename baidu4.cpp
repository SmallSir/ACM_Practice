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
LL n,i,ans;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		for(i=1;i*i<=n-1;i++)
		{
			if((n-1)%i==0)
			{
				if(i*i!=(n-1))
					ans+=2;
				else
					ans++;
			}
		}
		cout<<ans<<endl;;
	}
 return 0;
}
