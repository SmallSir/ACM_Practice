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
//strattime:2017/10/10 21:32
//endtime:2017/10/9 21:37

int i,n,tot;
double MAX,x,y;

int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	cin>>n;
	MAX=0.0;
	for(i = 1;i <= n; i ++)
	{
		cin >> x >> y;
		if(MAX < (x/y)*1.0)
		{
			tot = i;
			MAX = (x / y)*1.0;
		}
	}
	cout << tot << endl;
	return 0;
}
