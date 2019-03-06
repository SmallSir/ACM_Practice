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

void check(int n)
{
    for(int i = 1;i<=n;i++)
    {
        if(i % 3 == 0&&i % 5 == 0)
            cout << "FizzBuzz"<<endl;
        else if(i % 3 == 0)
            cout << "Fizz" << endl;
        else if(i % 5 == 0)
            cout << "Buzz" << endl;
        else
            cout << i << endl;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    check(n);
    return 0;
}