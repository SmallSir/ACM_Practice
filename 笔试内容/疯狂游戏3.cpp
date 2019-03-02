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
string str;
int tu[1005][1005];
int dp[1005][1005];
int MAX;
int main(int argc, char const *argv[])
{
    cin >> str;
    n = 1;
    m = 1;
    for(int i = 0;i < str.length();i++)
    {
        if(str[i] != ',')
            tu[n][m++] = str[i] -'0';
        else
        {
            n++;
            m = 1;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(tu[i][1] == 1)
        {
            MAX = 1;
            dp[i][1] = 1;
        }
    }
    for(int i = 1;i < m;i++)
    {
        if(tu[1][i] == 1)
        {
            MAX = 1;
            dp[1][i] = 1;
        }
    }
    for(int i = 2;i <= n;i++)
    {
        for(int j = 2;j < m;j++)
        {
            if(tu[i][j] == 1)
            {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            }
            MAX = max(dp[i][j],MAX);
        }
    }
    cout << MAX * MAX << endl;
    return 0;
}