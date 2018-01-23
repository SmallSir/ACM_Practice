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

int n,a,b,c,ans,sum;
int main()
{
	cin>>n;
	cin>>a>>b>>c;
	ans=min(a,b);
	ans=min(c,ans);
	if(n==1)
		cout<<0<<endl;
	else
	{
		sum=min(a,b);
		n-=2;
		cout<<sum+ans*n<<endl;
	}
	return 0;
}
