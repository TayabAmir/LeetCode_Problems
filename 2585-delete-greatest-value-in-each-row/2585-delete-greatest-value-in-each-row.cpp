class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
         int sum=0;
        for(int i=0; i< grid.size();i++)
            sort(grid[i].begin(),grid[i].end());
        for(int i=0; i < grid[0].size();++i){
            int maximum=0;
            for(int j=0; j < grid.size(); ++j){
                maximum = max(maximum,grid[j][i]);
            }
            sum +=maximum;
        }
        return sum;
    }
};