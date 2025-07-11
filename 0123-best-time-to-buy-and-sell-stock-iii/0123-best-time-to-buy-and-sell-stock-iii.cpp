class Solution {
public:
    int n;
    int rec(int lvl, int buy, int k, vector<int>& a, vector<vector<vector<int>>> &dp) {
        if(lvl == n || k == 0) return 0;
        if(dp[lvl][buy][k] != -1) return dp[lvl][buy][k];
        int ans;
        if(buy){
            ans = max(rec(lvl+1, false, k, a, dp) - a[lvl], rec(lvl+1, true, k, a, dp));
        } else {
            ans = max(rec(lvl+1, true, k-1, a, dp) + a[lvl], rec(lvl+1, false, k, a, dp));
        }
        return dp[lvl][buy][k] = ans;
    }
    int maxProfit(vector<int>& a) {
        n = a.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return rec(0, 1, 2, a, dp);
    }
};