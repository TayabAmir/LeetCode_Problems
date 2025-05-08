class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        vector<int> dp(m*(m+1) / 2, -1);

        function<int(int,int)> rec = [&](int r, int c) -> int {
            if(r >= m || c > r) return 0;
        
            if(dp[(r*(r+1)/2)+c] != -1) return dp[(r*(r+1)/2)+c];

            return dp[(r*(r+1)/2)+c] = tri[r][c] + min(rec(r+1, c), rec(r+1, c+1));
        };
        return rec(0,0);
    }
};