class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int,int)> rec = [&](int i, int j) -> int {
            if(j < i) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            int ans = INT_MIN;
            for(int k = i; k <= j; k++){
                int cost = ((i-1 >= 0) ? nums[i-1] : 1) * nums[k] * ((j+1 < n) ? nums[j+1] : 1);
                ans = max(ans, cost + rec(i, k-1) + rec(k+1, j));
            }
            return dp[i][j] = ans;
        };
        return rec(0, n-1);
    }
};