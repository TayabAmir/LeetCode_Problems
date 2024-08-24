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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root || !root->left) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        bool shouldSwap = false;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> v;
            for(int i = 0; i < size; ++i){
                TreeNode *front = q.front();
                q.pop();
                v.push_back(front);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(shouldSwap)
                for(int i = 0, j = v.size()-1; i < j; i++,j--)
                    swap(v[i]->val,v[j]->val);
            shouldSwap = !shouldSwap;
        }
        return root;
    }
};