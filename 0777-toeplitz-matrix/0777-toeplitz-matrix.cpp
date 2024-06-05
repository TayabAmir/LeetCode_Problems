class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        int num = matrix[i][0];
        int row = i;
        int col = 0;

        while (row < rows && col < cols) {
            if (matrix[row][col] != num) 
                return false;
            row++;
            col++;
        }
    }

    for (int j = 1; j < cols; j++) {
        int num = matrix[0][j];
        int row = 0;
        int col = j;

        while (row < rows && col < cols) {
            if (matrix[row][col] != num) 
                return false;
            row++;
            col++;
        }
    }

    return true;
}
};