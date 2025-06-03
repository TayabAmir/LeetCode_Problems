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
    bool var = true;
    int nodes(TreeNode *root){
        if(!root) return 0;
        int left = nodes(root->left);
        int right = nodes(root->right);
        if(abs(left-right) > 1) var = false;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        nodes(root);
        return var;
    }
};