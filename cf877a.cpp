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

string s[20]={"Danil","Olya","Slava","Ann","Nikita"};
string str;
int n,check,flag,k;
int main()
{
	flag=0;
	cin>>str;
	n=str.length();
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			check = 0;
			int m=s[j].length();
			for(k=0;k<m;k++)
			{
				if(s[j][k]!=str[i+k])
				{
					check = 1;
					break;
				}
			}
			if(check==0)
			{
				flag++;
			}
		}
	}
	if(flag!=1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
		
	return 0;
}
