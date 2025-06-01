class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int &ele : nums) sum += ele;
        if(sum % 2 == 1) return false;
        int n = nums.size(), target = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1)); 

        function<bool(int, int)> rec = [&](int lvl, int target) -> bool {
            if(lvl == n || target < 0) return false;
            if(target == 0) return true;

            if(dp[lvl][target] != -1) return dp[lvl][target];

            if(rec(lvl+1, target) || rec(lvl + 1, target - nums[lvl]))
                return dp[lvl][target] = true;
            return dp[lvl][target] = false;
        };
        return rec(0, target);
    }
};