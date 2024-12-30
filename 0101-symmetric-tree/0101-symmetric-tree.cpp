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
    bool isPalindrome(vector<int> v) {
        for (int i = 0, j = v.size() - 1; i < j; i++, j--)
            if (v[i] != v[j])
                return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (!front) {
                    temp.push_back(-101);
                } else {
                    temp.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                }
            }
            if (!isPalindrome(temp))
                return false;
        }
        return true;
    }
};