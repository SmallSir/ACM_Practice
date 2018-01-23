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

string str;
int n,i,sum;
int main()
{
	cin>>str;
	n=str.length();
	for(int i=0;i<n/2;i++)
	{
		if(str[i]!=str[n-i-1])
			sum++;
	}
	if(sum==0&&n%2!=0||sum==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
 return 0;
}
