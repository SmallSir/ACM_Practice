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
int n,T;
int main()
{
	cin >> T;
	while(T --)
	{
		cin >> str;
		n = str.length();
		if(n <= 10)
			cout << str <<endl;
		else
		{
			cout <<str[0]<<n-2<<str[n-1]<<endl;
		}
	}
 return 0;
}
