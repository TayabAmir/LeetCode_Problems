/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<Node*> v(size);
            for(int i = 0; i < size; i++){
                Node* front = q.front(); q.pop();
                v[i] = front;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            for(int i = 0; i < size-1; i++){
                v[i]->next = v[i+1];
            }
            v[size-1]->next = NULL;
        }
        return root;
    }
};