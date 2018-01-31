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

int i,n,m;
string name,ip;
map<string,string> a;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>name>>ip;
		ip+=';';
		a[ip]=name;
	}
	for(i=1;i<=m;i++)
	{
		cin>>name>>ip;
		cout<<name<<" "<<ip<<" "<<"#"<<a[ip]<<endl;
	}
	return 0;
}
