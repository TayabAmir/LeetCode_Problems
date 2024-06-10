class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arr;
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1, direction = 0;
        while(top <= bottom && left <= right){
            if(direction == 0){
                for(int cols = left;cols <= right; cols++)
                    arr.push_back(matrix[top][cols]);
                top++;
            }
            else if(direction == 1){
                for(int rows = top; rows <= bottom; rows++)
                    arr.push_back(matrix[rows][right]);
                right--;
            }
            else if(direction == 2){
                for(int cols = right; cols >= left; cols--)
                    arr.push_back(matrix[bottom][cols]);
                bottom--;
            }
            else{
                for(int rows = bottom; rows >= top; rows--)
                    arr.push_back(matrix[rows][left]);
                left++;
            }
            direction=(direction+1)%4;
        }
        return arr;
    }
};