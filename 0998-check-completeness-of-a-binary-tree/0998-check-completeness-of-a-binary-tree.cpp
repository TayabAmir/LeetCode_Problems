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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        bool isNull = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size; ++i){
                TreeNode *front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left){ 
                    if(isNull) return false;
                    q.push(front->left);
                }
                else {
                    isNull = true;
                }
                if(front->right){
                    if(isNull) return false;
                    q.push(front->right);
                } else {
                    isNull = true;
                }
            }
            res.push_back(v);
        }
        for(int level = 0; level < res.size() - 1; level++){
            if(res[level].size() != pow(2, level)) return false;
        }
        return true;
    }
};