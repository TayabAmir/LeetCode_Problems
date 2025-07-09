class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        function<int(int,int)> fn = [&](int lvl, int curr)->int{
            if(curr == 0) return 0;
            if(lvl == n || curr < 0) return INT_MAX;
            if(dp[lvl][curr] != -1) return dp[lvl][curr];
            int ans = fn(lvl+1, curr), temp = fn(lvl, curr-coins[lvl]);
            if(temp != INT_MAX) 
                ans = min(ans, 1+temp);
            return dp[lvl][curr] = ans;
        };
        int res =fn(0, amount);
        return  res == INT_MAX ? -1 : res ;
    }
};