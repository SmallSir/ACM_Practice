class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0,start = 0;
        stack<int> st;
        for(int i = 0;i <s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                
                if(st.size() == 0) 
                {
                    start = i + 1;
                }
                else {
                    st.pop();
                    if(st.size() == 0)
                        res = max(res, i - start + 1);
                    else
                    {
                        
                        res = max(res,i - st.top());
                    }
                }
            }
        }
        return res;
    }
};