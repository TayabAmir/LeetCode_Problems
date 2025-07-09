class Solution {
public:
    int count(int lvl, int rem, vector<int>& coins, int n, vector<vector<int>> &dp){
        if(rem == 0) return 1;
        if(lvl == n || rem < 0) return 0;
        if(dp[lvl][rem] != -1) return dp[lvl][rem];
        return dp[lvl][rem] = count(lvl, rem-coins[lvl], coins, n, dp) + count(lvl+1, rem, coins, n, dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return count(0, amount, coins, n, dp);
    }
};