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

int n;
string str;
int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	cin>>str;
	n=str.length();
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(str[i]=='Q'&&str[j]=='A'&&str[k]=='Q')
					sum++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
