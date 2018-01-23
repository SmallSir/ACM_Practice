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

int i,n;
int a[200005],sum;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(i=2;i<=n;i++)
		if(a[i]==a[i-1])
			sum++;
	cout<<sum+1<<endl;
}
