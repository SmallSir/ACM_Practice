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

int n,dp[100005];
int main(int argc, char const *argv[])
{
    cin >> n;
    if(n >= 0 && n < 4)
    {
        cout << n << endl;
        return 0;
    }
    if(n < 0)
        n = -n;
    for(int i = 1;i <= 100000;i++)
        dp[i] = (1 << 20);
    dp[1] = 1,dp[2] = 2,dp[3] = 3;
    for(int i = 4;i <= n;i++)
        if(i % 2 == 0)
            dp[i] = min(dp[i -1] +1,dp[i/2] + 1);
        else
            dp[i] = min(dp[(i+1) / 2] + 2,dp[i-1] + 1);
    cout << dp[n] << endl;

    return 0;
}