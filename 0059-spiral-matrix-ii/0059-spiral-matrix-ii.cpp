class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n));
        int left = 0, right = n-1, top = 0, bottom = n-1, direction = 0,value=1;
        while(top <= bottom && left <= right){
            if(direction == 0){
                for(int cols = left;cols <= right; cols++)
                    arr[top][cols] = value++;
                top++;
            }
            else if(direction == 1){
                for(int rows = top; rows <= bottom; rows++)
                    arr[rows][right] = value++;
                right--;
            }
            else if(direction == 2){
                for(int cols = right; cols >= left; cols--)
                    arr[bottom][cols]= value++;
                bottom--;
            }
            else{
                for(int rows = bottom; rows >= top; rows--)
                    arr[rows][left] = value++;
                left++;
            }
            direction=(direction+1)%4;
        }
        return arr;
    }
};