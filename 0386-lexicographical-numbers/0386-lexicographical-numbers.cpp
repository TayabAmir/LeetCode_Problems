class Solution {
public:
    void dfs(int &n, int curr, vector<int> &out){
        if(curr > n) return;
        out.push_back(curr);
        for(int i = 0; i <= 9; i++){
            dfs(n, curr*10+i ,out);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
    	for(int i = 1; i <= 9; i++){
            dfs(n, i, ans);
        }
        return ans;
    }
};