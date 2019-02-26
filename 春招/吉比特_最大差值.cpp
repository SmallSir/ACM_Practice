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

LL a[1000005];
LL MAX;
int n;
int main(int argc, char const *argv[])
{
    MAX = -1;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 2;i <=n ;i++)
        MAX = max(MAX,a[i] - a[i-1]);
    cout << MAX <<endl;
    return 0;
}