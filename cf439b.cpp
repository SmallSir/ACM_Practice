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
LL a,b,i,ans;
int main()
{
	cin>>a>>b;
	ans=1LL;
	for(i=a+1;i<=b;i++)
	{
		ans=ans*i%10;
		if(ans==0) break;
	}
	cout<<ans<<endl;

 return 0;
}
