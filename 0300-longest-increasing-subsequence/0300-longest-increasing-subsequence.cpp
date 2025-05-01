class Solution {
public:
    int rec(vector<int> &dp, vector<int> &nums, int lvl){
        if(lvl == nums.size()){
            return 0;
        }
        if(dp[lvl] != -1) return dp[lvl];
        int ans = 1;
        for(int i = 0; i < lvl; i++){
            if(nums[i] < nums[lvl]){
                ans = max(ans, 1+dp[i]);
            }
        }
        return dp[lvl] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, rec(dp,nums, i));
        }
        return maxi;
    }
};