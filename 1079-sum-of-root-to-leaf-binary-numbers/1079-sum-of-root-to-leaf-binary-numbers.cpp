/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> v;
    void preOrder(TreeNode* root, string s){
        if(!root) return;
        s += to_string(root->val);
        if(!root->left && !root->right) v.push_back(s);
        preOrder(root->left, s);
        preOrder(root->right, s);
    }
    int binaryToDecimal(string s, int i){
        if(s=="") return 0;
        return ((s[s.length()-1]-'0') * pow(2,i)) + binaryToDecimal(s.substr(0,s.length()-1), i+1);
    }
    int sumRootToLeaf(TreeNode* root) {
        preOrder(root, "");
        int sum = 0;
        for(auto s : v)
            sum += binaryToDecimal(s,0);
        return sum;
    }
};