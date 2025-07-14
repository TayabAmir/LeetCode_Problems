class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int ans = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0)
                    ans = max(ans, 1 + dp[j]);
            }
            dp[i] = ans;
        }
        int size = *max_element(dp.begin(), dp.end());
        vector<int> o;
        for(int i = n-1; i >= 0; i--){
            if(dp[i] == size && (o.empty() || o.back() % nums[i] == 0)){
                o.push_back(nums[i]);
                size--;
            }
        }

        return o;
    }
};