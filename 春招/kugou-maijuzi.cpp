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
    int sum = 5000;
    for(int i = 0;i <= 50;i++)
    {
        for(int j = 0;j <=50;j++)
        {
            if(i * 8 + j *6 > n)
                break;
            if(i * 8 + j * 6 == n)
                sum = min(sum, (i+j));
        }
    }
    if(sum == 5000)
        cout << -1 <<endl;
    else
    {
        cout << sum <<endl;
    }
    
}