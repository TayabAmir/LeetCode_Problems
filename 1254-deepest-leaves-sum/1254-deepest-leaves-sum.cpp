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
    int deepestLeavesSum(TreeNode* root) {
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
        int sum = 0;
        for(int i = res[res.size()-1].size()-1; i >= 0; --i)
            sum += res[res.size()-1][i];
        return sum;
    }
};