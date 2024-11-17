class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        int area = 1;
        grid[i][j] = 0;
        q.push({i,j});
        int arr[] = {0,1,0,-1,0};

        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + arr[i];
                int nc = c + arr[i+1];

                if(0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[0].size() && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc] = 0, area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area = max(area, bfs(grid, i, j));
                }
            }
        }
        return area;
    }
};