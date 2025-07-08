class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int,int)> rec = [&](int i, int j) -> int{
            if(i >= m || j >= n) return 0;
            if(i == m - 1 && j == n - 1) return 1;
            if(dp[i][j] != -1) return dp[i][j];
            return dp[i][j] = rec(i+1,j) + rec(i,j+1);
        };
        return rec(0,0);
    }
};