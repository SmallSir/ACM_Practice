#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef unsigned long long LL;
const int MM = 1e7;
const int Max = 2e5 + 5;

int main(){
	//	freopen("numbers.in","r",stdin);
	//		freopen("numbers.out","w",stdout);
	LL n, k;
	while(~scanf("%I64d%I64d", &n, &k))
	{
		int l = 0;
		if(n == 0 && k == 0) break;
		string s = " ", ss;
		bool flag = 0, f = 0;
		for(int i = 1; i <= 9; i++) {
			if(flag) break;
			LL ans = i * 1ll;
			while(ans <= n)
			{
				LL sum;
				LL pos = ans % k;
				LL a = k - pos;
				if(pos == 0) a = 0;
				if(a < (ans / i))
				{
					sum = ans + a;
					if(sum > n){
						ans *= 10;
						continue;
					}
				}
				else
				{
					ans *= 10;
					continue;
				}
				LL sum_ = sum;
				int len = -1;
				while(sum_ > 0)
				{
					len++;
					sum_ /= 10;
				}
				int len_ = len;
				if(f)
				{
					bool ff = 0;
					ss = " ";
					while(sum > 0)
					{
						int b = sum % 10;
						if(!ff){
							char a;
							a = 48 + b;
							ss[0] = a;
						}
						else 
						{
							char a;
							a = 48 + b;
							ss = a + ss;
						}
						ff = 1;
						sum /= 10;
					}
					if(ss < s){
						s = ss;
						l = len_;
					}
				}
				else
				{
					l = len;
					flag = 1;
					while(sum > 0)
					{
						int b = sum % 10;
						if(!f){
							char a;
							a = 48 + b;
							s[0] = a;
						}
						else 
						{
							char a;
							a = 48 + b;
							s = a + s;
						}
						f = 1;
						sum /= 10;
					}
				}
				ans *= 10;
			}
		}
		cout<< s << endl;
	}
	return 0;
}
