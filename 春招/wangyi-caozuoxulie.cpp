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

LL a[200005];
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    if(n % 2 == 0)
    {
        for(int i = n;i >=1;i-=2)
            cout << a[i] <<" ";
        for(int i = 1;i <= n - 1;i+=2)
        {
            if(i == n-1)
                cout << a[i] << endl;
            else
            {
                cout << a[i] << " ";
            }
            
        }
    }
    else
    {
        for(int i = n;i >=1;i-=2)
            cout << a[i] <<" ";
        for(int i = 2;i <= n - 1;i+=2)
        {
            if(i == n-1)
                cout << a[i]<<endl;
            else
            {
                cout << a[i] << " ";
            }
            
        }
    }
    
    return 0;
}