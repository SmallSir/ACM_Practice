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

LL a,b,x,y,z,aa,bb,sum;
int main()
{
	cin>>a>>b;
	cin>>x>>y>>z;
	aa = x * 2 + y;
	bb = y+z*3;
	sum=0;
	if(aa>a)
		sum+=aa-a;
	if(bb>b)
		sum+=bb-b;
	cout<<sum<<endl;
 return 0;
}
