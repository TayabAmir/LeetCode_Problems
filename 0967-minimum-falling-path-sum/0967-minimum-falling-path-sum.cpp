class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp = mat;
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                dp[i][j] = mat[i][j] + dp[i+1][j];
                if(j-1 >= 0) dp[i][j] = min(dp[i][j], mat[i][j] +dp[i+1][j-1]);
                if(j+1 < n) dp[i][j] = min(dp[i][j], mat[i][j] + dp[i+1][j+1]);
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};