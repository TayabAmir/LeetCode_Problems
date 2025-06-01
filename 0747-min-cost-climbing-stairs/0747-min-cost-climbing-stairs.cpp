class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        function<int(int)> rec = [&](int lvl) -> int{
            if(lvl >= n) return 0;
            if(dp[lvl] != -1) return dp[lvl];
            return dp[lvl] = cost[lvl]+min(rec(lvl+1), rec(lvl+2));
        };
        return min(rec(0), rec(1));
    }
};