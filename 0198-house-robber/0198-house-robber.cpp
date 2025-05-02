class Solution {
public:
    int rec(vector<int> &dp, vector<int>& nums, int lvl, int n) {
        if (lvl >= n)
            return 0;
        if (dp[lvl] != -1)
            return dp[lvl];
        return dp[lvl] = max(rec(dp, nums, lvl + 1, n),
                             nums[lvl] + rec(dp, nums, lvl + 2, n));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rec(dp, nums, 0, n);
    }
};