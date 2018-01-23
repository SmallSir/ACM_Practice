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


struct PP
{
	int l, r;
}ADD[250];
int main(){
	//	freopen("numbers.in","r",stdin);
	//	freopen("numbers.out","w",stdout);
	char a[205];
	bool flag, f, ch;
	while(gets(a) != NULL)
	{
		memset(ADD, 0, sizeof(ADD));
		flag = 0;
		f = 0;
		ch = 1;
		int ll, rr;
		int str = strlen(a);
		//
		for(int i = 0; i < str; i++)
		{
			if(!flag) {
				if(!f){
					if(a[i] >= 'A' && a[i] <= 'Z') {
						f = 1;
						flag = 1;
						ll = i;
					}
					else if(a[i] >= 'a' && a[i] <= 'z'){
						f = 1;
					}
					else f = 0;
				}
				else {
					if(a[i] >= 'A' && a[i] <= 'Z'){
						ch = 0;
					}
				}
			}
		}
		//
	}
	return 0;
}

