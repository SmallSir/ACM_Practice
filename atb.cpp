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
int a[15];
int t[15];
int b[15], c[15];
 
void check(int x) {
	int tot = 0;
	while(x > 0) {
		b[++tot] = x % 3;
		x = x / 3;
	}
}
 
int main()
{
	t[0] = 1;
	for(int i = 1; i <= 10; i++)
		t[i] = t[i - 1] * 3;
	while(cin>>n)
	{
		int cnt = 0;
		int tu = 0;
		for(int i = 0; i < n; i++)
			tu += t[i] * 2;
		for(int i = 1; i <= n; i++) {
			cin>>a[i];
		}
		for(int i = 0; i <= tu; i++) {
			check(i);
			for(int j = 1; j <= n; j++) {
				if(b[j] == 0) {
					c[j] = a[j] - 1;
				}
				else if(b[j] == 1) {
					c[j] = a[j];
				}
				else if(b[j] == 2) {
					c[j] = a[j] + 1;
				}
			}
			int res = 1;
			for(int j = 1; j <= n; j++)
				res = res * c[j];
			if((res & 1) == 0) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
