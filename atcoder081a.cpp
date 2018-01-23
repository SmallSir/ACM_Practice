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
const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MaxN = 1e5;
const int MOD = 1e9 + 7;

int n;
char s1[60], s2[60];
LL d[60];

int main()
{
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		d[0] = 1;
		if(s1[1] == s1[2]) d[1] = 6;
		else d[1] = 3;
		for(int i = 2; i <= n; i++) {
			if(s1[i] == s1[i + 1]) {
				if(s1[i - 1] == s2[i - 1]) {
					d[i] = d[i - 1] * 2 % MOD;
				}
				else {
					d[i] = d[i - 1] * 3 % MOD;
				}
				d[i + 1] = d[i];
				i++;
			}
			else if(s1[i] == s2[i]) {
				if(s1[i - 1] == s2[i -1]) {
					d[i] = d[i - 1] * 2 % MOD;
				}
				else if(s1[i - 1] != s2[i - 1]) {
					d[i] = d[i - 1] % MOD;
				}
			}
			else d[i] = d[i - 1];
		}
		cout<<d[n]<<endl;
	return 0;
}

