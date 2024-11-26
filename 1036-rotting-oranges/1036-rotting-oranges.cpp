class Solution {
public:
    int bfs(queue<pair<int,int>> &q,vector<vector<int>>& grid){
        int arr[] = {0,-1,0,1,0};
        int min = 0;
        while(!q.empty()){
            int s = q.size();
            bool g = false;
            for(int i = 0; i < s; i++){
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + arr[i];
                    int nc = c + arr[i+1];

                    if(0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[0].size() && grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        g = true;
                    }
                }
            }
            if(g) min++;
        }
        return min;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int c = bfs(q,grid);
        for(auto v : grid)
            if(count(v.begin(), v.end(), 1) >= 1) return -1;
        return c;
    }
};