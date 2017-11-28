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
int T,year;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>str;
		year=(str[0]-'0')*1000+(str[1]-'0')*100+10*(str[2]-'0')+(str[3]-'0');
		
		if(str[5]-'0'==0&&str[6]-'0'==2&&str[8]-'0'==2&&str[9]-'0'==9)
		{
			cout<<year+28<<endl;
		}
		else
		{
			if(year%4==0&&year%100!=0&&(str[5]-'0')==0&&(str[6]-'0')<=2)
			{
				cout<<year+5<<endl;
			}
			else
				cout<<year+6<<endl;
		}
	}
	return 0;
}
