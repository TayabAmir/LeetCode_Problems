class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 0;
        int arr[] = {0, 1, 0, -1, 0},r,c,nr,nc;

        while(!q.empty()){
            r = q.front().first, c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                nr = r + arr[i], nc = c + arr[i+1];
                if(0 <= nr && nr < grid.size() and 0 <= nc and nc < grid[0].size() and grid[nr][nc] == '1'){
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int out = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    out++;
                }
            }
        }
        return out;
    }
};