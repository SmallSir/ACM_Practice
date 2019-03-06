/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void serializeCore(TreeNode* root, string &s){
        if(root == NULL){
            s += "# ";
            return;
        }
        
        s += to_string(root->val) + " ";
        serializeCore(root->left, s);
        serializeCore(root->right, s);
    }
    
    string serialize(TreeNode* root) {
        string s = "";
        serializeCore(root, s);
        s.pop_back();
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserializeCore(vector<string> &data, int &len, int &n) {
        TreeNode* node = NULL;
        if(data[n] == "#"){//说明这里是null
            return node;
        }
        else{
            node = new TreeNode(stoi(data[n]));
        }
        
        TreeNode* leftnode = NULL, * rightnode = NULL;
        n++;
        if(n <= len - 2){
            leftnode = deserializeCore(data, len, n);
            n++;
            rightnode = deserializeCore(data, len, n);
        }
        node->left = leftnode;
        node->right = rightnode;
        return node;
    }
    
    TreeNode* deserialize(string data) {
        if(data == "#" || data == "") return NULL;
        
        int len = 0;
        vector<string> list_s;
        string s = "";
        for(auto d: data){
            if(d == ' '){
                list_s.push_back(s);
                s = "";
                len++;
            }
            else s.push_back(d);
        }
        list_s.push_back(s);
        len++;
        int n = 0;
        TreeNode* root = deserializeCore(list_s, len, n);
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));