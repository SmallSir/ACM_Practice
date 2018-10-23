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

char str[15];
int n,MIN;
void dfs(string ss,int deep)
{
	int j;
	if(deep == n+1)
	{
		LL sum;
		sum=0;
		int k=ss.length();
		for(j=0;j<k;j++)
		{
			sum*=10;
			sum+=ss[j]-'0';
		}
		int cnt=0;
		//cout<<"ss: "<<ss<<" sum "<<sum<<"sqrt: "<<sqrt(sum)<<endl;
		int sq = sqrt(sum);
		if(sq*sq == sum)
		{
			//cout<<sq<<endl;
			for(j=0;j<k;j++)
			{
				if(ss[j]!='0')
					break;
				cnt++;
			}
			MIN=min(MIN,(cnt+n-k));
		}
		return;
	}
	dfs(ss+str[deep],deep+1);
	dfs(ss,deep+1);
}
int main()
{
	string s;
	cin>>str;
	n=strlen(str);
	MIN = n;
	s="";
	dfs(s,0);
	if(MIN == n)
		cout<<-1<<endl;
	else
		cout<<MIN<<endl;

 return 0;
}
