class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(21, vector<int>(5000, INT_MIN));

        function<int(int,int)> rec = [&](int lvl, int amount) -> int {
            if(lvl == n){
                if(amount == 0) return 1;
                return 0;
            }
            if(amount < 0){
                if(dp[lvl][amount+2500] != INT_MIN) return dp[lvl][amount+2500];
            } else {
                if(dp[lvl][amount] != INT_MIN) return dp[lvl][amount];
            }
            int p = rec(lvl+1, amount-nums[lvl]); 
            int n = rec(lvl+1, amount+nums[lvl]);
            if(amount < 0)
                dp[lvl][amount+2500] = p+n;
            else
                dp[lvl][amount] = p+n;
            return p+n;
        };
        return rec(0, target);
    }
};