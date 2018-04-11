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

char str[10];
int n,sum,i;
int main()
{
	cin>>n;
	sum=0;
	for(i=1;i<=n;i++)
	{
		cin>>str;
		if((str[0]==str[3]&&str[1]==str[4])||(str[0]==str[1]&&str[3]==str[4])||(str[0]==str[4]&&str[1]==str[3]))
		{
			sum++;
		}
	}
	cout<<sum<<endl;
	 return 0;
}
