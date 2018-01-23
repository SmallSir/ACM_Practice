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

int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}
int i,n;
int main()
{
	cin>>n;
	int MAX = 0;
	for(i=1;i<=n;i++)
	{
		if(i<n-i)
		{
			if(gcd(i,n-i)==1)
			{
				MAX=max(i,MAX);
			}
		}
		else
			break;
	}
	cout<<MAX<<" "<<n-MAX<<endl;
	return 0;
}
