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

char str;
LL k,times;
map<char,LL> a;
int main()
{
	a['a']=4;
	a['b']=5;
	a['c']=6;
	a['f']=1;
	a['e']=2;
	a['d']=3;
	cin>>k>>str;
	if(k%4==0)
		times=(k/4-1)*16;
	else
		times=(k/4)*16;
	k=k%4;
	if(k==0)
		k=4;
	if(k%2==0)
		times+=1+6;
	times+=a[str];
	cout<<times<<endl;
	return 0;
}
