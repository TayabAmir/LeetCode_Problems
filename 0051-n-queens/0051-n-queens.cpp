class Solution {
public:
    bool check(int row, int col, vector<int>& rows){
        for(int i = 0; i < row; i++)
            if(col == rows[i] || abs(col-rows[i]) == abs(i-row)) return 0;
        return 1;
    }
    void rec(int lvl, int n, vector<string>& chessBoard, vector<int>& rows, vector<vector<string>> &ans){
        if(lvl == n) {
            ans.push_back(chessBoard);
            return;
        }

        for(int i = 0; i < n; i++){
            if(check(lvl, i, rows)){
                rows[lvl] = i;
                chessBoard[lvl][i] = 'Q';
                rec(lvl+1, n, chessBoard, rows, ans);
                rows[lvl] = -1;
                chessBoard[lvl][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n, string(n, '.'));
        vector<int> rows(n, -1);
        vector<vector<string>> ans;
        rec(0, n, chessBoard, rows, ans);
        return ans;
    }
};