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

int T,n;
int a[100005],b[100005];
LL sum;
int main(int argc, char const *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
            b[i] = 1;
        }
        a[0] = a[n];
        a[n+1] = a[1];
        sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] > a[i-1])
            {
                
            }
        }
        for(int i = 1;i <= n;i++)
        {
            
        }
        for(int i = 1;i <= n;i++)
            sum+=b[i];
        cout << sum << endl;
    }
    return 0;
}