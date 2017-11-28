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

double a;
LL i;
int main()
{
	int cnt=0;
	a=0;
	for(i=1;i<=100000010;i++)
	{
		a=log10(i+a);
		double k=pow(10,a);
		int x=floor(k);
		if(i+cnt!=x)
		{
			cnt++;
			cout<<i<<endl;
			cout<<x<<endl;
			cout<<x-i<<endl;
			cout<<"--------------"<<endl;
			//cout<<x<<endl;
		}
	}
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
 return 0;
}
