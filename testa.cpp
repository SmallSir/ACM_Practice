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

LL a[11] = {11 , 100 , 999 , 9998 , 99997 , 999996 , 9999995 , 99999994 , 999999993 , 9999999992 , 99999999991};
int main()
{
	LL n;
	while(cin>>n){
		int cnt = 0;
		for(int i = 0 ; i < 11 ; i++){
			if(n >= a[i]) cnt++;
		}
		cout<<n+cnt<<endl;
	}
    return 0;
}

