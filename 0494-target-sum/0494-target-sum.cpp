class Solution {
public:
    const int offset = 1500;
    int rec(int lvl, int rem, int n, vector<int> &a, vector<vector<int>> &dp){
        if(lvl == n) return rem == 0;
        int idx = (rem < 0) ? rem + offset : rem;
        if(dp[lvl][idx] != -1) return dp[lvl][idx];
        return dp[lvl][idx] = rec(lvl+1, rem-a[lvl], n, a, dp) + rec(lvl+1, rem+a[lvl], n, a, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(5000, -1));
        return rec(0, target, n, nums, dp);
    }
};