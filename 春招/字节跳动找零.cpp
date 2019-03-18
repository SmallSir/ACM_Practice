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
int sum;
int main(int argc, char const *argv[])
{
    cin >> n;
    n = 1024 - n;
    sum+= n / 64;
    n = n % 64;
    sum+= n / 16;
    n = n % 16;
    sum+= n / 4;
    n = n % 4;
    sum+=n;
    cout << sum << endl;
    return 0;
}