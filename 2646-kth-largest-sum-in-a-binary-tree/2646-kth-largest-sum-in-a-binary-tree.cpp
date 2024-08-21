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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<long long> sums;
        long long sum = 0;
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();
            if(front){
                sum += front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }else{
                if(!q.empty()) q.push(NULL);
                sums.push_back(sum);
                sum = 0;
            }
        }
        sort(sums.begin(),sums.end(),greater<long long>());
        return (k > sums.size()) ? -1 : sums[k-1];
    }
};