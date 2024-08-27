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
    int i = 0;
    TreeNode* solve(vector<int>& a, int min, int max){
        if(i >= a.size() || a[i] <= min || a[i] >= max) return NULL;
        TreeNode *root = new TreeNode(a[i++]);
        root->left = solve(a, min, root->val);
        root->right = solve(a, root->val, max);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, INT_MIN, INT_MAX);
    }
};