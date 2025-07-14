class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), ways(n, 1);
        for(int i = 0; i < n; i++){
            int ans = 1, m = -1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        ways[i] = ways[j];
                    } else if(dp[j]+1 == dp[i]){
                        ways[i] += ways[j];
                    }
                }
            }
        }
        int maxi = *max_element(dp.begin(), dp.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxi)
                res += ways[i];
        }
        return res;
    }
};