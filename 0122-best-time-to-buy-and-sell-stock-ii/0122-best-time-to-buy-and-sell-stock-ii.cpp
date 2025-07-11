class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        function<int(int, int)> rec = [&](int lvl, int buy) -> int {
            if(lvl == n) return 0;
            if(dp[lvl][buy] != -1) return dp[lvl][buy];
            int ans;
            if(buy){
                ans = max(rec(lvl+1, false) - a[lvl], rec(lvl+1, true));
            } else {
                ans = max(rec(lvl+1, true) + a[lvl], rec(lvl+1, false));
            }
            return dp[lvl][buy] = ans;
        };
        return rec(0, 1);
    }
};