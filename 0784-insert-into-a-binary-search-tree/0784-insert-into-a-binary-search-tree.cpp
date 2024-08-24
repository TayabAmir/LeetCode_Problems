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
    void insertHelper(TreeNode *&root, TreeNode *node_to_be_inserted){
        if(!root){
            root = node_to_be_inserted;
            return;
        }
        if(root->val > node_to_be_inserted->val){
            insertHelper(root->left, node_to_be_inserted);
        } else {
            insertHelper(root->right, node_to_be_inserted);
        }
    }
    // TreeNode* insertHelper(TreeNode* root, int data) {
    //     if (!root) {
    //         root = new TreeNode(data);
    //         return root;
    //     }
    //     if (root->val > data) {
    //         root->left = insertHelper(root->left, data);
    //     } else {
    //         root->right = insertHelper(root->right, data);
    //     }
    //     return root;
    // }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // root = insertHelper(root, val);
        insertHelper(root, new TreeNode(val));
        return root;
    }
};