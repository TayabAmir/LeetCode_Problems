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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int maxi = INT_MIN;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front) {
                maxi = max(maxi,front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            } else {
                if(!q.empty()) q.push(NULL);
                res.push_back(maxi);
                maxi = INT_MIN;
            }
        }
        return res;
    }
};