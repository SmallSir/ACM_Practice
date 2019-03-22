class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0,r = 0;
        map<char,bool> check;
        int ans = 0;
        for(r = 0;r < n;r++)
        {
            if(check[s[r]]== false)
            {
                check[s[r]] = true;
            }
            else
            {
                ans = max(ans,r-l);
                //cout << ans << " " << l << " "<< r <<endl;
                for(;;)
                {
                    if(s[l] == s[r])
                    {   
                        l++;
                        break;
                    }
                    check[s[l]] = false;
                    l++;
                }
            }
        }
        ans = max(r-l,ans);
        return ans;
    }
};