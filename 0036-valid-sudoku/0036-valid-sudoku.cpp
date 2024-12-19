class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board, int i, int j){
        vector<bool> is(9,false);
        for(int r = i; r < i+3; r++){
            for(int c = j; c < j+3; c++){
                if(board[r][c] == '.') continue;
                int x = board[r][c]-'1';
                // cout << x;
                if(is[x]) return false;
                is[x] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                if(!isValidSudoku(board, i, j)) return false;
            }
        }
        for(int i = 0; i < 9; i++){
            vector<bool> isRow(9,false);
            vector<bool> isCol(9,false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int x = board[i][j]-'1';
                    if(isRow[x]) return false;
                    isRow[x] = true;
                }
                if(board[j][i] != '.'){
                    int x = board[j][i]-'1';
                    if(isCol[x]) return false;
                    isCol[x] = true;
                }
            }
        }
        return true;
    }
};