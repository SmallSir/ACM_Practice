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

//strattime:2017/10/9 22:16
//endtime:2017/10/9 22:38
int i,n,k,j;
string str[500005];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str[i];
	}
	for(i=n-1;i>=1;i--)
	{
		if(str[i]>str[i+1])
		{
			k=0;
			while(k<min(str[i].length(),str[i+1].length())&&str[i][k]<=str[i+1][k])
				k++;
			while(k<str[i].length())
			{
				str[i][k]='\n';
				k++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<str[i].length()&&str[i][j]!='\n';j++)
			cout<<str[i][j];
		cout<<endl;
	}
 return 0;
}
