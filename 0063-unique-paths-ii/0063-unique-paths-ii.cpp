class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size(), n = o[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        set<pair<int,int>> st;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(o[i][j]) st.insert({i, j});

        function<int(int,int)> rec = [&](int i, int j) -> int{
            if(i >= m || j >= n || st.find({i,j}) != st.end()) return 0;
            if(i == m - 1 && j == n - 1) return 1;
            if(dp[i][j] != -1) return dp[i][j];
            return dp[i][j] = rec(i+1,j) + rec(i,j+1);
        };
        return rec(0,0);
    }
};