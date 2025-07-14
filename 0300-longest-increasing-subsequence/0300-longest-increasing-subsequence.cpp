class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        for(int i = 0; i < n; i++){
            int maxi = 1;
            for(int j = 0; j < i; j++)
                if(nums[i] > nums[j])
                    maxi = max(maxi, 1+dp[j]);
            dp[i] = maxi;
        }
        return *max_element(dp.begin(), dp.end());
    }
};