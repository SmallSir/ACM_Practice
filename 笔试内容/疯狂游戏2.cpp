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

string LetterChanges(string str){
    int n = str.length();
    for(int i = 0;i < n;i++)
    {
        if(str[i] == 'z')
            str[i] = 'a';
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] + 1;
        }
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            str[i] = str[i] - 'a' + 'A';
    }
    return str;
}
int main(int argc, char const *argv[])
{
    string str;
    getline(cin,str);
    cout << LetterChanges(str);
    return 0;
}