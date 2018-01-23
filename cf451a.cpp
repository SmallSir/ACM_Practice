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

LL x;
int main()
{
	cin>>x;
	if(x%10>=5)
		x=x-x%10+10;
	else
		x=x-x%10;
	cout<<x<<endl;
}
