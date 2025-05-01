class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return rec(0, n, dp);
    }   
    int rec(int lvl, int n, vector<int> &dp)
    {
        if(lvl == n) return 1;
        if(dp[lvl] != -1) return dp[lvl];

        int ans = 0;
        if(lvl + 1 <= n)
            ans += rec(lvl+1, n, dp);
        
        if(lvl + 2 <= n)
            ans += rec(lvl+2, n, dp);

        return dp[lvl] = ans;
    }
};