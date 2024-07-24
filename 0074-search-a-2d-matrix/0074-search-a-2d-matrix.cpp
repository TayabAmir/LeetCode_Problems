class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i){
            if(target < matrix[i][n-1]){
                int low = 0, high = n-1;
                while(low <= high){
                    int mid = low + (high - low) / 2;
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] > target) high = mid - 1;
                    else low = mid + 1;
                }
                break;
            } else if(target == matrix[i][n-1]) return true;
        }
        return false;
    }
};