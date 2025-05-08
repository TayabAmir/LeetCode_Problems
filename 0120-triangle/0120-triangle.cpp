class Solution {
public:
    int rec(int r, int c, int m, int n, vector<vector<int>>& tri, vector<int>& dp){
        if(r >= m || c >= n) return 0;
        
        if(dp[(r*(r+1)/2)+c] != -1) return dp[(r*(r+1)/2)+c];

        return dp[(r*(r+1)/2)+c] = tri[r][c] + min(rec(r+1, c, m, n+1, tri, dp), rec(r+1, c+1, m, n+1, tri, dp));
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        vector<int> dp(m*(m+1) / 2, -1);
        return rec(0,0,m,tri[0].size(), tri, dp);
    }
};