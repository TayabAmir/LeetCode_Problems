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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
        for(int i = 0; i < res.size(); ++i)
            if(i % 2 == 1) reverse(res[i].begin(),res[i].end());
        return res;
    }
};