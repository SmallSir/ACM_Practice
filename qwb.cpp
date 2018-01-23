#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;

int T;
long long int n,x,y,k,sum;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		k=n%3;
		x=0;
		if(k==1)
		{
			x=2;
			y=n/3-1;
		}
		else if(k==2)
		{
			x=1;
			y=n/3;
		}
		else
		{
			y=n/3;
		}
		sum=(pow(3,y)*pow(2,x));
		sum%=1000000007;
		cout<<sum<<endl;
	}
}
