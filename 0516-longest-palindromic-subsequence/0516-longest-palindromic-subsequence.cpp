class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        function<int(int,int)> lcs= [&](int i, int j) -> int {
            if(i >= n || j >= n) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] == t[j]) return dp[i][j] = 1+lcs(i+1, j+1);
            return dp[i][j] = max(lcs(i, j+1), lcs(i+1, j));
        };

        return lcs(0, 0);
    }
};