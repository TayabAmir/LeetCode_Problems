class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        for(int i = 0; i < n; i++){
            int ans = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    ans = max(ans, 1+dp[j]);
                }
            }
            dp[i] = ans;
        }

        return *max_element(dp.begin(), dp.end());
    }
};