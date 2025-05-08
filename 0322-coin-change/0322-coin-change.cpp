class Solution {
public:
    int rec(int lvl, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(lvl == -1) return INT_MAX;
        
        if(dp[lvl][amount] != -1) return dp[lvl][amount];
        int ans = rec(lvl-1, amount, coins, dp); // Dont take 
        if(coins[lvl] <= amount) // Take
        {
            int res = rec(lvl, amount-coins[lvl], coins, dp);  
            if(res != INT_MAX)
                ans = min(ans, 1+res);
        }
        return dp[lvl][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res = rec(coins.size()-1, amount, coins, dp);
        return (res != INT_MAX) ? res : -1;
    }
};