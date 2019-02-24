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
    vector<int> a;
    vector<vector<int>> b;
    map<int,int> check;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(check[nums[i]] == 0)
            {    
                check[nums[i]] = 1;
                a.push_back(nums[i]);
            }
            else
            {
                check[nums[i]]++;
            }
        }
        sort(a.begin(),a.end());
        for(int i = 0;i < a.size();i++){
            for(int j = i+1;j<a.size();j++)
            {
                int k = a[i] + a[j];
                if(-k == a[i] || -k == a[j])
                {
                    if(check[-k] >= 2)
                    {
                        b.push_back({a[i],a[j],-k});
                    }
                }
                else if(check[-k] != 0 && -k > a[j])
                {
                    b.push_back({a[i],a[j],-k});
                }
            }
        }
        if(check[0] >= 3)
            b.push_back({0,0,0});
        return b;
    }
};