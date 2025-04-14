class Solution {
public:
    bool rec(int lvl, vector<int>& nums, vector<int>& dp){
        if(lvl >= nums.size()) return false;
        if(lvl == nums.size() - 1) return true;

        if(dp[lvl] != -1) return dp[lvl];

        bool res = false;
        for(int i = 1; i <= nums[lvl]; ++i){
            if(rec(lvl+i, nums, dp)){
                res = true;
                break;
            }
        }
        return dp[lvl] = res;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(10001, -1);
        return rec(0, nums, dp);
    }
};