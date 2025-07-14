class Solution {
public:
    
    bool isMatch(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<bool(int,int)> rec = [&](int i , int j) -> bool {
            if(j == -1) return i < 0;
            if(i == -1) {
                while(j >= 0){
                    if(t[j] != '*') return false;
                    j--;
                }
                return true;
            }
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] == t[j] || t[j] == '?')
                return dp[i][j] = rec(i-1, j-1);
            else if(t[j] != '*') return dp[i][j] = false;
            return dp[i][j] = rec(i-1, j) || rec(i, j-1);
        };
        return rec(n-1, m-1);
    }
};