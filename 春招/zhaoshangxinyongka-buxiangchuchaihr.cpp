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

LL a,b,c;
int main(int argc, char const *argv[])
{
    scanf("%d,%d,%d", &a, &b, &c);
    if(c ^ b ^ a == 0)
    {
        cout << 1 << endl;
    }
    else if( (a ^ b) < c)
    {
        cout << "C," << c - (a ^ b) <<endl;
    }
    else if((a ^ c) < b)
    {
        cout <<"B," << b - (a ^ c) <<endl;
    }
    else if((b ^ c) < a)
    {
        cout <<"A," << a - (b ^ c) <<endl; 
    }
}