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
int main(int argc, char const *argv[])
{
    cin >> n;
    int k = n % 3;
    int x = n / 3;
    int sum;
    if(k == 0)
    {
        sum = 1;
        for(int i = 1;i <= x;i++)
            sum *= 3;
    }
    else if(k == 1)
    {
        sum = 4;
        for(int i = 1;i < x;i++)
            sum*=3;
    }
    else
    {
        sum = 2;
        for(int i = 1;i <= x;i++)
            sum*=3;
    }
    cout << sum << endl;
    return 0;
}