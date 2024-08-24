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
    int ans = 0;
    pair<int, int> postOrder(TreeNode* root) {
        if (!root)
            return {0,0};
        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);
        int sum = root->val + left.first + right.first, n = 1 + left.second + right.second; 
        if (root->val == sum / n) {
            ans++;
        }
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        postOrder(root );
        return ans;
    }
};