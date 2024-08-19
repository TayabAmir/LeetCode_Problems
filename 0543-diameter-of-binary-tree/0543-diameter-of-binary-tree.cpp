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
class TreeInfo {
public:
    int height;
    int diameter;

    TreeInfo(int h, int d) {
        height = h;
        diameter = d;
    }
};
class Solution {
public:
    TreeInfo* diameter(TreeNode* root) {
        if (!root) {
            TreeInfo* i = new TreeInfo(0, 0);
            return i;
        }
        TreeInfo* left = diameter(root->left);
        TreeInfo* right = diameter(root->right);
        int height = max(left->height, right->height) + 1;
        int dia = max(left->height + right->height + 1,
                      max(left->diameter, right->diameter));

        TreeInfo* info = new TreeInfo(height, dia);
        return info;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root)->diameter-1;
    }
};