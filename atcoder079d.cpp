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

LL k,n,a[55];
LL i,x;
int main()
{
	cin>>k;
	cout<<50<<endl;
	n=k/50;
	x=k%50;
	for(i=0;i<50;i++)
		a[i]=i+n;
	for(i=50;i=50-x;i--)
		a[i]+=1;
	for(i=0;i<50;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;

}
