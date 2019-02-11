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

LL x,f,d,p,a,day;
int main(int argc, char const *argv[])
{
    cin >> x >>f >> d >>p;
    day = d / x;
    if(f >= day)
    {
        cout << day <<endl;
    }
    else
    {
        d -= f * x;
        a = d / (x + p);
        cout << f + a <<endl;
    }
    
return 0;
}