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
#include<stack>  
using namespace std;
typedef long long LL;

stack<char> sta;
int n,i,sum;
char str[1000005];
int main()
{
	cin>>str;
	sum=0;
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i]=='['||str[i]=='<'||str[i]=='{'||str[i]=='(')
		{
			sta.push(str[i]);
		}
		else
		{
			if(sta.size()==0)
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			if(str[i]==']')
			{
				if(sta.top()!='[')
					sum++;
				sta.pop();
			}
			else if(str[i]=='>')
			{
				if(sta.top()!='<')
					sum++;
				sta.pop();
			}
			else if(str[i]=='}')
			{
				if(sta.top()!='{')
					sum++;
				sta.pop();
			}
			else
			{
				if(sta.top()!='(')
					sum++;
				sta.pop();
			}
		}
	}
	if(sta.size()!=0)
		cout<<"Impossible"<<endl;
	else
		cout<<sum<<endl;
	return 0;
}
