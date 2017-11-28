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

int i,n,cnt,ans,flag;
int a[105];
int main()
{
	cin >> n;
	for( i = 1 ;i <= n ;i ++)
		cin >> a[i];
	if( a[1] % 2 !=0 &&a[n] % 2!=0&&n%2!=0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}
