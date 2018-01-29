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

LL a,x,sum,b[100005];
int i,n;
int main()
{
	cin>>n>>a;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	sum=0;
	sort(b+1,b+1+n);
	cout<<min(min(abs(b[n]-b[2])+abs(b[n]-a),
		abs(b[n-1]-b[1])+abs(b[n-1]-a)),min(abs(a-b[1])+abs(b[n-1]-b[1]),
		abs(a-b[2])+abs(b[n]-b[2])))<<endl;
 return 0;
}
