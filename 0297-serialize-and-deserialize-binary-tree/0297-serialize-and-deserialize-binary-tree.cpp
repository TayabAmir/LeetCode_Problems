/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "n";
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        res += to_string(root->val);
        res += ',';
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode *front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                    res += to_string(front->left->val);
                } else res += "n";
                res += ",";
                if(front->right){
                    q.push(front->right);
                    res += to_string(front->right->val);
                } else res += "n";
                res += ",";
            }
        }   
        return res;
    }

    // Decodes your encoded val to tree.
    TreeNode* deserialize(string s) {
        if(s[0] == 'n') return NULL;
        queue<TreeNode*> q;
        stringstream ss(s);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();
            getline(ss, str, ',');
            if(str != "n"){
                front->left = new TreeNode(stoi(str));
                q.push(front->left);
            } else 
                front->left = NULL;
            getline(ss, str, ',');
            if(str != "n"){
                front->right = new TreeNode(stoi(str));
                q.push(front->right);
            } else front->right = NULL;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeTreeNode* ans = deser.deserialize(ser.serialize(root));