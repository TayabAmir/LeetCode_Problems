class Solution {
public:
    static bool comp(int a, int b){
        return to_string(a) < to_string(b);
    } 
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        for(int i = 1; i <= n; i++) ans[i-1] = i;
        sort(ans.begin(), ans.end(), comp);
        return ans;
    }
};