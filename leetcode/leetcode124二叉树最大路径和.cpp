/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int MAX = INT_MIN;
        dfs(root,MAX);
        return MAX;
    }
    int dfs(TreeNode* root,int &MAX){
        if(root == NULL)
            return 0;
        int l = max(0,dfs(root->left,MAX));//左边
        int r = max(0,dfs(root->right,MAX));//右边
        MAX = max(MAX,l+r+root->val);//以当前节点为根
        return max(l,r) + root->val;
    }
};