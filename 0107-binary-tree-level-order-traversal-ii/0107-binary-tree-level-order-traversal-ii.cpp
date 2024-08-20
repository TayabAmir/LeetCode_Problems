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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front) {
                v.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            } else {
                if(!q.empty()) q.push(NULL);
                res.push_back(v);
                v.clear();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};