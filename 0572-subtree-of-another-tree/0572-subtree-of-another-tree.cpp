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
    bool checkEquality(TreeNode *root, TreeNode *subRoot){
        if(!root && !subRoot) return true;
        if((root && !subRoot) || (!root && subRoot)) return false;
        if(root->val == subRoot->val)
            return checkEquality(root->left,subRoot->left) && checkEquality(root->right,subRoot->right);
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(checkEquality(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};