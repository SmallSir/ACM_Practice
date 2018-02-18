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

int n,pos,l,r;
int main()
{
	cin>>n>>pos>>l>>r;
	if(l==1&&r==n)
		cout<<0<<endl;
	else if(l==1||r==n)
	{
		if(l==1)
			cout<<abs(r-pos)+1<<endl;
		else
			cout<<abs(l-pos)+1<<endl;
	}
	else
	{
		cout<<min(abs(l-pos),abs(r-pos))+2+r-l<<endl;
	}
	return 0;
}
