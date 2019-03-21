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

class Solution {
public:
    bool check(vector<int> qua,int l,int r)
    {
        int i;
        if(l >= r)
            return true;
        for(i = 0; i <= r;i++)
        {
            if(qua[i] > qua[r+1])
                break;
        }
        for(int j = i;j <= r;j++)
        {
            if(qua[j] < qua[r+1])
                return false;
        }
        return check(qua,0,i-2) && check(qua,i-1,r-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0)
            return false;
        return check(sequence,0,sequence.size() - 2);
    }
    
};

int main(){
    Solution s;
    vector<int> a{4,8,6,12,16,14,10};
    cout << s.VerifySquenceOfBST(a) << endl;;
    
}