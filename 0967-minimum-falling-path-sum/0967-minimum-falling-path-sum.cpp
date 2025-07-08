class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -101));
        function<int(int,int)> rec = [&](int i, int j) -> int {
            if(i >= n || j < 0 || j >= n) return INT_MAX;
            if(i == n-1) return mat[i][j]; 

            if(dp[i][j] != -101) return dp[i][j];

            int ans = INT_MAX;
            for(int curr= -1; curr <= 1; curr++){
                ans = min(ans, rec(i+1, j+curr));
            }
            return dp[i][j] = mat[i][j] + ans;
        };
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
            ans = min(ans, rec(0,i));
        return ans;
    }
};