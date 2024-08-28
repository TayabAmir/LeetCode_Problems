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
class NodeInfo {
public:
    int mini;
    int maxi;
    bool isBst;
    int sum;
    NodeInfo(int mini, int maxi, bool isBst, int sum) {
        this->mini = mini;
        this->maxi = maxi;
        this->isBst = isBst;
        this->sum = sum;
    }
};

class Solution {
public:
    NodeInfo solve(TreeNode* root, int& maxSum) {
        if(!root){
            return NodeInfo(INT_MAX, INT_MIN, true, 0);
        }
        NodeInfo left = solve(root->left, maxSum);
        NodeInfo right = solve(root->right, maxSum);

        NodeInfo curr(min(left.mini, root->val), max(right.maxi, root->val), false, root->val);

        if(left.isBst && right.isBst && (root->val > left.maxi && root->val < right.mini)){
            curr.isBst = true;
            curr.sum += left.sum + right.sum;
            maxSum = max(maxSum, curr.sum);
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root,maxSum);
        return maxSum;
    }
};