class Solution {
public:
    int rec(vector<vector<int>> &dp, vector<int> &nums, int lvl, int prevIdx){
        if(lvl == nums.size()){
            return 0;
        }
        if(dp[lvl][prevIdx+1] != -1)
            return dp[lvl][prevIdx+1];

        int ans = rec(dp, nums, lvl+1, prevIdx);
        if(prevIdx == -1 || nums[lvl] > nums[prevIdx]){
            ans = max(ans,1+rec(dp, nums,lvl+1,lvl));
        }
        return dp[lvl][prevIdx+1] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return rec(dp,nums, 0, -1);
    }
};