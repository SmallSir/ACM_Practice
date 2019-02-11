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

int n,i;
LL x[55],y[55],c[55];
int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> x[i];
    for(int i = 0;i < n;i++)
        cin >> y[i];
    for(int i = 0;i < n;i++)
        c[i] = 1 << 30;
    for(int i = 0; i < n;i++)
    {
        int t[55],sum = 0;
        for(int j = 0; j < n;j++)
        {
            t[j] = abs(x[i] - x[j]) +  abs(y[i] - y[j]);
        }
        sort(t,t+n);
        for(int j = 0; j < n;j++)
        {
            sum += t[j];
            c[j] = c[j] > sum ? sum : c[j];
        }
    }
    for(int i = 0; i < n;i++)
    {
        if(i == n - 1)
            cout << c[i] << endl;
        else
            cout << c[i] << " ";
    }
    return 0;
}