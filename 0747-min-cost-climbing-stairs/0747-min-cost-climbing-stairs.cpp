class Solution {
public:
    int rec(int lvl, vector<int> &cost, vector<int> &dp){
        if(lvl >= cost.size()) return 0;
        if(dp[lvl] != -1) return dp[lvl];
        return dp[lvl] = cost[lvl] + min(rec(lvl+1, cost, dp), rec(lvl+2, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        int ans = rec(0, cost, dp);
        dp.resize(cost.size(), -1);
        return min(ans, rec(1, cost, dp));
    }
};