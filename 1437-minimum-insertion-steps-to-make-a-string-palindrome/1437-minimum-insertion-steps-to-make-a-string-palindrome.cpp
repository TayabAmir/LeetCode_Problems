class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> lcs = [&](int i, int j) -> int {
            if(i == n || j == -1) return 0;
            if(dp[i][j] != -1) return dp[i][j];

            if(s[i] == s[j])
                return dp[i][j] = 1 + lcs(i+1, j-1);
            else
                return dp[i][j] = max(lcs(i+1, j), lcs(i, j-1));
        };
        return n - lcs(0, n-1);
    }
};