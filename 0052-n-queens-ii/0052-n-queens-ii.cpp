class Solution {
public:
    bool check(int lvl, int col, vector<int>& rows){
        for(int i = 0; i < lvl; i++)
            if(rows[i] == col || abs(rows[i] - col) == abs(lvl - i)) return false;
        return true;
    }
    int rec(int lvl, int n, vector<int>& rows){
        if(lvl == n) return 1;

        int ans = 0;
        for(int col = 0; col < n; col++){
            if(check(lvl, col, rows)){
                rows[lvl] = col;
                ans += rec(lvl+1, n, rows);
                rows[lvl] = -1;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<int> rows(n, -1);
        return rec(0, n, rows);
    }
};