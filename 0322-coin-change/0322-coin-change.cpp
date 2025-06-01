class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        function<int(int, int)> rec = [&](int lvl, int amount) -> int {
            if(lvl == n) return INT_MAX;
            if(amount == 0) return 0;

            if(dp[lvl][amount] != -1) return dp[lvl][amount];

            int skip = rec(lvl+1, amount);
            if(coins[lvl] <= amount){
                int res = rec(lvl, amount-coins[lvl]);
                if(res != INT_MAX){
                    skip = min(skip, 1+res);
                }
            }
            return dp[lvl][amount] = skip;
        };
        int res = rec(0, amount);
        return (res != INT_MAX) ? res : -1;
    }
};