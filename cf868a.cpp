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

string str,s;
int T,l,r;
int main()
{
	cin>>str;
	cin>>T;
	l=r=0;
	while(T--)
	{
		cin>>s;
		if(s==str)
		{
			l=1,r=1;
		}
		if(s[0]==str[1])
			r=1;
		if(s[1]==str[0])
			l=1;
	}
	if(l==1&&r==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
 return 0;
}
