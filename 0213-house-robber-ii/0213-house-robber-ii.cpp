class Solution {
public:
    int recF(vector<int> &dp, vector<int>& nums, int lvl, int n) {
        if (lvl >= n - 1)
            return 0;
        if (dp[lvl] != -1)
            return dp[lvl];
        return dp[lvl] = max(recF(dp, nums, lvl + 1, n),
                             nums[lvl] + recF(dp, nums, lvl + 2, n));
    }
    int recB(vector<int> &dp, vector<int>& nums, int lvl) {
        if (lvl < 1)
            return 0;
        if (dp[lvl] != -1)
            return dp[lvl];
        return dp[lvl] = max(recB(dp, nums, lvl - 1),
                             nums[lvl] + recB(dp, nums, lvl - 2));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dpA(n, -1);
        vector<int> dpB(n, -1);
        return max(recF(dpA, nums, 0, n), recB(dpB, nums, n-1));
    }
};