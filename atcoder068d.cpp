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

LL a[55],n,k,x;
int i;
int main()
{
 
	cin>>k;
	n=k/50;
	x=k%50;
	memset(a,0,sizeof(a));
	cout<<50<<endl;
	for(i=1;i<=x;i++)
		a[i]=i+50;
	for(i=1;i<=50;i++)
		a[i]+=50*n;
	for(i=1;i<=50;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
