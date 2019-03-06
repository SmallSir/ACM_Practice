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

int x,a[500005],sum,cnt,n;
int main(int argc, char const *argv[])
{
    n = 1;
    int flag = 0;
    //while(cin >> x)
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
        if(a[i] < 0)
            flag++;
    }
    sum = 0;
    cnt = 0;
    for(int i = 1; i <= n;i++)
    {
        if(cnt + a[i] < 0)
        {
            sum = max(sum,cnt);
            cnt = 0;
        }
        else
        {
            cnt += a[i];
            sum = max(sum,cnt);
        }
    }
    sum = max(sum,cnt);
    cout << flag << " " << sum;
    if(flag == n)
    {
        sum = a[1];
        for(int i = 1;i <= n;i++)
        {
            sum = max(sum,a[i]);
        }
    }
    cout << sum << endl;
    return 0;
}