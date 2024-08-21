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
    bool checkSum(TreeNode *root, int sum, int targetSum){
        if(!root) return false;
        sum += root->val;
        if(!root->left && !root->right)
            if(sum == targetSum) return true;
        return checkSum(root->left,sum,targetSum) || checkSum(root->right,sum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return checkSum(root,0,targetSum);
    }
};