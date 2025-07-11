class Solution {
public:
    int rec(int i, int j, int &n, int &m, string &s, string &t, vector<vector<int>> &dp){
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = rec(i+1, j, n, m, s, t, dp);
        if(s[i] == t[j]){
            ans += rec(i+1, j+1, n, m, s, t, dp);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(0,0,n,m,s,t,dp);
    }
};