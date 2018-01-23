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

int n,m,k;
int a[200005];
int check[1000005];
int i,cnt;
int main()
{
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	queue<int> qua;
	for(i=1;i<=n;i++)
	{
		while(!qua.empty()&&a[i]-qua.front()>=m) {
			qua.pop();
		}
		if(qua.size()>=k-1)
		{
			cnt++;
		}
		else
			qua.push(a[i]);
	}
	cout<<cnt<<endl;
 return 0;
}
