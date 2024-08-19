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
    int sumNumbers(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> q2;
        q.push(root);
        q.push(NULL);
        q2.push(root->val);
        int sum = 0;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front) {
                int val = q2.front();
                q2.pop();
                if (front->left) {
                    q.push(front->left);
                    q2.push((val * 10) + front->left->val);
                }
                if (front->right) {
                    q.push(front->right);
                    q2.push((val * 10) + front->right->val);
                }
                if (!front->left && !front->right) {
                    sum += val;
                }
            } else {
                if (!q.empty())
                    q.push(NULL);
            }
        }
        return sum;
    }
};