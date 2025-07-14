class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int,int)> rec = [&](int i, int j) -> int {
            if(i < 0) return j+1;
            if(j < 0) return i+1;
            if(dp[i][j] != -1) return dp[i][j];
            return dp[i][j] = (s[i] == t[j]) ? rec(i-1, j-1) : 1+min({rec(i-1, j), rec(i, j-1), rec(i-1, j-1)});
        };
        return rec(s.length()-1,t.length()-1);
    }
};