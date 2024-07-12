class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            if(grid[i][0] == 0)
                for(int j = 0; j < n; j++)
                    grid[i][j] = grid[i][j] ^ 1;

        for(int i = 1; i < n; i++){
            int zeroCount = 0;
            for(int j = 0; j < m; j++)
                if(!grid[j][i]) zeroCount++;
            if(zeroCount > m - zeroCount)
                for(int j = 0; j < m; j++)
                    grid[j][i] = 1 ^ grid[j][i];
        }
        int score = 0;
        for(int i = 0; i < m; i++)
            for(int j = n - 1, n = 0; j >= 0; j--,n++)
                score += (pow(2,n) * grid[i][j]);
        return score;
    }
};