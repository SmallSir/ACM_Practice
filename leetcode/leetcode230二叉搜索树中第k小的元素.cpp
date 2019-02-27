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

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    stack<int> st;
    void dfs(TreeNode *root)
    {
        if(root->left!=NULL)
            dfs(root->left);
        st.push(root->val);
        if(root->right!=null)
            dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        int n = st.size();
        n = n - k;
        while(n--)
            st.pop();
        return st.pop();
    }
};