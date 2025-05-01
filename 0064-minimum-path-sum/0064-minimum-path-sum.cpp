class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0){
                    if(j == 0) dp[i][j] = grid[i][j];
                    else dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if(j == 0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(grid[i][j]+dp[i][j-1], grid[i][j]+dp[i-1][j]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};