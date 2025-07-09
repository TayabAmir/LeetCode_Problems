class Solution {
public:
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int dp[n][m][m];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> rec = [&](int i, int j, int k) -> int {
            if (i >= n || j < 0 || j >= m || k < 0 || k >= m)
                return -100;
            if (i == n - 1)
                return (j == k) ? a[i][j] : a[i][j] + a[i][k];
            if (dp[i][j][k] != -1)
                return dp[i][j][k];
            int ans = -100;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    ans = max(ans, rec(i + 1, j + x, k + y));
                }
            }
            return dp[i][j][k] = ((j == k) ? a[i][k] : a[i][j] + a[i][k]) + ans;
        };
        return rec(0, 0, m - 1);
    }
};