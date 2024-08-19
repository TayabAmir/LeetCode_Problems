/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int diameter(TreeNode* root,int &d) {
        if (!root) return 0;   
        int lh = diameter(root->left,d);     
        int rh = diameter(root->right,d);
        d = max(lh+rh,d);
        return 1 + max(lh,rh);     
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = -1;
        diameter(root,d);
        return d;
    }
};