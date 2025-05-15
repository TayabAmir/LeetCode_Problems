class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
        int x = g[0];
        vector<string> ans;
        ans.push_back(w[0]);

        for(int i = 1; i < w.size(); i++){
            if((g[i] ^ x) == 1){
                x = !x;
                ans.push_back(w[i]);
            }
        }
        return ans;
    }
};