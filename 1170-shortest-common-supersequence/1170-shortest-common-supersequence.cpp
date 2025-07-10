class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i = n, j = m;
        string res = "";
        while(i >= 1 && j >= 1){
            if(s[i-1] == t[j-1]){
                res = s[i-1] + res;
                i--, j--;
            } else {
                if(dp[i-1][j] >= dp[i][j-1]){
                    res = s[i-1] + res;
                    i--;
                } else {
                    res = t[j-1] + res;
                    j--;
                }
            }
        }
        while(i >= 1) res = s[i-1] + res, i--;
        while(j >= 1) res = t[j-1] + res, j--;
        return res;
    }
};