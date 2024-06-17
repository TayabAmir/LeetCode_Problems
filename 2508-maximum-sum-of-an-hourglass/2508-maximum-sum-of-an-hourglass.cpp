class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int sum = 0,maxHourglass = -1;
        for(int i=0; i<grid.size();i++){
            for(int j=1;j<grid[i].size();j++){
                grid[i][j] += grid[i][j-1];
            }
        }
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[i].size()-2;j++){
                sum = grid[i][j+2] + (grid[i+1][j+1] - grid[i+1][j]) + grid[i+2][j+2];
                if(j>0)
                    sum -= (grid[i][j-1] + grid[i+2][j-1]);
                maxHourglass = max(sum,maxHourglass);
            }
        }
        return maxHourglass;
    }
};