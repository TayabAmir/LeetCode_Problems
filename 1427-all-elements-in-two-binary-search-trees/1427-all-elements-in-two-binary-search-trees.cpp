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
    void inOrder(TreeNode* root, vector<int> &v){
        if(!root) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        inOrder(root1, v1);
        vector<int> v2;
        inOrder(root2, v2);
        v1.insert(v1.end(),v2.begin(),v2.end());
        sort(v1.begin(),v1.end());
        return v1;
    }
};