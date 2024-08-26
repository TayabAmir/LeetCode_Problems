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
    void preOrder(TreeNode *root, vector<int> &ans){
        if(!root) return;
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<int> ans;
        preOrder(root, ans);
        root->left = NULL;
        for(int i = 1; i < ans.size(); ++i){
            root->right = new TreeNode(ans[i]);
            root = root->right;
        }
    }
};