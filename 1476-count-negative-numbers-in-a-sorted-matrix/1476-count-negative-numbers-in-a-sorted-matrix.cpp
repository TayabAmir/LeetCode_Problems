class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, n = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            int low = 0, high = n-1, neg = -1;
            while(low <= high){
                int mid = (high + low) / 2;
                if(grid[i][mid] < 0){
                    neg = mid;
                    high = mid - 1;
                } else if(grid[i][mid] >= 0){
                    low = mid + 1;
                }
            }
            if(neg != -1)
                count += (n - neg);
        }
        return count;
    }
};