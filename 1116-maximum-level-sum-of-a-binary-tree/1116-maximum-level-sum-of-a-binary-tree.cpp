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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = 0, maxSum = INT_MIN, level = 0, maxLevel = -1;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front) {
                sum += front->val;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            } else {
                level++;
                if (!q.empty())
                    q.push(NULL);
                if (sum > maxSum) {
                    maxSum = sum, maxLevel = level;
                }
                sum = 0;
            }
        }
        return maxLevel;
    }
};