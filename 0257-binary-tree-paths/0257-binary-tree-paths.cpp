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
    vector<string> v;
    void trav(TreeNode *root, string s){
        if(!root) return;
        if(!root->left && !root->right){
            s = s + to_string(root->val);
            v.push_back(s);
            return;
        }
        s = s + to_string(root->val) + "->";
        trav(root->left, s);
        trav(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        trav(root, "");
        return v;
    }
};