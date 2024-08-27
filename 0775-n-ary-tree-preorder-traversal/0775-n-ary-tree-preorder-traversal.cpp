/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void preHelper(Node *root){
        ans.push_back(root->val);
        for(auto r : root->children)
            preHelper(r);
    }
    vector<int> preorder(Node* root) {
        preHelper(root);
        return ans;
    }
};