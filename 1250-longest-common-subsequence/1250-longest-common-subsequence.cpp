class Solution {
public:
    int rec(string &s,string &t, int i, int j, int &n, int &m, int dp[][1001]){
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = 1+rec(s, t, i+1, j+1, n, m, dp);
        return dp[i][j] = max(rec(s, t, i+1, j, n, m, dp), rec(s, t, i, j+1, n, m, dp));
    }
    int longestCommonSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return rec(s, t, 0, 0, n, m, dp);
    }
};