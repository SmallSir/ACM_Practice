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

int cnt,n,i;
string str;
int main()
{
	cin>>str;
	cnt=0;
	n=str.length();
	for(i=0;i<n;i++)
	{
		if(i%3==0)
		{
			if(str[i]!='P'&&str[i]!='p')
				cnt++;
		}
		else if(i%3==1)
		{
			if(str[i]!='E'&&str[i]!='e')
				cnt++;
		}
		else 
		{
			if(str[i]!='r'&&str[i]!='R')
				cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
