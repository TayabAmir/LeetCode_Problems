class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'U'));
        for(vector<int> v : guards)
            grid[v[0]][v[1]] = 'G';
        for(vector<int> v : walls)
            grid[v[0]][v[1]] = 'W';

        set<pair<int,int>> st;
        int x,y;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 'G'){
                    x = i-1, y = j;
                    while(x >= 0 && grid[x][y] != 'W' && grid[x][y] != 'G'){
                        st.insert({x,y});
                        x--;
                    }
                    x = i+1, y = j;
                    while(x < m && grid[x][y] != 'W' && grid[x][y] != 'G'){
                        st.insert({x,y});
                        x++;
                    }
                    x = i, y = j - 1;
                    while(y >= 0 && grid[x][y] != 'W' && grid[x][y] != 'G'){
                        st.insert({x,y}); y--;
                    }
                    x = i, y = j+1;
                    while(y < n && grid[x][y] != 'W' && grid[x][y] != 'G'){
                        st.insert({x,y}); ++y;
                    }
                }
            }
        }
        return (m*n)-(st.size()+guards.size()+walls.size());
    }
};