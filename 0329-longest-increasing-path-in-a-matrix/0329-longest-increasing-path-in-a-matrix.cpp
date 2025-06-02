class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int, int, int)> dfs = [&](int i, int j, int prevEle) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] <= prevEle)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            int up = dfs(i - 1, j, mat[i][j]);
            int down = dfs(i + 1, j, mat[i][j]);
            int left = dfs(i, j - 1, mat[i][j]);
            int right = dfs(i, j + 1, mat[i][j]);
            return dp[i][j] = 1 + max({up, down, left, right});
        };
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ans = dfs(i, j, -1);
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
};