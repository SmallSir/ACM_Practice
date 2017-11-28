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

int main()
{
	cin>>n>>x;
	if(n==1)
	{
		cout<<"YES"<<endl;
		cout<<x<<endl;
	}
	else if(n==2)
	{
		if(x!=0)
		{
			cout<<"YES"<<endl;
			cout<<0<<" "<<x<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}

	}
	else
	{
	}
	return 0;
}
