class Solution {
public:
    int rec(vector<vector<int>> &dp, vector<int> &nums, int lvl, int n, int prevTaken){
        if(lvl == n) return 0;
        if(dp[lvl][prevTaken+1] != -1)
            return dp[lvl][prevTaken+1];
        int ans = rec(dp, nums, lvl+1, n, prevTaken);
        if(prevTaken == -1 || prevTaken != lvl - 1){
            ans = max(ans, nums[lvl]+rec(dp, nums, lvl+1, n, lvl));
        }
        return dp[lvl][prevTaken+1] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return rec(dp, nums, 0, n, -1);      
    }
};