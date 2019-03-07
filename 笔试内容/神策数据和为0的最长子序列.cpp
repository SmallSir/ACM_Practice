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

int MAX = 0;
int n,l;
map<int,int> check;
int a[100005];
int dp[100005];
int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        l = check[dp[i]];
        if(check[dp[i]] == 0 && dp[i]!=0)
            check[dp[i]] = i;
        else
        {
            MAX = max(i-l,MAX);
        }
    }
    cout << MAX << endl;
    return 0;
}