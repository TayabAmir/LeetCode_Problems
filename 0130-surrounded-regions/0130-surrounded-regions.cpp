class Solution {
public:
    void bfs(vector<vector<char>>& board, queue<pair<int,int>> q, int& rows, int& cols) {
        int r, c, nr, nc;
        int arr[] = {0, -1, 0, 1, 0};
        
        while (!q.empty()) {
            r = q.front().first, c = q.front().second;
            q.pop();
            board[r][c] = 'T';
            for (int i = 0; i < 4; i++) {
                nr = r + arr[i], nc = c + arr[i + 1];

                if (0 <= nr and nr < rows and 0 <= nc and nc < cols && board[nr][nc] == 'O') {
                        q.push({nr, nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < rows; i++){
            if (board[i][0] == 'O') q.push({i,0});
            if (board[i][cols - 1] == 'O') q.push({i,cols-1});
        }
        for (int i = 1; i < cols - 1; i++){
            if (board[0][i] == 'O') q.push({0,i});
            if (board[rows - 1][i] == 'O') q.push({rows-1,i});
        }

        bfs(board, q, rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};