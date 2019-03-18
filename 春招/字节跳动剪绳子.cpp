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

int n,m;
double a[100005],MAX;
bool check(double x)
{
    int sum = 0;
    for(int i = 1;i <= n;i++)
        sum += a[i] / x;
    if(sum < m)
        return false;
    else
        return true;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    MAX = 0;
    double l,r;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        MAX = max(a[i],MAX);
    }
    l = 0,r = MAX;
    while(l < r - 0.001)
    {
        double mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%0.2lf\n",r);
    return 0;
}