class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int,int)> lcs = [&](int i, int j) -> int {
            if(i >= n || j >= m) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            return dp[i][j] = (s[i] == t[j]) ? 1 + lcs(i+1, j+1) : max(lcs(i,j+1), lcs(i+1, j));
        };
        return lcs(0,0);
    }
};