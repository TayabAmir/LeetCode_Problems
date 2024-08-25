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
    TreeNode* getMinValueRoot(TreeNode *root) {
        TreeNode *temp = root;
        while (temp && temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            if(!root->left && root->right){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if(root->left && !root->right){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            int val = getMinValueRoot(root->right)->val;
            root->val = val;
            root->right = deleteNode(root->right, val);
            return root;
        } 
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        return root;
    }
};