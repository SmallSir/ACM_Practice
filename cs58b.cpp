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
//strattime:2017/10/9 21:38
//endtime:2017/10/9 21:44


int n,i;
struct point
{
	int cnt,pos;
}a[105];
bool cmp(point x,point y)
{
	if(x.pos==y.pos)
		return x.cnt>y.cnt;
	return x.pos<y.pos;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin >> n;
	for(i = 1;i <= n;i ++)
	{
		cin>>a[i].pos;
		a[i].pos+=i;
		a[i].cnt=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i = 1;i < n;i ++)
	{
		cout<<a[i].cnt<<" ";
	}
	cout<<a[i].cnt<<endl;

	return 0;
}
