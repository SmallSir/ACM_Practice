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

int i,n,cnt;
char str[20],str1[20],s[20];
int main()
{
	 cin>>str;
	 cin>>str1;
	 n=strlen(str);
	 s[cnt++]=str[0];
	 for(i=1;i<n;i++)
	 {
		if(str[i]<str1[0])
			s[cnt++]=str[i];
		else
			break;
	 }
		s[cnt++]=str1[0];
	cout<<s<<endl;
	 return 0;
}
