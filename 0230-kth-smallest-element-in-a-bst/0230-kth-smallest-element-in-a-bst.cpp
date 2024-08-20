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
    vector<int> arr;
    void preOrder(TreeNode* root){
        if(!root) return;
        arr.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        preOrder(root);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};