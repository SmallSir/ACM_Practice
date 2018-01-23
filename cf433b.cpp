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

LL n,k,MAX,MIN;
int main()
{
	cin>>n>>k;
	MAX=min(2*k,n-k);
	if(n==k||k==0) MIN=0;
	else MIN=1;
	cout<<MIN<<" "<<MAX<<endl;
 return 0;
}
