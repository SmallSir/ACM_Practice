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

map<LL,int> b;
int n,sum;
LL a[505];
int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(b[a[i]] == 0)
        {
            b[a[i]] = 1;
        }
        else
        {
            b[a[i]] = b[a[i]] + 1;
        }
    }
    sort(a,a+n);
    int flag = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] == a[i+1])
            continue;
        for(int j = i + 1;j < n;j++)
        {
            if(a[j] == a[j+1])
                continue;
            for(int k = j + 1;k < n;k++)
            {
                if(a[k] == a[k+1])
                    continue;
                if(b[a[i] * a[j] * a[k]]!= 0)
                {
                    sum += b[a[i] * a[j] * a[k]];
                }
                if(a[i] * a[j] * a[k] >a[n-1])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            break;
    }
    cout<<sum<<endl;
    
    return 0;
}