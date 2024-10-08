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
    bool postOrder(TreeNode *root){
        if(!root->left && !root->right) return root->val;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        if(root->val == 2)
            return left || right;
        return left && right;
    }
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        return postOrder(root);
    }
};